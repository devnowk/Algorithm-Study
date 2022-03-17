#include <stdio.h>
#include <vector>
#include <queue>

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    int n; // 입력 : 격자판 크기 n(1<=n<=20)
    int cnt=0; // 출력 : 섬나라 개수
    int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1}; // 상하좌우, 대각선
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    std::queue<std::pair<int, int> > Q; // BFS에 이용할 Queue
    scanf("%d", &n);
    std::vector<std::vector<int> > map(n+2, std::vector<int>(n+2)); // 격자판 정보
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            map[i][j] = tmp;
        }
    }
    
    //Q.push(std::make_pair(1, 1)); // 시작점인 (1, 1) 좌표를 넣음
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(map[i][j] == 1) // 모든 격자 확인해서 1이면 섬나라 하나 추가
            {
                Q.push(std::make_pair(i, j));
                //printf("%d %d\n", i, j);
                cnt++;
                while(!Q.empty())
                {
                    int x = Q.front().first;
                    int y = Q.front().second;
                    Q.pop();
                    map[x][y] = -1; // 지나간 수는 -1로 만듦
                    
                    for(int k=0; k<8; k++) // 상하좌우대각선에 1인 수 있는지 확인
                    {
                        if(map[x+dx[k]][y+dy[k]] == 1) // 연결된 지점이면
                            Q.push(std::make_pair(x+dx[k], y+dy[k]));
                    }
                }
            }
        }
    }
    
    printf("%d", cnt);
    
    return 0;
}