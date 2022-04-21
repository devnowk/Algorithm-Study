#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) // 유클리드 알고리즘
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    short n; // 입력 : 링의 개수 n(3<=n<=100)
    std::cin >> n;
    short first; // 입력 : 첫 번째 링
    std::cin >> first;
    for(int i=2; i<=n; i++)
    {
        short r; // 입력 : 다른 링의 반지름
        std::cin >> r;
        short up=first; // 분자에 들어갈 수 (첫 번째 링의 반지름)
        short down=r; // 분모에 들어갈 수(i i번째 링의 반지름)
        short gcdNum;
        
        // 첫 번째 링과 i 번째 링의 반지름의 최대공약수를 찾는다.
        if(first > r) gcdNum = gcd(first, r); 
        else gcdNum = gcd(r, first);
        
        // 분모와 분자에 최대공약수를 나누면 기약 분수 형태가 된다.
        std::cout << up/gcdNum << "/" << down/gcdNum << "\n";
    }
    
    return 0;
}