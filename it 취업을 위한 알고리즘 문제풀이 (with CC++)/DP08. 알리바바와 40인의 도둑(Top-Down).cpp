#include <iostream>
#include <vector>
#include <algorithm>

int map[20][20]; // 입력 : 돌다리 건널 때 드는 에너지 정보
int dp[20][20]; // DP - dp[i][j] : (0,0)->(i,j) 최소 에너지 비용
int n; // 입력 : 계곡의 격자 크기 n*n(1<=n<=20)

int DFS(int x, int y)
{
    if(dp[x][y]>0) return dp[x][y]; // 탈출조건 : 이미 dp에 값이 있으면 탈출
    return dp[x][y]=std::min(DFS(x-1, y), DFS(x, y-1))+map[x][y]; // 왼쪽이나 위 중 작은 값
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) std::cin >> map[i][j];
    
    // 행이 0, 열이 0인 칸은 가지 수가 하나밖에 없으므로 미리 초기화
    dp[0][0]=map[0][0];
    for(int i=1; i<n; i++) dp[0][i]=dp[0][i-1]+map[0][i];
    for(int i=1; i<n; i++) dp[i][0]=dp[i-1][0]+map[i][0];
    
    std::cout << DFS(n-1, n-1); // (0,0)->(n-1, n-1)로 가는 최소 비용
    
    return 0;
}