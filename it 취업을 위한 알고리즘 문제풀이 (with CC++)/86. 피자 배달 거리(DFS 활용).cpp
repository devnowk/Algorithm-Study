#include <stdio.h>
#include <vector>

std::vector<std::pair<int, int> > pizza; // 입력 : 피자집의 좌표 모음
std::vector<std::pair<int, int> > house; // 입력 : 집의 좌표 모음
int m; // 입력 : 선택될 피자집의 개수(1<=m<=12)
int min=2147000000; // 출력 : 피자집들과 도시의 최소 피자배달거리
int ch[13]; // 선택된 피자집의 인덱스 번호 넣을 배열

void DFS(int L, int cnt)
{
    //printf("DFS(%d, %d)\n", L, cnt);
    if(cnt == m) // 마지막 피자집이 선택됐을 때, 집들과의 최소 거리 구해야 함
    {
        int sum=0; // 집들과의 거리 합
        for(int i=0; i<house.size(); i++) // 집들의 개수만큼 반복
        {
            int tmp=2147000000;
            for(int j=0; j<m; j++) // 선택된 피자집들의 개수만큼 반복
            {
                // 피자집과 집 사이의 거리 구함(어느 게 최소인지 모르므로 일단 다 구함)
                int dx = house[i].first - pizza[ch[j]].first;
                int dy = house[i].second - pizza[ch[j]].second;
                if(dx<0) dx = -dx;
                if(dy<0) dy = -dy;
                //printf("%d %d\n", dx, dy);
                if(dx+dy < tmp) tmp = dx+dy;
                //printf("%d\n", tmp);
            }
            sum+=tmp; // 집과 가장 가까운 피자집과의 거리가 sum에 축적됨
        }
        if(sum < min) min = sum; // 모든 집과 피자집의 거리가 min에 넣어짐
        //printf("%d\n", sum);
        return;
    }
    for(int i=L; i<pizza.size(); i++)
    {
        ch[cnt] = i; // i번째 피자집을 선택함
        DFS(i+1, cnt+1);
    }
}

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    int n; // 입력 : 지도의 크기 n*n(2<=n<=50)
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            if(tmp == 1) house.push_back(std::make_pair(i, j));
            else if(tmp == 2) pizza.push_back(std::make_pair(i, j));
        }
    }
    
    DFS(0, 0); // 0번째 부터 선택 시작, 첫 번째 선택된 피자집
    
    printf("%d", min);
    
    return 0;
}