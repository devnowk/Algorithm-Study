#include <iostream>
#include <vector>

int n; // 입력 : 사람 수(4<=n<=20, n은 짝수)
int min=2147000000; // 출력 : 두 팀 간의 능력치 차이 최소
int sum=0; // 모든 능력치의 합
int skill[21][21]; // 입력 : skill[i][j] - i와 j가 같은 팀일 때의 능력치
int who[11]; // who[i] - 스타트 팀의 사람 누구있는지
bool check[21]; // 스타트 팀으로 뽑혔으면 true

void DFS(int idx)
{
    if(idx>n/2) // 반만 정하면 나머지 반은 정해짐
    {
        int start=0, link=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(check[i]==true && check[j]==true) start+=skill[i][j];
                else if(check[i]==false && check[j]==false) link+=skill[i][j];
            }
        }
        
        int tmp=start-link;
        if(tmp<0) tmp=-tmp;
        if(tmp<min) min=tmp;
        return;
    }
    for(int i=who[idx-1]+1; i<=n; i++) // 한 사람씩 스타트 팀에 넣음
    {
        if(check[i]) continue;
        check[i]=true;
        who[idx]=i;
        DFS(idx+1);
        check[i]=false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) std::cin >> skill[i][j];
    
    DFS(1); // 스타트 팀 첫 번째 사람부터 정함
    
    std::cout << min;
    
    return 0;
}