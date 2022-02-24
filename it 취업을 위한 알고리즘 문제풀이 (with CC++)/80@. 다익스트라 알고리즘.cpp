#include <stdio.h>
#include <vector>
#include <queue>

struct Node{ // 최소힙에 넣을 구조체
    int vex; // 목적지 정점
    int dis; // 누적 가중치
    Node(int a, int b) // 생성자
    {
        vex = a;
        dis = b;
    }
    bool operator<(const Node &b) const // 최소힙 정렬에 사용됨
    {
        return dis > b.dis; // 부호 반대면 최대힙이 됨
    }
};

int main() 
{
	// freopen("input.txt", "rt", stdin);
	
    // 다익스트라 알고리즘 : 인접한 노드 중 가중치의 누적이 최소인 노드를 방문하면서 최소 가중치를 구한다.
	std::priority_queue<Node> pQ;
	std::vector<std::pair<int, int> > graph[30]; // 가중치 방향 그래프의 인접 리스트
	int n, m; // 입력 : 정점의 수 n(1<=n<=20), 간선의 수 m
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
	{
	    int a, b, c;
	    scanf("%d %d %d", &a, &b, &c);
	    graph[a].push_back(std::make_pair(b, c));
	}
	// 인덱스 번호의 정점으로 가는 최소 가중치 변수, 처음에는 무한대로 초기화 시킨다.(무한대는 연결되지 않은 노드를 의미)
	std::vector<int> dist(n+1, 2147000000); // @@@ n+1크기의 벡터에 값을 2147000000으로 초기화한 채로 생성한다. @@@
	
	// pQ 자료구조 이용하여 BFS 알고리즘으로 인접 노드 탐색
	pQ.push(Node(1, 0));
	dist[1] = 0; // 1에서 1까지 가는 최소 거리는 0
	
	while(!pQ.empty())
	{
	    // 최소힙이므로 제일 적은 가중치의 노드가 pop됨
	    int now = pQ.top().vex;
	    int cost = pQ.top().dis; // 지금까지 누적된 가중치 값
	    pQ.pop();
	    
	    // if(cost > dist[now]) continue; // 중복된 노드가 pQ에 들어간 경우를 배제(없어도 됨)
	    for(int i=0; i<graph[now].size(); i++) // 연결된 노드의 개수만큼 반복(BFS)
	    {
	        int next = graph[now][i].first; // 연결된 정점 번호
	        int nextDis = graph[now][i].second; // 가중치 값
	        
	        // 정점을 두 번 거치게 되면 무조건 누적 가중치가 커지므로 if문 넘어감
	        if(cost+nextDis < dist[next]) // 여러 정점을 거쳐서 가는 게 더 작은 가중치라면 dist[next] 갱신
	        {     
	            dist[next] = cost+nextDis;
	            pQ.push(Node(next, dist[next])); // 최저 가중치를 가진 노드가 top으로 올라감
	            // 중복된 노드가 pQ에 들어가도 cost가 기존보다 크므로 계속 넣어도 괜찮음
	        }
	    }
	}
	
	for(int i=2; i<=n; i++)
	{
	    if(dist[i]!=2147000000) printf("%d : %d\n", i, dist[i]);
	    else printf("%d : impossible\n", i);
	}
	
	return 0;
}