#include <iostream>

int n; // 입력 : N-Queen의 크기(1<=n<15)
int cnt=0; // 출력 : 퀸을 놓는 방법의 수
int arr[15]; // 퀸을 놓는 체스판, arr[i] : i번째 행의 퀸은 몇 번째 열에 있는지 좌표 저장
bool check[15]; // 퀸이 자리 잡고 있는 지 여부, check[i] : i번째 열에는 퀸이 있다(true)

void DFS(int row) // row 번째 행에 퀸을 놓는 경우
{
    if(row>n) // 마지막 행 다음(모든 행에서 잘 배치된 상태)일 때 개수 세고 탈출
    {
        cnt++;
        //std::cout << "cnt : " << cnt << "\n";
        return;
    }
    for(int i=1; i<=n; i++) // 1부터 n열까지 퀸을 다 넣어봄
    {
        if(check[i]) continue; // 이미 해당 열에 다른 퀸이 있으면 넘어감
        bool tmp=true; // 대각선 겹치지 않으면 true
        for(int j=1; j<row; j++) // 이전 값들의 대각선 위치인지 확인
        {
            // 대각선 위치인지 확인 - 두 좌표의 기울기가 -1 또는 1이면 됨
            int dx = row-j;
            int dy = i-arr[j];
            if(dx==dy || dx==-dy)
            {
                //std::cout << "diagonal : (" << row << ", " << i << "), (" << j << ", " << arr[j] << ")\n";
                tmp=false;
                break;
            }
        }
        if(!tmp) continue; // 대각선 겹치므로 다음 열 검사
        arr[row]=i;
        check[i]=true;
        //std::cout << "row : " << row << " col : " << i << "\n";
        DFS(row+1);
        check[i]=false;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    DFS(1); // 1 번째 행의 퀸 정하기
    std::cout << cnt;
    
    return 0;
}