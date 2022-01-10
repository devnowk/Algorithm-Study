#include <stdio.h>
int cnt[10]{}; // 1~9 각 개수, 전역변수로 선언 하면 자동 초기화됨
int main() {
    // freopen("input.txt", "rt", stdin);
    
	char arr[101]; // 입력 값(자연수);
	int maxId; // 출력 값(가장 많이 사용된 숫자 중 가장 큰 수)
	int max=0; // 가장 많이 사용된 개수

    scanf("%s", arr);
    for(size_t i=0; arr[i]!='\0'; i++)
    {
        int tmp = arr[i]-48; // 숫자로 변환한 값을 tmp에 임시 저장
        cnt[tmp]++; // 해당 숫자의 값을 증가시킴
    }
    
    for(size_t i=1; i<=9; i++) // 최댓값 확인
    {
        if(cnt[i] >= max)
        {
            max = cnt[i];
            maxId = i;
        }
        /*for문은 오름차순이므로 등호만 써주면 됨*
        else if(cnt[i] == max)
        {
            if(i > maxId)
                maxId = i;
        }
        *****************************************/
    }
    
    printf("%d", maxId);
    	
	return 0;
}