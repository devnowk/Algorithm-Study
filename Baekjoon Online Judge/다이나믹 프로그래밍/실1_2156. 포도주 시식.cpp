#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 포도주 잔의 개수(1<=n<=10,000)
    std::cin >> n;
    std::vector<int> wine(n+1); // 포도주의 양(0<=wine[i]<=1,000)
    std::vector<int> dp(n+1); // dp[i] : i 번째 포도주까지 가장 많은 누적 양
    
    for(int i=1; i<=n; i++) std::cin >> wine[i];
    dp[1]=wine[1];
    dp[2]=wine[1]+wine[2];
    dp[3]=std::max(wine[1], wine[2])+wine[3];
    for(int i=4; i<=n; i++)
    {
        int max=0; // 최댓값 구하기
        int zero = wine[i]+wine[i-1]+std::max(dp[i-3], dp[i-4]); // 바로 전 와인을 마실 경우
        int one = wine[i]+dp[i-2]; // 하나 빼고 와인을 마실 경우
        int two = wine[i]+dp[i-3]; // 두개 빼고 와인을 마실 경우
        if(zero>max) max=zero;
        if(one>max) max=one;
        if(two>max) max=two;
        dp[i]=max;
    }
    
    std::cout << std::max(dp[n-1], dp[n]);
    
    return 0;
}