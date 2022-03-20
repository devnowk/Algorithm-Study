#include <stdio.h>
#include <vector>
#include <queue>

struct Loc{ // 구조체 정의
    int x; // 익은 토마토의 x좌표
    int y; // 익은 토마토의 y좌표
    Loc(int a, int b) // 생성자
    {
        x = a;
        y = b;
    }
};

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    int cnt=0; // 안익은 토마토의 개수
    int day=0; // 출력 : 토마토가 모두 익는 날짜
    int m; // 입력 : 상자의 가로 칸의 수 (2<=m<=1,000)
    int n; // 입력 : 상자의 세로 칸의 수 (2<=n<=1,000)
    int dx[4] = {0, 0, -1, 1}; // 상하좌우
    int dy[4] = {1, -1, 0, 0};
    scanf("%d %d", &m, &n);
    std::vector<std::vector<int> > map(n+2, std::vector<int>(m+2, -1)); // 토마토의 정보
    std::queue<Loc> Q; // 익은 토마토의 좌표를 넣어서 BFS에 활용
    
    for(int i=1; i<=n; i++) 
    {
        for(int j=1; j<=m; j++) 
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0) cnt++; // 안 익은 토마토의 수를 셈
            if(map[i][j] == 1) Q.push(Loc(i, j)); // 익은 토마토는 큐에 넣음
        }
    }
    if(cnt == 0) // 모두 익은 토마토일 때
    {
        printf("0");
        return 0;
    } else if(Q.empty()) // 익은 토마토가 하나도 없을 때
    {
        printf("-1");
        return 0;
    }
    
    while(!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();
        
        for(int k=0; k<4; k++)
        {
            int xx = x+dx[k];
            int yy = y+dy[k];
            if(map[xx][yy] == 0) // 자식이 안익은 토마토이면 익게 하고 날짜 넣음
            {
                cnt--;
                Q.push(Loc(xx, yy));
                map[xx][yy] = map[x][y] + 1;
                //printf("%d ", cnt);
            }
        }
    }
    
    if(cnt!=0) // 덜익은 토마토가 있으면 -1 출력
    {
        printf("-1");
        return 0; 
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(map[i][j] > day) day = map[i][j]; // 최대로 적힌 날짜를 추출해냄
        }
    }
    
    printf("%d", day-1); // 1로 시작했으므로 1 빼줘야 함
    
    return 0;
}