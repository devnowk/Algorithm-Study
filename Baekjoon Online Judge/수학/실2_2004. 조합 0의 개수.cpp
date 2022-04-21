#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n, m; // 입력 : 이항계수 nCm(0<=m<=n<=2,000,000,000, n!=0)
    std::cin >> n >> m;
    
    // n! 0의 개수 - m! 0의 개수 - (n-m)! 0의 개수
    
    // n! 2의 개수는 n을 2^k로 나눈 수들을 합한 값과 같음
    // 10/2=5 (2, 4, 6, 8, 10) -> 2가 한 번 포함된 수들
    // 10/4=2 (4, 8) -> 2가 두 번 포함된 수들
    // 10/8=1 (8) -> 2가 세 번 포함된 수
    // 따라서 10!의 2의 개수는 5+2+1=8개
    
    // 0의 개수를 구하기 위해서는 2와 5의 개수를 구해 작은 값을 구하면 됨
    int two=0, five=0;
    
    // n!의 2와 5의 개수 구하기
    for(long long i=2; i<=n; i*=2) two+=n/i;
    for(long long i=5; i<=n; i*=5) five+=n/i;
    
    // m!의 2와 5의 개수 구해서 빼기
    for(long long i=2; i<=n; i*=2) two-=m/i;
    for(long long i=5; i<=n; i*=5) five-=m/i;
    
    // (m-n)!의 2와 5의 개수 구해서 빼기
    for(long long i=2; i<=n; i*=2) two-=(n-m)/i;
    for(long long i=5; i<=n; i*=5) five-=(n-m)/i;
    
    std::cout << std::min(two, five);
    
    return 0;
}