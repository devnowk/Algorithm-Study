#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int map[9][9]; // 입력 : 격자판 정보 1은 벽, 0은 통로
int sum=0; // 출력 : 출발점(1, 1)에서 도착점(7, 7)로 가는 방법의 수

void DFS(int x, int y)
{
    if(x == 7 && y == 7)
    {
        sum++;
        return;
    }
    // 상하좌우를 가리키는 (dx, dy)
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0}; 
    
    for(int i=0; i<4; i++) // 상하좌우 한 번씩 가볼 것임
    {
        // @@@ 가려고 하는 좌표를 따로 변수로 만드는 게 가독성이 더 좋긴 함 @@@
        if(map[x+dx[i]][y+dy[i]] == 0) // 다음 갈 곳이 벽이 아닌 통로라면
        {
            map[x+dx[i]][y+dy[i]] = -1; // 갔던 곳이라고 표시를 해둠
            DFS(x+dx[i], y+dy[i]); // 통로로 이동
            map[x+dx[i]][y+dy[i]] = 0; // 왔던 길에서 해제시킴
        }
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    // 경로의 모든 경우를 구하는 것이므로 DFS를 사용(최단 거리일 경우 BFS)
    for(int i=1; i<=7; i++)
        for(int j=1; j<=7; j++)
            scanf("%d", &map[i][j]);
    
    for(int i=0; i<=8; i++) // 미로의 가장자리 부분은 벽으로 채운다.
    {
        map[0][i] = 1;
        map[i][0] = 1;
        map[8][i] = 1;
        map[i][8] = 1;
    }
    map[1][1] = -1; // 시작하는 곳은 왔던 길로 표시
    DFS(1, 1); // (1, 1)부터 시작하여 길을 찾는다.
    
    printf("%d", sum);
    
	return 0;
}