#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n, m; // 문제의 개수 n(1<=n<=100), 제한 시간 m(10<=m<=1000)
    std::cin >> n >> m;
    
    /* dp[n+1][m+1]의 최대 메모리 개수는 약 40만Byte 이상, 시간도 오래 걸림 -> 비효율적(값이 커지면 시간 초과할 수도 있음)
    std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1)); // dp[i][j]의미 : i문제까지 j시간 안에 풀 수 있는 최대점수
    for(int i=1; i<=n; i++)
    {
        int score, time; // 문제를 풀었을 때 점수와 걸리는 시간
        std::cin >> score >> time;
        
        for(int j=time; j<=m; j++) // 문제 푸는 시간은 넘겨야 점수를 얻을 수 있음
        {
            // 한 문제만 풀 수 있으므로 i-1 행의 값을 가져와서 비교해야 함
            dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-time]+score);
            //std::cout << dp[i][j] << " ";
        }
        //std::cout << std::endl;
    }
    std::cout << dp[n][m];
    */
    // @@@ 뒤에서부터 거꾸로 구하면 dp[i-time]의 값을 참조해도 문제를 풀기 전이므로 두 개 이상 중복해서 푸는 일이 없음 @@@
    std::vector<int> dp(m+1); // dp[i]의미 : i초 일 때 풀 수 있는 최대 점수
    for(int i=1; i<=n; i++)
    {
        int score, time; // 문제를 풀었을 때 점수와 걸리는 시간
        std::cin >> score >> time;
        
        for(int j=m; j>=time; j--) // j를 m에서 time까지 거꾸로 계산
        {
            dp[j]=std::max(dp[j], dp[j-time]+score);
        }
    }    
    std::cout << dp[m];
    
    return 0;
}