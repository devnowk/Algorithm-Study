#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int map[21][21]; // 입력 : 방향 그래프의 인접행렬
int check[21]; // 방문한 노드는 다시 방문하지 않아야 함
int n; // 입력 : 정점의 수 n(1<=n<=20)
int sum=0; // 출력 : 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수

void DFS(int x)
{
    if(x == n) 
    {
        sum++;
        return; // n번까지 가면 재귀 종료
    }
    for(int i=1; i<=n; i++) // 1번부터 n번까지 모든 정점 x와 연결됐는지 확인
    {
        if(check[i]==0 && map[x][i] == 1) // 방문한 적이 없고, 연결된 노드라면
        {
            check[i]=1; // 방문했음
            DFS(i);
            check[i]=0; // 체크 해제해줘야 다음 반복 때 사용
        }
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int m; // 입력 : 간선의 수 m
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int a, b; // a : 출발정점, b : 도착정점
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }

    check[1]=1;
    DFS(1);
    printf("%d", sum);

	return 0;
}