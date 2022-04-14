#include <iostream>
#include <vector>

std::vector<std::vector<char> > canvas(7000, std::vector<char>(7000, ' ')); // 캔버스를 공백으로 채움
void starDraw(int x, int y, int n) // 좌표 (x, y)에 별을 찍는다. 
{
    if(n==1) // 더 이상 쪼개질 수 없을 때, 별을 찍고 반환한다.
    {
        canvas[x][y]='*';
        return;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i==1 && j==1) continue; // (1,1)은 공백으로 비워둔다.
            starDraw(x+i*n/3, y+j*n/3, n/3); // n/3으로 쪼개면서 진짜 좌표를 입력해줌(현재 좌표+반영된 크기)
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 3의 거듭제곱 n=3^k (1<=k<8)
    std::cin >> n;
   
    starDraw(0, 0, n); // (0, 0)좌표에 n/3크기의 패턴을 3*3만큼 찍어 내는 함수
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cout << canvas[i][j];
        }
        std::cout << "\n";
    }
    
    return 0;
}