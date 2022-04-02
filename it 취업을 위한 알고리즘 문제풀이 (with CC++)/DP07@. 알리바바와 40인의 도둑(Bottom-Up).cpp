#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 계곡의 돌다리 크기 n*n(1<=n<=20)
    std::cin >> n;
    std::vector<std::vector<int> > map(n, std::vector<int>(n)); // 입력 : 돌다리 건너는 데 필요한 에너지 정보
    std::vector<std::vector<int> > mem(n, std::vector<int>(n)); // DP : dy[i][j] - (0,0)->(i,j)로 가는 데 드는 최소 비용 정보
    
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) std::cin >> map[i][j];
    
    // @@@ mem의 0행, 0열 정보를 먼저 초기화 시킴(0행, 0열에 있는 칸은 오로지 한 가지 방법으로만 갈 수 있으므로 초기화 가능) @@@
    mem[0][0] = map[0][0];
    for(int i=1; i<n; i++) mem[0][i] = mem[0][i-1]+map[0][i]; // 0행 초기화
    for(int i=1; i<n; i++) mem[i][0] = mem[i-1][0]+map[i][0]; // 0열 초기화
    
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            int min = std::min(mem[i-1][j], mem[i][j-1]); // 위쪽과 왼쪽에서만 올 수 있으므로 둘 중 작은 걸 더해야함
            mem[i][j] = min+map[i][j];
            //std::cout << mem[i][j] << " ";
        }
        //std::cout << std::endl;
    }
    
    std::cout << mem[n-1][n-1];
    
    return 0;
}