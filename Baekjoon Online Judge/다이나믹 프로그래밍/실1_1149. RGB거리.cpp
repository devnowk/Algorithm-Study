#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 집의 수(2<=n<=1,000)
    int min=2147000000; // 출력 : 집을 칠하는 최소 비용
    std::cin >> n;
    std::vector<std::vector<int> > cost(n+1, std::vector<int>(3)); 
    // cost[i][0]의미 : i 번째 집을 빨간색으로 칠할 때의 누적 최소 비용
    // cost[i][1]의미 : i 번째 집을 초록색으로 칠할 때의 누적 최소 비용
    // cost[i][2]의미 : i 번째 집을 파란색으로 칠할 때의 누적 최소 비용
    
    for(int i=1; i<=n; i++) // 1번부터 n 번 집까지 최소 비용을 구해야 함
    {
        int r, g, b;
        std::cin >> r >> g >> b;
        cost[i][0]=std::min(cost[i-1][1], cost[i-1][2])+r; // 빨간색으로 칠한다면 이전 집은 초록 또는 파랑이어야 함
        cost[i][1]=std::min(cost[i-1][0], cost[i-1][2])+g; // 초록색으로 칠한다면 이전 집은 빨강 또는 파랑이어야 함
        cost[i][2]=std::min(cost[i-1][0], cost[i-1][1])+b; // 파란색으로 칠한다면 이전 집은 빨강 또는 초록이어야 함
    }
    
    for(int i=0; i<3; i++) if(cost[n][i]<min) min=cost[n][i]; // 마지막 집까지 구했던 누적 최소 비용 중 가장 작은 값을 찾음
    
    std::cout << min;
    
    return 0;
}