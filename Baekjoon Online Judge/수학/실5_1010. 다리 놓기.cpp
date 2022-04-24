#include <iostream>

int dp[30][30]; // 이항계수 메모이제이션 배열
int DFS(int n, int r)
{
    if(dp[n][r]!=0) return dp[n][r];
    if(n==r) return 1;
    if(r==1) return n;
    return dp[n][r] = DFS(n-1, r-1)+DFS(n-1, r);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int t;
    std::cin >> t;
    for(int i=0; i<t; i++)
    {
        int n, m; // 입력 : 서쪽과 동쪽의 개수(0<n<=m<30)
        std::cin >> n >> m;
        // 최대한 다리를 지으려면 동쪽 개수 중 서쪽 개수를 선택한 후 서쪽 다리를 배치하면 됨(mCn 구하기)
        std::cout << DFS(m, n) << "\n";
    }
    
    return 0;
}