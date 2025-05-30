#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int n;
    int arr[5] = { 3, 4, 1, 5, 2 };

    scanf("%d", &n);

    p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", *(p + i));
    }
    for (int i = 0; i < n; i++) printf("%d ", *(p + i));
    printf("\n\n");

    // 이렇게 5개의 값이 들어간 정리되지 않은 배열이 있다고 할 때,
    // 오름차순(1, 2, 3 ... 99) 정렬을 하려면 어떻게 해야 하는지에 대해 알아보자

    // 어떻게 해야 할까요?
    // asc, dsc 인가? a가 오름차순 d가 내림차순 ㅇ니걸로 알고있음음

    // 그렇다면 가장 중요한 건 무엇인가
    // 바로 '대소비교'이다 이말이에요
    // 뭐가 큰지 모르는데 어떻게 배열 안에서 정렬을 해?
    // 정렬한다는 것은 배열 안에 있는 값을 임의의 위치로 이동시켜야하는 거잖아?
    // 그래서 대소비교가 중요하다.
    // 그렇다면 대소비교를 했어, 어떤 식으로 위치를 바꿀 겁니까(오름차순 기준으로 설명)
    // 내 현재 위치에 있는 값이, 바로 뒤에 값이랑 비교했을 때, 더 작아? 그러면 둘의 위치를 바꿉니다.
    // 그리고 ㅇㅇㅇ그렇습니다
    // 예제 보여드림

    for (int i = 0; i < 4; i++) { // 이걸 0~3으로 하는 이유는 이따 알려드림 이거 왜 0~3으로 하는 지 알았음
        for (int j = i + 1; j < 5; j++) { // 내리면 같이 내려가요 내려주지 마세요
            int tmp;
            if (arr[i] > arr[j]) { // 내가 다음 수보다 크면
                tmp = arr[i]; // 위치 교환(오름차순 정렬이라)
                arr[i] = arr[j];
                arr[j] = tmp; // 아 잠만요 반 찾아감
            }
        }
    }
    // 배열이 0번부터 시작하니까
    // 0~3번 까지 돌린다 이말은 어떻게 보면 배열 안에 있는 4개의 값을 조건문 돌린거랑 같이 때문에 마지막은 굳이 안해도 되는거임
    // 그니까 위에 1,2,3,4,5 일케 있는데 0~3번까지 돌린거는 1,2,3,4 이렇게 돌린거랑 똑같은 거 아님? 왜냐면 4번까지 돌리면 전체를 돌리는거랑 같으니까
    
    // ?!??!?!? ㅅㅓㄹㅁㅕㅇ ㄱㄱ
    // 안에 있는 j가 주요 개념임
    // 배열에 원소가, 그러니까 값이 5개 있으면
    // 다음 수랑 비교를 해야 하는데, 마지막 수(5)에 오면 배열의 범위를 넘어선 애랑 비교를 하게 됨
    // 그래서 배열에 들어있는 값의 개수 - 1만큼 원소를 비교해야함
    // 예시를 보여드림
    // 값 3개 들어있는 배열 (1, 2, 3)이 있다고 하면
    // 그쵸
    // 그래서 바깥 거는 들어있는 값 - 1
    // 안 쪽은 들어있는 값만큼 가는 거

    // 결국엔 마지막껄 비교하면 그냥 NULL이랑 비교한다는거랑 비슷한 개념? 그니까 마지막은 애초에 없는 애랑 비교를 하니까 오류가 나는거잖아 ㅇㅋ 이해완료
    // 어떻게 보면 그냥 비교를 게속하면서 배열을 바꿔주는 거지? 씨발 이 자살해야겠다
    // ㅇㅇ..ㄴㄴ....

    // 해서 출력해보면
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    // 근데 터미널 보임?
    // 일단 샐행 해바 보임
    // 음지를 운지로 봤네
    // 잘 나오죠?
    // 잠시만요 위에 조건문좀 다시 보고 오겟슴니다
    // ㅇㅋ
    return 0;
}