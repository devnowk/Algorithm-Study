#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 회원의 수(1<=n<=50)
    std::cin >> n;
    std::vector<std::vector<int> > dis(n+1, std::vector<int>(n+1, n-1)); // dis[i][j]의미 : i->j 회원 사이의 최소 거리
    
    while(true) // -1, -1 입력이 들어오면 반복문 중지
    {
        int a, b;
        std::cin >> a >> b;
        if(a==-1 && b==-1) break;
        dis[a][b]=1; // dis(0) 초기화 : 두 회원이 친구사이인 1값으로 초기화
        dis[b][a]=1; // 대칭
    }
    for(int i=1; i<=n; i++) dis[i][i]=0; // 자기 자신은 0
    
    for(int k=1; k<=n; k++) // k사람을 거쳐서 친구 관계가 이루어지면 그 값으로 업데이트
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dis[i][j]=std::min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    
    int minScore=50; // 회장 후보의 점수
    int cnt=0; // 회장 후보 수
    std::vector<int> who(n+1);
    for(int i=1; i<=n; i++)
    {
        int max=0; // 친구관계의 최댓값이 이 사람의 점수가 됨
        for(int j=1; j<=n; j++)
        {
            if(dis[i][j]>max) max=dis[i][j];
        }
        who[i]=max; // 점수 기록
        if(max<minScore) minScore=max; // 회장 후보의 점수 갱신
    }
    
    for(int i=1; i<=n; i++) if(who[i]==minScore) cnt++;
    std::cout << minScore << " " << cnt << std::endl;
    for(int i=1; i<=n; i++) if(who[i]==minScore) std::cout << i << " ";
    
    return 0;
}