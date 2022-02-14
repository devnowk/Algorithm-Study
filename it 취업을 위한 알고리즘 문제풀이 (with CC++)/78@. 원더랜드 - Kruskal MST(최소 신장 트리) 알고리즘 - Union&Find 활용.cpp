#include <stdio.h>
#include <vector>
#include <algorithm>

int unf[26];

struct Edge // 간선의 정보
{
    int v1; // 정점1
    int v2; // 정점2
    int val; // 가중치
    Edge(int a, int b, int c) // 구조체의 생성자
    {
        v1 = a;
        v2 = b;
        val = c;
    }
    bool operator<(Edge &b) // 연산자 오버로딩(정렬에 이용)
    {
        return val<b.val;
    }
};

int Find(int v) // v의 루트노드를 찾음
{
    if(v == unf[v]) // v가 루트 노드라면 v 반환
        return v;
    else // 루트노드를 찾으러 재귀 호출
    {
        return unf[v] = Find(unf[v]);
    }
}

void Union(int a, int b) // 같은 집합으로 합침
{
    a = Find(a); // 루트 노드를 찾음
    b = Find(b);
    if(a != b) // 두 정점의 루트 노드가 다르면 같게 합쳐줌
        unf[a] = b;
}

int main() 
{
    // freopen("input.txt", "rt", stdin);
    
    // 크루스칼 알고리즘 : 간선의 가중치를 오름차순으로 정렬하면서 MST(최소 스패닝 트리)를 만듦
    
    std::vector<Edge> Ed; // 간선의 정보 담김
    int v, e; // 입력 : 도시의 개수 v(1<=v<=25), 도로의 개수 e(1<=e<=200)
    scanf("%d %d", &v, &e);
    int res = 0; // 출력 : 모든 도시를 연결하면서 드는 최소비용
    
    for(int i=1; i<=v; i++) unf[i] = i; // 집합의 정보를 초기화(처음에는 각자 서로 다른 집합)
    
    for(int i=1; i<=e; i++)
    {
        int a, b, c; // 입력 : a번 도시와 b번 도시가 유지비용 c로 연결(1<=c<=1,000,000)
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a, b, c)); // Edge 구조체 생성자 호출하면 객체 생성됨
    }
    sort(Ed.begin(), Ed.end()); // 가중치 기준으로 오름차순 정렬됨
    for(int i=0; i<e; i++) // 간선 개수만큼 반복하면서 어떤 간선이 최소비용 신장 트리를 만족하는 지 결정함
    {
        int a = Find(Ed[i].v1);
        int b = Find(Ed[i].v2);
        if(a != b) // 아직 같은 집합이 아닐때
        {// @@@ 같은 루트를 가지면 선택하지 않는다(사이클을 만들지 않아야 하므로) @@@
            res += Ed[i].val; // 가중치를 더함
            //Union(a, b); // 집합을 합침
            unf[a] = b; // Union함수에서 중복되는 부분 있으므로 바로 처리해줌
        }
    }
    
    printf("%d", res);
    
	return 0;
}