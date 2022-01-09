#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(5<=n<=100,000)
    int max=0; // 출력(증가하는 수열의 최대 길이)
    int cnt=0; // 수열의 길이 측정
    int pre=0; // 증가를 판별하기 위해 이전 값 저장
    
    scanf("%d", &n);
    //scanf("%d", &num); // 맨 처음 값은 저장하고 시작
    // 위 대신에 for문에 0부터 시작해도 같은 효과를 볼 수 있음
    for(size_t i=0; i<n; i++)
    {
        int now;
        scanf("%d", &now);
        
        if(now < pre) // 값이 감소할 때
            cnt=1; // 처음 자신은 세줘야 함
        else // 값이 증가,동일할 때
        {
            cnt++;
            if(cnt > max)
                max = cnt;
        }
        pre = now; // 이전 값 업데이트
    }
    
    printf("%d", max);
    
	return 0;
}