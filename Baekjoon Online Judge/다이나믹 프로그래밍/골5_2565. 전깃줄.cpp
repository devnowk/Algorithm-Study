#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b) // 벡터 정렬하는 함수
{
    return a.first<b.first; // first(a전봇대) 기준으로 오름차순 정렬
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 전깃줄의 개수(1<=n<=100)
    std::cin >> n;
    std::vector<std::pair<int, int> > arr; // 입력 : arr[i] : a전깃줄위치와 연결된 b전깃줄의 위치(1<=arr[i]<=500)
    std::vector<int> dp(n, 1); // arr 정렬 후에 LIS 구함, dp[i] : i번째가 부분 수열의 마지막일 때의 LIS
    for(int i=0; i<n; i++)
    {
        int a, b; // a 전봇대와 b전봇대의 연결되는 위치
        std::cin >> a >> b;
        arr.push_back(std::make_pair(a, b));
    }
    sort(arr.begin(), arr.end(), compare); // compare 조건대로 정렬
    for(int i=0; i<n; i++) // i번째 수가 부분 수열의 가장 끝 수라고 가정
    {
        //std::cout << arr[i].first << " " << arr[i].second << "\n";
        int max=1; // 이전 값들 중 가장 큰 dp값
        for(int j=0; j<i; j++)
        {
            if(arr[j].second<arr[i].second && dp[j]+1>max) max=dp[j]+1;
        }
        dp[i]=max;
    }
    int max=0; // 가장 많이 연결할 수 있는 선의 수
    for(int i=0; i<n; i++)
    {
        if(dp[i]>max) max=dp[i];
        //std::cout << dp[i] << " ";
    }
    std::cout << n-max; // 없애야 하는 전깃줄의 최소 개수
    
    return 0;
}