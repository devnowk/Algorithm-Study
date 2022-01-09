#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    // 공개된 숫자가 더 큰 사람이 승자
    // 승자 +3, 패자 +0, 비김 +1
    // 총 10라운드
    // 총 승점 동일하면 마지막 승자가 총 승자 (기억)
    // 모든 게임이 비기면 총 승자 없음
    
    int a[10], b[10]; // 입력(a와 b의 숫자)
    int aWin=0, bWin=0; // 출력(a와 b의 승점)
    char last = ' '; // 마지막으로 이긴 사람(없으면 비김)
    
    for(size_t i=0; i<10; i++)
        scanf("%d", &a[i]);
    for(size_t i=0; i<10; i++)
        scanf("%d", &b[i]);
        
    // 게임 승점 계산
    for(size_t i=0; i<10; i++)
    {
        if(a[i] > b[i]) // a가 이겼을 때
        {
            aWin += 3;
            last = 'A';
        }else if(a[i] == b[i]) // 비겼을 때
        {
            aWin++;
            bWin++;
        }else // b가 이겼을 때
        {
            bWin += 3;
            last = 'B';
        }
    }
    printf("%d %d\n", aWin, bWin);
    
    // 누가 이겼는지 판별
    if(aWin > bWin)
        printf("A");
    else if(bWin > aWin)
        printf("B");
    else // 점수가 같을 경우
    {
        if(last == ' ') // 최종 승자가 없음
            printf("D");
        else
            printf("%c", last);
    }
    
	return 0;
}