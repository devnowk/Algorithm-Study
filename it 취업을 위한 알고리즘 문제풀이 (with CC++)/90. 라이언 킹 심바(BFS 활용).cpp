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
    Lion simba; // 입력 : 심바의 현재 위치
    scanf("%d", &n);
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
    
    
    return 0;
}