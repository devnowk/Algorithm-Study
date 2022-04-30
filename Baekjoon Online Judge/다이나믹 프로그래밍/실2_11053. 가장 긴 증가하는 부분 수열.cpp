#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 수열 a의 크기(1<=n<=1,000)
    int max=0; // 출력 : 가장 긴 증가하는 부분 수열의 길이
    std::cin >> n;
    std::vector<int> a(n); // 입력 : 수열 a(1<=a[i]>=1,000)
    std::vector<int> dp(n, 1); // dp[i] : i번째 수가 수열의 마지막 수일 때 최대 LIS길이
    for(int i=0; i<n; i++) std::cin >> a[i];
    
    for(int i=1; i<n; i++) // i가 수열의 마지막 수라고 가정
    {
        for(int j=0; j<i; j++) // j를 0부터 i-1까지 돌리면서 i보다 작은 수이면 j와 i는 부분 수열이 됨
        {
            if(a[j]<a[i]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1; // j가 갖고 있는 수열의 수+1
        }
    }
    for(int i=0; i<n; i++) if(dp[i]>max) max=dp[i];
    std::cout << max;
    
    return 0;
}