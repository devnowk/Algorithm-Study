#include <stdio.h>
#include <vector>

int n; // 입력 : 정점의 수 n(1<=n<=20)
int map[21][21]; // 인접행렬(가중치 방향 그래프)
int min = 2147000000; // 출력 : 1번 정점에서 n번 정점으로 가는 최소비용
int check[21]; // 방문한 노드 체크

void DFS(int v, int sum)
{
    if(v == n) // 마지막 노드까지 왔으면
    {
        if(sum < min) min = sum; // 최소비용이면 min갱신
    }
    else
    {
        for(int i=1; i<=n; i++) // 모든 노드 연결돼있는지 확인(인접행렬의 특징)
        {
            if(check[i] == 0 && map[v][i] != 0) // 방문한 적 없고, 연결이 되어있다면
            {
                check[i] = 1; // 방문체크
                DFS(i, sum+map[v][i]); // 가중치 더해서 재귀호출
                check[i] = 0; // 돌아오면 방문 해제
            }
        }
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int m; // 입력 : 간선의 수
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
    }
    check[1] = 1;
    DFS(1, 0); // 1번 노드에서부터 출발, 처음 가중치는 0부터 시작
    
    printf("%d", min);
    
	return 0;
}