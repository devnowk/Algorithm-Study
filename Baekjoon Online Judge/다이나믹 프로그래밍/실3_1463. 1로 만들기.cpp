#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : n을 1로 만들어야 함(1<=n<=1,000,000) -> 거꾸로 1을 n으로 만들어도 됨
    std::cin >> n;
    std::vector<int> dp(n+1); // dp[i]의미 : 1을 i로 만드는 데 사용하는 최소 연산 횟수
    
    for(int i=2; i<=n; i++)
    {
        // 이전에 구했던 최소 연산횟수들은 변하지 않으므로 이 방법이 가능
        // dp[i]=min(dp[i/2], dp[i/3], dp[i-1])+1 이므로 셋 중에 최솟값을 찾아야 함
        int min=1000000;
        if(i%2==0 && dp[i/2]<min) min=dp[i/2];
        if(i%3==0 && dp[i/3]<min) min=dp[i/3];
        if(dp[i-1]<min) min=dp[i-1];
        dp[i]=min+1;
        //std::cout << dp[i] << "\n";
    }
    
    std::cout << dp[n];
    
    return 0;
}