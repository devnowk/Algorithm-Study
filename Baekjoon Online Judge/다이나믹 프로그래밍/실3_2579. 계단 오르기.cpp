#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 계단의 개수(1<=n<=300)
    std::cin >> n;
    std::vector<int> dp(n+1); // dp[i] : i번째 계단까지 오는 데 최대 점수
    std::vector<int> stair(n+1); // 입력 : 계단을 오를 때의 점수
    
    for(int i=1; i<=n; i++) std::cin >> stair[i];
    dp[1]=stair[1];
    dp[2]=stair[1]+stair[2];
    for(int i=3; i<=n; i++) // 두번째 계단부터 체크
    {
        // 전 계단과 그 전 계단에서 오는 것 중 큰 값과 더하면서 누적
        dp[i]=std::max(dp[i-3]+stair[i-1]+stair[i], dp[i-2]+stair[i]);
        // dp[i-3]까지 더하는 이유는 dp[i-1]는 그 값이 연속이었을 때 최대가 될 수 있기 때문에 i에서 더하기 적합하지 않음
    }
    std::cout << dp[n];
    
    return 0;
}