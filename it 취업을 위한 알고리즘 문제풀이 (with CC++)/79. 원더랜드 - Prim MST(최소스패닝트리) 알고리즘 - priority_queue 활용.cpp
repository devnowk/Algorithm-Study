#include <stdio.h>
#include <algorithm>
#include <queue>

struct Node // 목표 정점과 가중치 값
{
    int n; // 목표 정점
    int val; // 가중치 값
    Node(int a, int b)
    {
        n = a;
        val = b;
    }
    bool operator<(const Node &b)const
    {
        return val>b.val; // b가 작으면 true (최소 힙)
    }
};

int ch[30]; // 노드를 방문했는지 체크하는 배열

int main() 
{
	
	// freopen("input.txt", "rt", stdin);
	
	// Prim : 임의의 시작 정점부터 정점을 하나씩 추가하며 트리를 확장해 나감
	
	int v, e; // 입력 : 도시의 개수 v(1<=v<=25), e(1<=e<=200)
	std::priority_queue<Node> pQ; // 가중치를 기준으로 최소힙을 만듦
	std::vector<std::pair<int, int> > map[30]; // 무방향 그래프 정보 입력
	scanf("%d %d", &v, &e);
	int res = 0; // 출력 : 모든 도시를 연결하면서 드는 최소비용
	
	for(int i=0; i<e; i++)
	{
	    int a, b, c;
	    scanf("%d %d %d", &a, &b, &c);
	    map[a].push_back(std::make_pair(b, c));
	    map[b].push_back(std::make_pair(a, c));
	}
	pQ.push(Node(1, 0)); // 임의의 정점 1을 가중치 0과 함께 pQ에 넣음
	while(!pQ.empty())
	{
	    Node tmp = pQ.top();
	    pQ.pop();
	    int v = tmp.n;
	    int cost = tmp.val;
	    if(ch[v] == 0) // 방문하지 않은 정점이면 비용에 추가함
	    {
	        ch[v] = 1;
	        res += cost;
	        for(int i=0; i<map[v].size(); i++) // 정점에 연결된 도시들 pQ에 추가함
	        {
	            pQ.push(Node(map[v][i].first, map[v][i].second));
	        }
	    }
	}
	printf("%d", res);
	
	return 0;
}