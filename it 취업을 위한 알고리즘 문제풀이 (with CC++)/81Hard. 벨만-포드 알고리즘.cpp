#include <stdio.h>
#include <vector>

struct Edge // 가중치 방향 그래프의 정보를 담을 구조체 정의
{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c)
    {
        v1 = a;
        v2 = b;
        val = c;
    }
};
 
int main() 
{
    // freopen("input.txt", "rt", stdin);
    
    // 벨만 포드 알고리즘 : 가중치가 음수일 때 사용, 다익스트라보다 느리므로 가중치가 양수라면 다익스트라로.
    // 모든 간선을 n-1번 확인하며, 각 노드로 가는 최솟값을 구한다. O(VE) v:노드 개수, e:간선 개수
    // n-1번이 넘어갈 때가 최소가 된다면 음의 사이클이 존재하는 것이다.
    
    int n, m; // 입력 : 도시의 수 n(1<=n<=100), 도로 수 m(1<=m<=200)
    std::vector<Edge> graph; // 입력 : 도시의 정보 담을 인접 리스트
    scanf("%d %d", &n, &m);
    std::vector<int> dist(n+1, 2147000000); // 출발 정점에서 인덱스 번호 정점까지 최소 누적 가중치 구할 배열
    int start, end; // 입력 : 출발지점, 목적지점
    
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph.push_back(Edge(a, b, c)); // 간선의 정보를 저장
    }
    scanf("%d %d", &start, &end);
    
    dist[start] = 0; // 출발점은 0으로 초기화
    for(int i=1; i<=n; i++) // 1번 만에 가는 경우부터 n-1번 만에 가는 경우까지 따짐(n번은 음의 사이클 존재 확인)
    { // 간선을 모두 n-1번 반복 확인하며 최솟값을 구함
        for(int j=0; j<graph.size(); j++) // 간선 모두를 확인함
        {
            int now = graph[j].v1;
            int next = graph[j].v2;
            int nCost = graph[j].val;
            if(dist[now]!=2147000000 && dist[now] + nCost < dist[next]) // 출발지가 무한대가 아니고, 기존 값보다 거쳐서 오는 값이 더 좋으면 갱신
            {
                if(i==n) // n번째에도 값이 갱신된다면 음의 사이클이 존재하는 것이므로 프로그램 종료
                {
                    printf("-1");
                    return 0;
                }
                dist[next] = dist[now] + nCost;
            }
        }
    }
    printf("%d", dist[end]); // 음의 사이클이 없을 때 최종 목적지의 최솟값 반환
    
	return 0;
}