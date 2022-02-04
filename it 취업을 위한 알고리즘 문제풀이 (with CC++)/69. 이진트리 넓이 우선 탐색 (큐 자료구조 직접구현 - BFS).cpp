#include <stdio.h>
#include <vector>

// BFS(레벨 탐색) : 다음 레벨의 정점을 모두 탐색 후 그 다음 레벨의 정점 탐색
// 큐 : front에 있는 걸 빼고 back에 넣는다
int Q[100], front = -1, back = -1; // front와 back 둘 다 -1에서 시작
int ch[10]; // 방문한 노드 체크
std::vector<int> map[10]; // 입력 : 무방향 그래프 - 인접 리스트

int main() {
    // freopen("input.txt", "rt", stdin);
    
    for(int i=1; i<=6; i++) // 간선 정보 6개
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a].push_back(b); // 무방향 그래프
        map[b].push_back(a); // @@@ a와 b 양쪽으로 모두 넣어줘야 함 @@@
    }
    
    Q[++back] = 1; // 1번 루트 노드를 넣음
    ch[1] = 1; // 1번 방문함
    while(front<back)
    {
        int x = Q[++front];
        printf("%d ", x);
        for(int i=0; i<map[x].size(); i++) // x와 연결된 노드를 찾음
        {
            if(ch[map[x][i]] == 0) // 방문하지 않은 노드여야 함
            {
                Q[++back] = map[x][i]; // x와 연결된 노드를 큐에 넣음
                ch[map[x][i]] = 1; // 방문한 노드로 체크
            }
        }
    }
	return 0;
}
