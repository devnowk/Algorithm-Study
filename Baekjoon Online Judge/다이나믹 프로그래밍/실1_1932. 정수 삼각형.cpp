#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int dp[501]; // 삼각형의 숫자 최댓값 누적
    short n; // 입력 : 삼각형의 크기(1<=n<=500)
    int max=0; // 출력 : 맨 아래층으로 가는 최댓값
    std::cin >> n;
    
    // 숫자의 최대 합 누적하기
    for(short i=1; i<=n; i++) // 첫 번째 행부터 n번째 행까지 돌림(i는 한 줄에 있는 숫자의 개수 의미)
    {
        int tmp[i]; // 입력 : 숫자 임시로 입력받을 곳(벡터로 선언하면 메모리 초과)
        for(short j=1; j<=i; j++)
        {
            std::cin >> tmp[j];
            // 이전 행의 대각선 수 중 큰 수와 더함
            if(j==1) tmp[j]+=dp[1];
            else if(j==i) tmp[j]+=dp[j-1];
            else tmp[j]+=std::max(dp[j], dp[j-1]);
        }
        // tmp에 누적했던 값을 dp에 옮김
        for(short j=1; j<=i; j++) 
        {
            dp[j]=tmp[j];
        }
    }
    for(short i=1; i<=n; i++)
    {
        if(dp[i]>max) max=dp[i];
    }
    std::cout << max;
    
    return 0;
}