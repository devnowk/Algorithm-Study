#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

// 그래프의 종류
// 행 : 출발 정점, 열 : 도착 정점
// 1. 무방향 그래프 : 인접행렬에서 0과 1로 표시(대칭)
// 2.   방향 그래프 : 인접행렬에서 0과 1로 표시(대칭X)
// 3. 가중치 방향 그래프 : 인접행렬에서 0과 자연수로 표시(대칭X)
int map[21][21]; // 출력 : 방향 그래프의 정보를 인접행렬로 표현하기
int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n, m; // 입력 : 정점의 수n(1<=n<=20), 간선의 수 m
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=m; i++) // 간선의 수만큼 반복
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d ", map[i][j]);
        puts("");
    }
	return 0;
}
