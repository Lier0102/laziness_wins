#include "phantom.h"

struct stat st = {0};

bool adddir(Database *db, int8* path) {
        int32 fd, bpos;
        struct linux_dirent64 *p;
        signed int ret;
        int8 buf[102400];
        Entry e;

        ret = open($c path, O_RDONLY|O_DIRECTORY);
        if (ret < 1)
                return false;
        else
                fd = $4 ret;

        memset($c buf, 0, sizeof(buf));
        ret = syscall(SYS_getdents64, fd, buf, (sizeof(buf))); // rax 마냥 활용해버리기;;

        if (ret < 0) {
                close($i fd);
                return false;
        }

        for (bpos = 0; bpos < ret;) {
                p = (struct linux_dirent64 *)(buf + bpos); // 배열처럼 사용

                if (p->d_type & DT_REG) {
                        zero($1 &e, sizeof(Entry)); // 엔트리 초기화
                        e.type = file;
                        strncpy($c e.dir, $c path, 63); // 경로
                        strncpy($c e.file, p->d_name, 63); // 파일명

                        addtodb(db, e); // db(파일목록)에 추가
                } else if (p->d_type & DT_DIR) {
                        zero($1 &e, sizeof(Entry)); // 엔트리 초기화
                        e.type = dir;
                        strncpy($c e.dir, $c path, 63); // 경로
                        strncpy($c e.file, p->d_name, 63); // 파일명

                        addtodb(db, e); // db(파일목록)에 추가
                }


                bpos += p->d_reclen; // 파일 가져올 때, reclen을 참조하면서(offset) 다음 파일을 가져와 읽어야함.
        }

        close(fd);

        return true;
}



int main(int argc, char *argv[]) {
        Database *db;
        unsigned int opt = 0;

        printf("\t\t<---[ ! ] 아직 기능은 개발중입니다. version: 0.0--->\t\t\n\n");
        printf("[ . ] 간단한 백신 프로그램입니다.\n");
        printf("[ . ] 검사 옵션을 선택해주세요.\n");

        puts("-----------------------------------------------");
        puts("|                                             |");
        puts("|            1. 검사(v.0)                     |");
        puts("|            2. 종료                          |");
        puts("-----------------------------------------------");

        scanf("%d", &opt);

        char path[256] = {'\0'};

        if (opt == 1) {

                puts("[ > ] 경로를 입력해주세요");
                printf("[ >> ] ");
                scanf("%s", path);

                // assert(argc>1); // 인자 받기(실험용)
                assert($c path);
                puts(path);

                db = mkdatabase();

                adddir(db, $1 path);

                Database *db2;
                db2 = filter(db, &vaccine);

                // showdb(db);
                //

                puts("\t\t<---[ ! ] 비어있으면 아직 감지 못한겁니다....--->\n\n\r\n");
                puts("[ + ] 검사 결과(의심): \n\n");
                printf("-->\t"); showdb(db2); puts("\n\n\r\n");

                destroydb(db);
                destroydb(db2);
        } else {
                puts("[ ... ] 사후약방문.");
                exit(0);
        }

        return 0;
}