#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n, m; // 입력(n초 동안 측정, 경계값 m)
    int max=0; // 출력(경보음이 울린 최대 시간)
    int cnt=0; // 경보음이 연속으로 울린 시간
    //bool flag = false; // 경보음이 울린지 체크
    
    scanf("%d %d", &n, &m);
    for(size_t i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        
        if(tmp > m) // 경계값 초과
        {
           // flag = true;
            cnt++;
            if(cnt > max)
                max = cnt;
        }
        else
            cnt = 0; // 연속이 아니게됨
    }
    //if(!flag)
    if(max == 0) 
    // max는 cnt를 업뎃해주는 것이므로 0이면 한 번도 안 울린 것
    {
        printf("-1");
        return 0;
    }
    
    printf("%d", max);
	return 0;
}