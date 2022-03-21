#include <stdio.h>
#include <vector>
#include <queue>

struct State
{
    int x, y, dis; // 심바가 갈 수 있는 좌표와 거리
    State(int a, int b, int c)
    {
        x = a;
        y = b;
        dis = c;
    }
    bool operator< (const State &bb) const // 우선순위 큐에 정렬할 조건
    {
        if(dis != bb.dis) return dis>bb.dis; // 거리가 다르면 거리가 짧은 걸 우선순위 높게 함
        if(x != bb.x) return x>bb.x; // 거리가 같고 행(x)이 다르면 행이 낮은 걸 우선순위 높게 함
        if(y != bb.y) return y>bb.y; // 행도 같고 열(y)이 다르면 열이 낮은 걸 우선순위 높게 함
    }
};

struct Lion
{
    int x, y, size=2, ate=0; // 심바의 현재 위치, 심바의 사이즈, 먹은 토끼의 수
    void sizeUp() // 사이즈와 먹은 토끼의 수가 동일 할 때 사이즈 커짐
    {
        ate = 0;
        size++;
    }
};

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    int n; // 입력 : 정글의 크기 (2<=n<=25)
    int sum=0; // 출력 : 심바의 누적 거리
    int dx[4] = {0, 0, -1, 1}; // 상하좌우
    int dy[4] = {1, -1, 0, 0};
    Lion simba; // 입력 : 심바의 현재 위치
    scanf("%d", &n);
    std::vector<std::vector<bool> > ch(n+1, std::vector<bool>(n+1)); // 방문했는지 체크 배열
    std::vector<std::vector<int> > map(n+1, std::vector<int>(n+1)); // 입력 : 정글 정보
    std::priority_queue<State> pQ; // 심바가 먹을 토끼들 우선순위대로 정렬
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9)
            {
                simba.x = i; // 심바의 처음 위치 초기화
                simba.y = j;
                map[i][j] = 0; // 심바가 있었던 곳은 0으로 만듦
            }
        }
    }
    
    pQ.push(State(simba.x, simba.y, 0)); // 처음에 심바의 위치 넣어줌
    while(!pQ.empty())
    {
        State tmp = pQ.top();
        pQ.pop();
        
        int x = tmp.x;
        int y = tmp.y;
        int dis = tmp.dis;
        
        // 심바가 먹을 수 있는 토끼가 top에 있는 경우
        if(map[x][y]!=0 && map[x][y]<simba.size) // 심바와 사이즈가 같으면 지나갈 수는 있지만 먹지는 못함
        {
            // 심바의 위치를 바꿔줌
            simba.x = x;
            simba.y = y;
            
            simba.ate++;
            if(simba.ate == simba.size) simba.sizeUp(); // 심바의 크기와 먹은 토끼 수가 같으면 사이즈 업
            
            map[x][y]=0; // 토끼는 심바가 먹었으므로 0으로 만들어줌
            
            for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) ch[i][j]=false; // 방문 체크 모두 해제
            while(!pQ.empty()) pQ.pop(); // 방문하려 했던 노드 모두 없앰
            sum += dis; // 심바에서 토끼까지 누적해온 거리 더해줌
            
            dis=0; // 심바의 위치가 여기로 이동했으므로 거리는 다시 0
        }
        
        for(int i=0; i<4; i++) // @@@ 일단 상하좌우 다 추가하고 토끼가 나오면 0인 노드 다 없어짐 @@@
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            // 상하좌우에 있는 토끼 값이 범위 밖이거나, 심바보다 크기가 큰 토끼거나, 이미 방문한 곳이라면 큐에 추가하지 않음
            if(xx<1 || xx>n || yy<1 || yy>n || map[xx][yy]>simba.size || ch[xx][yy]==true) continue;
            
            pQ.push(State(xx, yy, dis+1)); // 기존에 들어있던 거리에서 +1해줌
            ch[xx][yy] = true;
            //printf("%d %d %d\n", xx, yy, dis+1);
        }
    }
    
    printf("%d", sum);
    
    return 0;
}