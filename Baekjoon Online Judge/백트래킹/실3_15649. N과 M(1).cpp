#include <iostream>

int n, m; // 입력 : 1~n 중 m개를 고르는 수열 구하기(깊이 우선으로 탐색)(1<=m<=n<=8)
int arr[9]; // 1부터 m까지 들어 있는 수를 출력
bool ch[9]; // 1부터 8까지 방문했는지 체크
void DFS(int idx)
{
    if(idx>m) // 선택된 개수가 m이면 리턴
    {
        for(int i=1; i<=m; i++) std::cout << arr[i] << " ";
        std::cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++)
    {
        // 방문 상태를 체크하고 해제하는 과정이 백트래킹
        
        if(ch[i]) continue; // 이미 방문했으면 무시
        arr[idx]=i; // idx번째 숫자 정함
        ch[i]=true; // 방문 체크
        DFS(idx+1); // 다음 숫자 정함
        ch[i]=false; // 방문 체크 해제
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> m;
    
    DFS(1); // 첫 번째 수부터 정하기
    
    return 0;
}