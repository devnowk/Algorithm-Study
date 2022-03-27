#include <iostream>

int n; // 입력 : 네트워크 선의 길이(3<=n<=45)
int mem[46];

int DFS2(int n)
{
    if(mem[n]>0) return mem[n]; // 중복된 호출 막아줌
    if(n==1 || n==2) return n;
    return mem[n] = DFS2(n-2)+DFS2(n-1); // 가지치기 하기 전
}



void DFS(int n) // 끝이 1m인 경우, 2m인 경우의 수를 합함
{
    // 값이 없을 때만 재귀 돌림
    if(mem[n-2]==0) DFS(n-2);
    if(mem[n-1]==0) DFS(n-1);
    
    mem[n]=mem[n-2]+mem[n-1]; // 점화식 적용
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    // 동적 계획법(Top-Down) : 재귀를 이용, DFS(7)을 호출하면 점점 낮은 수를 호출함
    //                         전부 호출하면 중복이 있으므로 메모이제이션을 이용
    
    std::cin >> n;
    mem[1]=1; mem[2]=2;
    DFS(n);
    std::cout << mem[n];
    
    return 0;
}