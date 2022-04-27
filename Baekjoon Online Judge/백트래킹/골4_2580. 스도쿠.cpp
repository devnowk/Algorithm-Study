#include <iostream>
#include <vector>

std::vector<std::pair<int, int> > blank; // 빈칸의 좌표를 넣음
std::vector<std::vector<int> > sudoku(10, std::vector<int>(10)); // 입력 : 스도쿠 판
bool success; // 한 번 성공하면 DFS 모두 탈출

void DFS(int idx) 
{
    if(success) return;
    if(idx==blank.size())
    {
        for(int i=1; i<=9; i++)
        {
            for(int j=1; j<=9; j++) std::cout << sudoku[i][j] << " ";
            std::cout << "\n";
        }
        success=true;
        return;
    }
    int row = blank[idx].first; // 빈 칸의 행
    int col = blank[idx].second; // 빈 칸의 열
    for(int i=1; i<=9; i++) // 1~9 중 들어갈 수 있는 숫자 찾기
    {
        bool isExist = false; // 숫자 이미 있는 지 판단
        for(int j=1; j<=9; j++) // 가로 세로에 i없는지 확인
        {
            if(sudoku[row][j]==i || sudoku[j][col]==i)
            {
                isExist=true;
                break;
            }
        }
        // 자신이 포함된 정사각형에 i없는지 확인
        int FRow = (row-1)/3*3+1; // 시작 행(3으로 나누면 나머지는 다 버림이라서 가능한 식)
        int FCol = (col-1)/3*3+1; // 시작 열
        for(int j=FRow; j<FRow+3; j++)
        {
            for(int k=FCol; k<FCol+3; k++)
            {
                if(sudoku[j][k]==i)
                {
                    isExist=true;
                    break;
                }
            }
        }
        if(isExist) continue; // 가로 세로 정사각형에 존재하면 다음 숫자 확인
        sudoku[row][col]=i;
        DFS(idx+1);
        sudoku[row][col]=0; // 0으로 만들어줘야 다음 숫자 검사할 때 잘 돌아감
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            std::cin >> sudoku[i][j];
            if(sudoku[i][j]==0) blank.push_back(std::make_pair(i, j));
        }
    }
    //std::cout << blank.size();
    DFS(0); // blank에 들어있는 0 번째 빈칸부터 값을 채워나감
    
    return 0;
}