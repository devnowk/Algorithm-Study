#include <stdio.h>
#include <vector>
#include <cmath>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    // X소수만 있는 배열 먼저 만듦
    // X2부터 n까지 소수 배열의 있는 값으로 나누면서 ++해감

    //2부터 n까지 소인수분해 하면서 나누어떨어지는 숫자 배열에 저장@@@
    //@@@n을 i로 나누면 i가 소수가 아닐 수 있다?@@@@@@@@@@@
    //@@@NO i가 2일 때 계속 나눠주면 4는 그냥 넘어가게됨@@@
    int n; // 입력(3<=n<=1000)
    scanf("%d", &n);
    std::vector<int> ch(n+1); // n이 7이면 7까지는 있어야 함
    
    for(int i=2; i<=n; i++) // 소인수분해를 할 i값들
    {
        int tmp=i;
        int j=2; // while문에서 나누기를 할 값
        while(tmp > 1) // 나눈 값이 1이 되면 소인수 분해 끝
        {
            if(tmp%j == 0) // 나누어지면 계속 나눔
            {    
                ch[j]++;
                tmp/=j;
            }
            else // 나누어 지지 않으면
                j++; // j값을 하나씩 증가(결국 ch에서 증가되는 값은 소수만 남음)
        }
    }
    printf("%d! = ", n);
    for(int i=2; i<=n; i++) 
    // 소수에는 모든 값이 다 들어있음(팩토리얼이므로)
    // 빈 값은 소수가 아닌 수들임
    {
        if(ch[i]!=0)
            printf("%d ", ch[i]);
    }
    
	return 0;
}