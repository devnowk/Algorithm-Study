#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    // 플로이드 워샬 알고리즘 : 모든 정점에서 다른 모든 정점으로 가는 최단 거리
    // 1을 거쳐서 가는 경우, 2를 거쳐서 가는 경우 ... n을 거쳐서 가는 경우로 나눠짐
    
    int n, m; // 입력 : 도시의 수 n(2<=n<=100), 도로의 수 m(1<=m<=200)
    std::vector<std::pair<int, int> > map[201]; // 인접리스트(map[1][x].first : 1에서 갈 수 있는 노드, .second : 가는 비용)
    std::vector<std::vector<int> > dis(n+1, std::vector<int>(n+1)); // dis[i][j]의미 : i->j로 가는 최소 비용
    /* @@@ dis 초기 값 : 직행할 때의 비용 
           dis 첫 번째 갱신 값 : 1번 정점을 거칠 때의 최소 비용(거쳤던 값이 더 크면 원래 값 그대로->dis[i][j]=min(dis[i][j], dis[i][1]+dis[1][j])
           dis 두 번째 갱신 값 : 2번 정점을 거칠 때의 최소 비용(1번 정점을 거쳤던 내용은 변하지 않음)
           dis n 번째 갱신 값 : n번 정점을 거칠 때의 최소 비용(n-1번 정점까지 거쳤던 내용은 변하지 않음) -> 최종적으로 모든 정점을 거쳤을 때의 최소 비용
    */   
    
    
    
    return 0;
}