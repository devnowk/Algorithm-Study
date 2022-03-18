#include <stdio.h>
#include <vector>
#include <queue>

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    //int cnt=0; // 출력 : (1, 1)부터 (7, 7)까지 최단으로 움직인 칸의 수
    int dx[4] = {0, 0, -1, 1}; // 상하좌우
    int dy[4] = {1, -1, 0, 0};
    std::vector<std::vector<int> > map(9, std::vector<int>(9, 1)); // 9*9격자판 만듦
    std::queue<std::pair<int, int> > Q; // BFS에 활용할 큐
    for(int i=1; i<=7; i++) for(int j=1; j<=7; j++) scanf("%d", &map[i][j]);
    
    Q.push(std::make_pair(1, 1)); // 출발점 넣음
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int k=0; k<4; k++)
        {
            int xx = x+dx[k]; // 상하좌우로 움직인 곳
            int yy = y+dy[k];
            if(map[xx][yy] == 0) // 도로라면 한 번 가 봄
            {
                Q.push(std::make_pair(xx, yy));
                map[xx][yy] = map[x][y] + 1; // @@@ 부모 노드의 값에 1 추가함 @@@
                if(xx==7&&yy==7) // 앞으로 갈 값에 도착 노드가 있으면 프로그램 종료
                {
                    printf("%d", map[xx][yy]);
                    return 0;
                }
            }
        }
    }
    printf("-1"); // 도착 노드에 갈 수 없다면 -1 출력
    
    return 0;
}