#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n, m; // 입력 : 보드의 크기(8<=n, m<=50)
    int min=2500; // 출력 : 8*8 크기로 자른 후 다시 칠해야 하는 최솟값
    std::cin >> n >> m;
    std::vector<std::vector<char> > board(n, std::vector<char>(m)); // 입력 : n*m크기 보드 판 정보
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) std::cin >> board[i][j];
    
    // 8*8 크기로 잘라보기
    for(int i=0; i<=n-8; i++)
    {
        for(int j=0; j<=m-8; j++)
        {
            int tmp1=0; // 칠해야 하는 수(왼쪽 위가 하얀 색인 체스판)
            int tmp2=0; // 칠해야 하는 수(왼쪽 위가 검은 색인 체스판)
            for(int x=i; x<i+8; x++)
            {
                for(int y=j; y<j+8; y++)
                {
                    if((x%2==0&&y%2==0) || (x%2==1&&y%2==1)) // (행-짝, 열-짝) || (행-홀, 열-홀)
                    {
                        if(board[x][y]!='W') tmp1++; // 왼쪽 위가 하얀 색인 체스판을 만들 때
                        else tmp2++; // 왼쪽 위가 검은 색인 체스판을 만들 때
                    } else
                    {
                        if(board[x][y]!='B') tmp1++;
                        else tmp2++;
                    }
                }
            }
            if(tmp1<min) min=tmp1; // 칠하는 수가 최솟값이면 갱신
            if(tmp2<min) min=tmp2;
        }
    }
    
    std::cout << min;
    
    return 0;
}