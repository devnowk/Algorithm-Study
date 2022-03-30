#include <iostream>
#include <vector>
#include <queue>

struct Brick
{
    int volume; // 벽돌 밑면의 넓이(넓이가 큰 게 밑에 있어야 함)
    int height; // 벽돌의 높이
    int weight; // 벽돌의 무게(무게가 큰 게 밑에 있어야 함)
    
    Brick(int a, int b, int c)
    {
        volume = a;
        height = b;
        weight = c;
    }
    
    bool operator<(const Brick &b)const
    {
        return volume > b->volume; // 우선순위 큐 사용시 넓이 내림차순
    }
    
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 벽돌의 수
    std::cin >> n;
    std::priority_queue<Brick> pQ(n+1); // 넓이를 기준으로 내림차순 정렬된 벽돌들
    std::vector<int> mem(n+1); // DP : 쌓고자 하는 벽돌이 제일 꼭대기에 있다고 가정할 때의 최대 높이 값
    
    for(int i=1; i<=n; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        pQ.push(Brick(a, b, c));
    }
    
    for(int i=1; i<=n; i++) // mem 값 채워 나갈 반복문
    {
        for(int j=1; j<i; j++) // 이전의 벽돌들 위에 쌓을 수 있는 지 확인
        {
            int nowWeight = pQ[j]->weight; // 현재 쌓을 벽돌의 무게
            int nowHeight = pQ[j]->height; // 현재 쌓을 벽돌의 높이
            if(pQ[i]->weight<nowWeight && mem[j]+nowHeight>mem[i]) // 벽돌 쌓을 수 있는 지 확인 && 가장 최댓값인지 확인
            {
                mem[i]=mem[j]+nowWeight; // 밑에 벽돌의 최대 높이에 현재 벽돌의 높이 더함
            }
        }
    }
    
    return 0;
}