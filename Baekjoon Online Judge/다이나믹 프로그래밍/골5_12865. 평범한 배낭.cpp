#include <iostream>
#include <vector>

std::vector<std::pair<int, int> > knapsack; // 입력 : 각 물건의 무게w(1<=w<=100,000)와 가치v(0<=v<=1,000)
int n; // 입력 : 물품의 수(1<=n<=100)
int k; // 입력 : 최대 무게(1<=k<=100,000)
int dp[101][100001]; // dp[i][j] : j무게까지 제한했을 때, i번째 물건까지의 최대 가치

int DFS(int idx, int w) // 1~idx번째 물건까지 w만큼 담을 때 최대 가치
{
    if(idx==1) return dp[idx][w]; // 1은 초기화 해뒀음
    if(dp[idx][w]>0) return dp[idx][w]; // 이미 존재하면 바로 반환
    // Top-Down
    int idxWeight = knapsack[idx-1].first; // 현재 검사하려는 물건의 무게
    int idxValue = knapsack[idx-1].second; // 현재 검사하려는 물건의 가치
    
    // 현재 물건을 넣지 않을 때의 최대 가치는 DFS(idx-1, w) (이전 물건의 같은 무게일 때와 같음)
    // 현재 물건을 넣을 때의 최대 가치는 DFS(idx-1, w-현재물건 무게)+현재믈건 가치
    // 둘 중에 큰 값이 현재 물건을 넣을지 뺄지를 결정하는 요인이 됨
    if(w-idxWeight<0) return dp[idx][w]=DFS(idx-1, w); // 최대 무게보다 물건 무게가 무거우면 자동으로 뺌
    else return dp[idx][w] = std::max(DFS(idx-1, w), DFS(idx-1, w-idxWeight)+idxValue);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        int w, v;
        std::cin >> w >> v;
        knapsack.push_back(std::make_pair(w, v));
    }
    for(int i=knapsack[0].first; i<=k; i++) dp[1][i]=knapsack[0].second; // 1행-0번째 물건 가치로 초기화
    
    std::cout << DFS(n, k); // 1~n번째 물건을 k무게만큼 담을 때의 최대 가치 구하기
    
    return 0;
}