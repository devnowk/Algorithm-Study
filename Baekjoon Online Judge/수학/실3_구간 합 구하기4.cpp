#include <iostream>
#include <vector>

int sum[100001]; // sum[i] : 1~i번째 수를 모두 더한 값
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL); std::cin.tie(NULL);
    
    int n; // 입력 : 수의 개수(1<=n<=100,000)
    int m; // 입력 : 테스트 케이스(1<=m<=100,000)
    std::cin >> n >> m;
    
    for(int i=1; i<=n; i++)
    {
        int tmp;
        std::cin >> tmp;
        sum[i]=sum[i-1]+tmp; // 1~i-1을 모두 더한 수+i번째 값(tmp)
    }
    for(int idx=0; idx<m; idx++)
    {
        int i, j;
        std::cin >> i >> j;
        std::cout << sum[j]-sum[i-1] << "\n"; // 1~j까지 모두 더한 수에서 1~i-1까지 모두 더한 수를 빼면 i~j더한 수
    }
    
    return 0;
}