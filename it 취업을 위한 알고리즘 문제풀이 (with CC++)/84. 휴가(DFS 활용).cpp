#include <stdio.h>
#include <vector>

std::vector<std::pair<int, int> > schedule(16); // 입력 : 상담 스케쥴
int maxVal = 0; // 최대 수익 기록
int n; // 입력 : 여행가는 전날

void DFS(int d, int sum) // d번째 날 누적 수입은 sum
{   
    //printf("DFS(%d, %d)\n", d, sum);
    if(d > n) // n번째 날 넘으면 끝
    {
        if(sum > maxVal) maxVal = sum;
        return;
    }
    std::pair<int, int> tmp = schedule[d]; // d번째 날 스케쥴
    if(d+tmp.first <= n+1) // 마지막 날이 1이면 할 수 있음(시작을 0부터 했어야..)
        DFS(d+tmp.first, sum+tmp.second); // d번째 날에 상담할 경우
    DFS(d+1, sum); // d번째 날에 상담하지 않을 경우, 그 다음 날로 넘어감    
}

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        schedule[i] = std::make_pair(a, b); // i번째 날 스케쥴 입력
    }
    
    DFS(1, 0); // 첫 번째 날, 누적 수입 0으로 DFS 시작
    
    printf("%d", maxVal);
    
    return 0;
}