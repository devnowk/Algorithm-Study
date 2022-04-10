#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    // 플로이드 워샬 알고리즘 : 모든 정점에서 다른 모든 정점으로 가는 최단 거리
    // 1을 거쳐서 가는 경우, 2를 거쳐서 가는 경우 ... n을 거쳐서 가는 경우로 나눠짐
    
    int n, m; // 입력 : 도시의 수 n(2<=n<=100), 도로의 수 m(1<=m<=200)
    std::cin >> n >> m;
    //std::vector<std::pair<int, int> > map[201]; // 인접리스트 필요 없음 -> 바로 dis에 비용만 넣으면 됨
    // 비용은 1~20 제한이라 21을 최대값으로 초기화 시킴
    std::vector<std::vector<int> > dis(n+1, std::vector<int>(n+1, 21)); // dis[i][j]의미 : i->j로 가는 최소 비용
    /* @@@ dis 초기 값 : 직행할 때의 비용 
           dis 첫 번째 갱신 값 : 1번 정점을 거칠 때의 최소 비용(거쳤던 값이 더 크면 원래 값 그대로->dis[i][j]=min(dis[i][j], dis[i][1]+dis[1][j])
           dis 두 번째 갱신 값 : 2번 정점을 거칠 때의 최소 비용(1번 정점을 거쳤던 내용은 변하지 않음)
           dis n 번째 갱신 값 : n번 정점을 거칠 때의 최소 비용(n-1번 정점까지 거쳤던 내용은 변하지 않음) -> 최종적으로 모든 정점을 거쳤을 때의 최소 비용
    */   
    
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        //map[a].push_back(std::make_pair(b, c));
        dis[a][b]=c; // dis(0) : 직행할 때의 비용으로 초기화
    }
    for(int i=1; i<=n; i++) dis[i][i]=0; // 자기 자신으로 가는 비용은 0으로 초기화

    for(int k=1; k<=n; k++) // 1번부터 n번까지 거쳐 가는 경우를 따짐
    {
        for(int i=1; i<=n; i++) // 1행~n행
        {
            for(int j=1; j<=n; j++) // 1열~n열
            {
                dis[i][j]=std::min(dis[i][j], dis[i][k]+dis[k][j]); // k를 거쳐서 가는 게 더 작은 비용이면 바꿔줌
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dis[i][j]>20) std::cout << "M ";
            else std::cout << dis[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}