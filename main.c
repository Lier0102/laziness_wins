#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 이동현 숙제_ 내가 수정함;;
#ifdef _WIN32
    #include <windows.h>
#else 
    #include <unistd.h>
#endif

void waiting(int sec) {
    #ifdef _WIN32
        Sleep(sec * 1000);
    #else
        sleep(sec);
    #endif
}

void cleaning() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(void) {

    char pwd[11] = {'\0'}, select[10] = {'\0'};
	int check, check2;

    printf("관리자 페이지 입니다.\n 비밀번호를 입력하세요: ");
    
    while(1) {
        scanf("%s", pwd);
        check = strcmp(pwd, "hannamoon");
        cleaning();
        if(check == 0) {
            printf("로그인에 성공했습니다!\n");
                waiting(2);
                cleaning();
            break;

        } else {
            printf("비밀번호가 틀렸습니다. 다시 입력해주세요.\n 다시 입력하기: ");
        }
    }
	while(1) {
	
            printf("원하는 선택지가 있다면 그대로 따라 적으세요\n");
			printf("1. st a\n");
			printf("선택지 한 개 밖에 없지롱\n");
			printf("선택하기: ");

			// 전에 있던 버퍼 비우기
			
			while(getchar() != '\n');
			fgets(select, sizeof(select), stdin);
			printf("%s", select);

			if(!strcmp("st a\n", select)) {
				int num;
				cleaning();
				printf("별을 몇 개 찍고 싶으신가요?\n");
				printf("개수: ");
				scanf("%d", &num);

				for(int i = 1; i <= num; i++) {
					printf("*");
				}
			} else {
				printf("다시 입력해주세요.\n");
				waiting(2);
				cleaning();
			}
		}

    return 0;
}