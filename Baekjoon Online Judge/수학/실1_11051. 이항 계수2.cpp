#include <iostream>
#include <vector>

int comb[1001][1001]; // 이항계수 메모이제이션 배열
int DFS(int n, int k)
{
    if(comb[n][k]!=0)return comb[n][k]; // 이미 존재하면 존재하는 값 반환
    if(n==k || k==0) return 1; // nCn=1
    if(k==1) return n; // nC1=n
    return comb[n][k]=(DFS(n-1, k)%10007)+(DFS(n-1, k-1)%10007);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n, k; // 입력 : 이항 계수 nCk
    std::cin >> n >> k;
    std::cout << DFS(n, k)%10007;
    
    return 0;
}