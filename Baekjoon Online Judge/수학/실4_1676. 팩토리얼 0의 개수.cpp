#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : n!(0<=n<=500)
    std::cin >> n;
    int cnt=0;
    // 1~n까지 중 5의 개수를 구하면 뒷자리 0의 개수가 된다.(5*2 여야 하는데 5가 훨씬 적으므로)
    for(int i=5; i<=n; i+=5)
    {
        int tmp=i;
        while(tmp%5==0)
        {
            cnt++;
            tmp/=5;
        }
    }
    std::cout << cnt;
    
    return 0;
}