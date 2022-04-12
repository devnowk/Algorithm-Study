#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    // 위상정렬 : 일의 선후관계를 유지하면서 전체 일의 순서를 짜는 알고리즘
    int n, m; // 입력 : 일의 개수 n, 일의 순서 정보 개수 m
    std::cin >> n >> m;
    std::vector<int> degree(n+1); // 각 일의 진입차수 개수
    // 진입차수 : 일을 시작하기 전에 미리 끝내야 하는 일의 개수
    std::vector<int> graph[n+1]; // 입력 : 그래프의 정보(인접 리스트)
    std::queue<int> Q; // 진입차수가 0인 일들을 넣어서 진행
    
    for(int i=0; i<m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b); // a일을 끝내고 나서 b를 할 수 있음
        degree[b]++; // b를 하기 전에 해야 하는 일의 개수를 기록
    }
    
    for(int i=1; i<=n; i++) if(degree[i]==0) Q.push(i); // Q에 진입차수가 0인 일을 넣어둠
    while(!Q.empty())
    {
        int tmp = Q.front(); // 큐에 담긴 일을 한 개 뺌
        Q.pop();
        //degree[tmp]=-1; // 한 번 한 일의 진입차수는 -1로 만듦
        std::cout << tmp << " ";
        for(int i=0; i<graph[tmp].size(); i++) // @@@ tmp일을 하면 연결된 일들의 진입차수가 낮아지는 작업 @@@
        {
            int work = graph[tmp][i];
            degree[work]--;
            if(degree[work]==0) Q.push(work); // 안전하게 연결된 일들만 확인함
        }
        //for(int i=1; i<=n; i++) if(degree[i]==0) Q.push(i); // 이렇게 하면 두 가지 일이 큐에 있었을 경우 뒤에 일은 한 번 더 하게 됨
    }
    
    return 0;
}