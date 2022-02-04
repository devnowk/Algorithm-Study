#include <stdio.h>
#include <vector>
#include <queue>

std::vector<int> map[21]; // 방향그래프의 인접리스트
std::queue<int> Q;
int ch[21]; // 방문 정보
int dis[21]; // 출력 : 각 정점으로 가는 최소 간선수
    
int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 정점의 수(1<=n<=20)
    int m; // 입력 : 간선의 수
    //int front = -1, back = -1;
        
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b); // 방향 그래프
    }
    
    Q.push(1);
    ch[1] = 1; // 1번 방문
  
    while(!Q.empty()) // 끝까지 조사하면서 최소 간선수를 구함
    {
        int x = Q.front(); // 큐의 제일 앞의 수를 꺼내옴
        Q.pop(); // 정점 하나를 꺼냄
        
        for(int i=0;i<map[x].size(); i++) // 연결된 노드 체크
        {
            if(ch[map[x][i]] == 0) // 방문하지 않은 노드
            { // @@@ 방문한 노드는 이미 최솟값이 구해진 것임 @@@
                ch[map[x][i]] = 1; // 방문 체크
                dis[map[x][i]] = dis[x]+1; // 부모 노드에서 한 번 추가한 값 넣어줌
                Q.push(map[x][i]);
            }
        }
    }
    
    for(int i=2; i<=n; i++) printf("%d : %d\n", i, dis[i]);
    
	return 0;
}