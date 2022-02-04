#include <stdio.h>
#include <vector>
#include <queue>

int ch[10001]; // 방문한 지점에 레벨 체크해둠
std::queue<int> Q; // BFS에 활용할 큐

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int s, e; // 입력 : 현수의 위치 s, 송아지의 위치 e(1<=s,e<=10,000)
    int cnt=0; // 출력 : 현수가 송아지의 위치까지 갈 수 있는 최소 점프 횟수
    int jump[3] = {-1, 1, 5};
    
    scanf("%d %d", &s, &e);
    
    Q.push(s); // 현수의 위치 넣음
    ch[s] = 1; // 현수의 위치 방문 체크
    
    while(!Q.empty()) // Q에 뭐가 있으면 계속 반복
    {
        int x = Q.front();
        Q.pop(); // 큐에 있는 것 꺼냄
        
        for(int i=0; i<3; i++) // 뒤로 1,앞으로 1, 5 경우의 수를 큐에 담음
        {
            if(x+jump[i]<=0 || x+jump[i]>10000) continue;
            if(x+jump[i] == e) // 목적지에 도착하면
            {
                printf("%d", (ch[x]+1)-1); // 루트에서 점프횟수 = 현재레벨 - 루트레벨
                return 0;
            }
            if(ch[x+jump[i]] == 0) // 방문한 적 없는 정점
            {
                Q.push(x+jump[i]); // 점프한 정점 큐에 담음
                ch[x+jump[i]] = ch[x]+1; // 레벨 넣음
            }
        }
    }
     
	return 0;
}