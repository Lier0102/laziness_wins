#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <fcntl.h>
#include "birchutils.h"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define Blocksize       50000

#define $i (int)
#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)

#define $c (char *)

typedef int8 Dir[64];
typedef int8 File[64];

enum e_filetype {
        file = 1,
        dir = 2,
        other = 3
};
typedef enum e_filetype Filetype;

struct s_entry {
        Filetype type;
        Dir dir;
        File file;
};
typedef struct s_entry Entry;

struct s_database {
        Entry *entries;
        int32 cap;
        int32 num;
};
typedef struct s_database Database;
typedef bool (*function)(Entry);

//#define linux_dirent dirent
struct linux_dirent64 {
        unsigned long long d_ino;
        long long d_off;
        unsigned short d_reclen;
        unsigned char d_type;
        char d_name[];
};

Database *mkdatabase(void);
Database *filter(Database *, function);
bool vaccine(Entry);
bool adddir(Database*, int8*);
void addtodb(Database*, Entry);
void destroydb(Database*);
void showdb(Database*);
int main(int, char**);

Database *mkdatabase() {
        Database *db;
        int32 size;
        Entry *p;

        size = sizeof(Database);
        db = (Database *)malloc($i size);
        assert(db);
        zero($1 db, size);

        db->num = 0;
        db->cap = Blocksize;
        size = Blocksize * sizeof(Entry);
        p = (Entry*)malloc($i size);
        assert(p);
        zero($1 p, size);
        db->entries = p;

        return db;
}

bool vaccine(Entry e) {
        int32 fd;
        signed int ret;
        int8 path[64];
        char buf[4]; // 파일 헤더

        if (e.type != file) {
                return false;
        }

        zero(path, 64);

        if (!strcmp($c e.dir, ".")) {
                snprintf($c path, 63, "./%s", $c e.file);
        } else {
                snprintf($c path, 63, "%s/%s", $c e.dir, $c e.file);
        }
        ret = open($c path, O_RDONLY);

        if (ret < 1)
                return false;
        else
                fd = $4 ret;

        zero($1 buf, 4);
        read($i fd, buf, 4);
        close($i fd);

        if (
                (buf[0] == 0x7f)
                && (buf[1] == 0x45)
                && (buf[2] == 0x4c)
                && (buf[3] == 0x46)
           )
                return true;
        else
                return false;


}

Database *filter(Database *db, function f) { // 파일 목록 중 의심되는 친구들만 데려오기
        int32 n;
        Database *res;
        Entry *p;
        bool element_;

        res = mkdatabase();
        for (n = 0; n < db->num; n++) {
                p = &db->entries[n];
                element_ = f(*p);

                if (element_)
                        addtodb(res, *p);
        }

        return res;
}

void showdb(Database *db) {
        int32 n;

        //printf("capacity:\t%d\ncurrent size:\t%d\n", db->cap, db->num);

        for (n = 0; n < db->num; n++)
                printf("\n\n%s/%s\n", db->entries[n].dir, db->entries[n].file);
}

void destroydb(Database *db) {
        db->cap = 0;
        db->num = 0;
        free(db->entries);
        free(db);

        return;
}

void addtodb(Database *db, Entry e) {
        int32 size, cap, idx;

        if (db->num == db->cap) {
                cap = db->cap + Blocksize;
                size = cap * sizeof(Entry);

                db->entries = realloc(db->entries, size);
                assert(db->entries);
                db->cap = cap;
        }

        idx = db->num;
        memcpy($c &db->entries[idx], $c &e, sizeof(Entry));
        db->num++;

        return;
}