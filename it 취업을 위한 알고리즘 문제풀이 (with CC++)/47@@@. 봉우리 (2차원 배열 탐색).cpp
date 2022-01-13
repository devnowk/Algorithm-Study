#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 격자판의 크기 n*n(1<=n<=50)
    //int a[52][52]; // 입력 : 지역의 높이, 상하좌우보다 크면 봉우리 지역(100이하)
    int cnt=0; // 출력 : 봉우리의 개수
    
    scanf("%d", &n);
    std::vector<std::vector<int>> a(n+2, std::vector<int>(n+2)); // @@@2차원 벡터 형태, 0 초기화@@@
    for(int i=0; i<n+2; i++) // 가장자리 포함
    {
        for(int j=0; j<n+2; j++)
        {
            if(i==0 || i==n+1 || j==0 || j==n+1)
                a[i][j] = 0; // 격자의 가장자리는 0으로 초기화(전역변수로 잡으면 자동초기화)
            else
                scanf("%d", &a[i][j]);
        }
    }
    // 상 : {-1, 0}, 하 : {1, 0}, 좌 : {0, -1}, 우 : {0 ,1}
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    for(int i=1; i<=n; i++) // 가장자리 부분 제외하고 봉우리 검사
    {
        for(int j=1; j<=n; j++)
        {
            /***@@@ 상하좌우의 배열을 따로 만들어서 for문 돌리기 @@@***
            int tmp = a[i][j];
            if(tmp > a[i-1][j] && tmp > a[i+1][j] && tmp > a[i][j-1] && tmp > a[i][j+1])
                cnt++;
            **********************************************************/
            bool flag = true; // 봉우리인지 확인
            for(int k=0; k<4; k++)
            {
                // @@@봉우리일 때 개수를 세는 것보다 봉우리가 아닐 때 flag에 표시하는 게 더 간단@@@
                if(a[i][j] <= a[i+dx[k]][j+dy[k]]) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
    }
    
    printf("%d", cnt);
    
	return 0;
}