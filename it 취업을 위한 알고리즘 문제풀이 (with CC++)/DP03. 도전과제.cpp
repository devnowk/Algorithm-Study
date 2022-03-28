#include <iostream>

int n; // 입력 : 계단의 개수(3<=n<=45)
int mem[46]; // 메모이제이션 DFS에서 사용

int StepUp(int n) // Top-Down
{
    if(n==1 || n==2) return n; // 1계단, 2계단 오르는 경우의 수는 1,2
    if(mem[n]>0) return mem[n]; // 이미 구한 값이면 바로 반환
    return mem[n] = StepUp(n-1)+StepUp(n-2); // 점화식
}

int StoneBridge(int n) // Bottom-Up
{
    mem[1]=1; mem[2]=2;
    for(int i=3; i<=n; i++) mem[i]=mem[i-2]+mem[i-1];
    return mem[n];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    std::cout << StepUp(n) << std::endl; // 계단 오르기
    std::cout << StoneBridge(n+1); // 돌다리 개수가 n
    
    return 0;
}