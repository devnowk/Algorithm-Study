#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 소인수분해 할 수(1<=n<=10,000,000)
    std::cin >> n;
    
    if(n==1) return 0; // 1이면 아무것도 출력하지 않음
    
    int i=2;
    int tmp=n;
    while(i<=n)
    {
        if(tmp%i==0) 
        {
            std::cout << i << "\n"; // i로 나눠지면 i 출력
            tmp/=i;
        }
        else i++; // 나눠지지 않으면 i를 다음 수로 바꿈
    }
    
    return 0;
}