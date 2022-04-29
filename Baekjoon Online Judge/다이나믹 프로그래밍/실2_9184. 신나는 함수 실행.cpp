#include <iostream>

int dp[21][21][21]; // w함수의 값을 저장할 공간

int w(int a, int b, int c)
{
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) return dp[20][20][20]=w(20, 20, 20);
    if(dp[a][b][c]!=0) return dp[a][b][c];
    if(a<b&&b<c) return dp[a][b][c]=w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c);
    return dp[a][b][c]=w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int a, b, c; // 입력 : 세 정수(-50<=a, b, c<=50)
    while(true)
    {
        std::cin >> a >> b >> c;
        if(a==-1&&b==-1&&c==-1) break;
        std::cout << "w(" << a << ", " << b << ", " << c << ") = ";
        std::cout << w(a, b, c) << "\n";
    }
    
    return 0;
}