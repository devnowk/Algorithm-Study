#include <iostream>
#include <vector>
#include <algorithm>

struct Brick
{
    int size; // 벽돌 밑면의 넓이(넓이가 큰 게 밑에 있어야 함)
    int height; // 벽돌의 높이
    int weight; // 벽돌의 무게(무게가 큰 게 밑에 있어야 함)
    
    Brick(int a, int b, int c)
    {
        size = a;
        height = b;
        weight = c;
    }
    
    bool operator<(const Brick &b)const
    {
        return size > b.size; // sort 사용시 넓이 내림차순
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 벽돌의 수
    std::cin >> n;
    // @@@ 구조체 타입을 설정하면 크기 지정 할 수 없음 @@@
    std::vector<Brick> bricks; // 넓이를 기준으로 내림차순 정렬된 벽돌들
    std::vector<int> mem(n); // @@@ DP : 쌓고자 하는 벽돌이 제일 꼭대기에 있다고 가정할 때의 최대 높이 값 @@@
    
    for(int i=0; i<n; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        bricks.push_back(Brick(a, b, c));
    }
    
    sort(bricks.begin(), bricks.end()); // 넓이를 기준으로 내림차순 정렬됨
    
    for(int i=0; i<n; i++) // mem 값 채워 나갈 반복문
    {
        //mem[i]=bricks[i].height; // 높이 자기 자신만 있는 걸로 초기화(밑에 아무것도 없으면 자기 자신 높이만)
        int max_h=0; // 이전 값들 중에 높이 가장 큰 걸 구함
        int nowWeight = bricks[i].weight;
        int nowHeight = bricks[i].height;
        
        for(int j=0; j<i; j++) // 이전의 벽돌들 위에 쌓을 수 있는 지 확인
        {
            int lastWeight = bricks[j].weight; // 이전에 쌓은 벽돌의 무게
            if(nowWeight<lastWeight && mem[j]>max_h) // 벽돌 쌓을 수 있는 지 확인 && 가장 최댓값인지 확인
            {
                max_h=mem[j]; // 가장 높았던 벽돌 높이 구함
            }
        }
        mem[i]=max_h+nowHeight; // 밑에 벽돌의 최대 높이에 현재 벽돌의 높이 더함
        //std::cout << mem[i] << " ";
    }
    
    int max=0;
    for(int i=0; i<n; i++) 
    {
        if(max<mem[i]) max=mem[i];
    }
    
    std::cout << max;
    
    return 0;
}
