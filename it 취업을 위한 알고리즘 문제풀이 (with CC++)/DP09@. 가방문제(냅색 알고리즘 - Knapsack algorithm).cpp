#include <iostream>
#include <vector>

int main() 
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 보석 종류의 개수
    int limit; // 입력 : 가방에 담을 수 있는 무게의 한계
    
    std::cin >> n >> limit;
    std::vector<std::pair<int, int> > arr; // 입력 : 보석의 무게와 가치정보
    std::vector<int> dp(limit); // @@@ 냅색 알고리즘 - dp[i]의미 : i그램일 때 담을 수 있는 보석의 최대 가치 @@@
    // i그램~ limit그램까지 각 보석이 가질 수 있는 최대 가치 정보를 업데이트 시킴
    
    for(int i=0; i<n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        arr.push_back(std::make_pair(a, b));
        //std::cout << arr[i].first << " " << arr[i].second << std::endl;
    }
    
    for(int i=0; i<n; i++) // 각 보석마다 최대 가치의 경우를 따져서 업데이트 시킴
    {
        for(int j=0; j<=limit; j++) // 0그램~limit그램까지 하나씩 확인
        {
            if(j<arr[i].first) continue; // j가 i보석의 무게보다 작으면 무시
            int dif = dp[j-arr[i].first]; // i보석의 무게를 빼고 남은 무게, dp에 기록한 최대 무게 값
            int value = arr[i].second; // i보석의 가치
            
            if(dif+value>dp[j]) dp[j]=dif+value; // 현재 무게를 뺀 가장 가치 있는 값과 현재 가치를 더한 값이 dp에 있는 기존 값보다 크면 갱신
            //std::cout << dif << " " << value << " " << dp[j] << std::endl;
        }
    }
    
    std::cout << dp[limit];
    
	return 0;
}