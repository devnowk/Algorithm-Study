#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 동전 종류 개수(1<=n<=12)
    int coin[12]; // 입력 : 동전 종류(오름차순으로 입력)
    int m; // 입력 : 거슬러 줄 금액(1<=m<=500)
    std::cin >> n;
    for(int i=0; i<n; i++) std::cin >> coin[i];
    std::cin >> m;
    
    // dp[i]의미 : i원을 거슬러 줄 때 동전의 '최소'개수
    std::vector<int> dp(m+1); // 최대 숫자로 맞춰놔야 최소값을 구할 수 있음
    for(int i=0; i<=m; i++) dp[i]=i/coin[0]; // 동전 최대 숫자로 초기화 (coin[0]이 제일 작은 수이므로 가능)
    
    for(int i=0; i<n; i++) // 동전의 개수만큼 반복
    {
        for(int j=coin[i]; j<=m; j++) // 0원~m원까지 각 동전의 최소 개수를 구함
        {
            dp[j]=std::min(dp[j-coin[i]]+1, dp[j]); // 기존 값과 coin[i]값을 제외한 나머지의 최소 동전+1 중 작은 값으로 업데이트
            //std::cout << dp[j] << " ";
        }
        //std::cout << std::endl;
    }
    
    std::cout << dp[m];
    
	return 0;
}