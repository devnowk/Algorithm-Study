#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(3<=n<=100,000)
    int cnt=0; // 출력(3의 개수)
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int tmp = i;
        while(tmp > 0)
        {
            if(tmp%10 == 3)
                cnt++;
            tmp/=10;    
        }
    }
    printf("%d", cnt);
        
	return 0;
}