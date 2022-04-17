#include <iostream>
#include <vector>
#include <algorithm>

struct point
{
    int x, y;
    point(int x, int y) // 생성자
    {
        this->x=x;
        this->y=y;
    }
    bool operator<(const point& b) const // 정렬 조건 함수
    {
        if(x==b.x) return y<b.y; // x좌표가 같으면 y좌표가 증가하는 순서로 정렬
        return x<b.x; // x좌표가 증가하는 순으로 정렬
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 점의 개수(1<=n<=100,000)
    std::vector<point> p; // 입력 : 점들
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        p.push_back(point(a, b));
        //std::cout << p[i].x << " " << p[i].y << "\n";
    }
    
    sort(p.begin(), p.end());
    for(int i=0; i<n; i++) std::cout << p[i].x << " " << p[i].y << "\n";
    
    return 0;
}