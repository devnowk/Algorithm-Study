#include <stdio.h>
#include <vector>
#define x first // @@@ first 대신에 x로 하겠다.
#define y second // second 대신에 y로 하겠다. @@@

int n; // 입력 : 정점의 수 n(1<=n<=20)
int min = 2147000000; // 출력 : 1번 정점에서 n번 정점으로 가는 최소비용
int ch[21]; // 방문한 노드 체크

// pair는 vector라이브러리에 포함돼있음
std::vector<std::pair<int, int> > map[21]; // 한 쌍의 정보(정점, 가중치)를 저장할 수 있는 벡터21개 생성

void DFS(int v, int sum)
{
    if(v == n)
    {
        if(sum < min) min = sum;
    }
    else
    {
        for(int i=0; i<map[v].size(); i++) // v와 연결된 정점 수만큼 반복
        {
            std::pair<int, int> node = map[v][i]; // v와 연결된 노드정보
            if(ch[node.first] == 0) // 방문하지 않은 노드
            {
                ch[node.first] = 1; // 방문 체크
                DFS(node.first, sum+node.second);
                ch[node.first] = 0; // 방문 해제
            }
        }
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // std::pair<int, char> p; // pair : 두 개의 데이터를 한 쌍으로 묶음
    // p = std::make_pair(10, 'T'); // 실제 메모리에 값이 들어감
    // printf("%d %c\n", p.first, p.second);
    
    int m; // 입력 : 간선의 수
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(std::make_pair(b, c)); // a와 연결된 정점 b와 가중치 c를 한 쌍을 묶음
    }
    ch[1] = 1; // 1번 노드 방문한 상태
    DFS(1, 0);
    
    printf("%d", min);
    
	return 0;
}