#include <stdio.h>
#include <vector>

int n; // 입력 : 정점의 수 n(1<=n<=20)
int cnt=0; // 출력 : 1번 정점에서 n번 정점으로 가는 모든 경로의 가지 수
int check[21]; // 방문했던 노드 체크하는 배열
std::vector<int> map[21]; 
// @@@ 인접리스트는 간선의 수만큼만 공간을 차지하므로 인접행렬보다 공간복잡도가 훨씬 낫다 @@@

void DFS(int x)
{
    if(x == n) cnt++; // n번노드까지 왔으면 개수 증가
    else
    {
        for(int i=0; i<map[x].size(); i++) // 연결된 리스트의 개수만큼 반복
        {
            int next = map[x][i]; // 연결된 노드
            if(check[next] == 0) // 방문하지 않았으면
            {
                check[next] = 1;
                DFS(next); // map[x]에 들어있는 모든 노드들은 연결되어있으므로 바로 DFS 호출
                check[next] = 0; // 돌아오면 방문 해제
            }
        }
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int m; // 입력 : 간선의 수 m
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b); // a정점과 연결된 b정점 자체 값이 계속 쌓임
    }
    // map[1].size() 하면 1번 정점과 연결된 노드들의 개수를 알 수 있음
    
    check[1] = 1; // 1번 노드는 방문함
    DFS(1); // 1번 노드에서부터 시작
    
    printf("%d", cnt);
    
	return 0;
}