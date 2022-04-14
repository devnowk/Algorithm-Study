#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int m, n; // 입력 : m이상 n이하 자연수 중 소수 고르기(m<=n<=10,000)
    int sum=0; // 출력 : 소수들의 합 구하기
    int min=10000; // 출력 : 소수들 중 가장 작은 수 출력
    
    std::cin >> m >> n;
    
    for(int i=m; i<=n; i++) // m부터 n까지 소수 구하기
    {
        if(i==2 || i==3) // 2와 3은 따로 처리 후 밑에는 무시
        {
            sum+=i;
            if(i<min) min=i;
            continue;
        }
        int tmp=i;
        for(int j=2; j*j<=i; j++) // 소수 확인은 i의 제곱근까지만 하면 됨
        {
            if(tmp%j==0) break; // 나누어 떨어지면 소수가 아님
            if((j+1)*(j+1)>i) // j+1이 i보다 크면 반복문에서 빠져나가므로 그 전에 소수 처리를 함
            {
                sum+=i;
                if(i<min) min=i;
            }
        }
    }
    
    if(sum==0)
    {
        std::cout << -1;
        return 0;
    }
    std::cout << sum << "\n" << min;
    
    return 0;
}