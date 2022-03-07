#include <stdio.h>
#include <vector>

int n, r; // 입력 : 서로 다른 n개의 자연수 중 r개를 뽑아 일렬로 나열
int sum=0; // 출력 : 순열의 총 개수
int ch[16]; // 번호 들렸는지 체크하는 배열
int num[16]; // 입력 : n개의 서로 다른 자연수 오름차순 정렬됨
std::vector<int> res; // 출력할 번호 기억하는 배열

void DFS(int idx, int cnt) // num 배열 중 몇 번째 번호를 선택했는지, 몇 개째 번호를 뽑고 있는지 기록
{
    if(cnt == r) // r번째까지 오면 출력하고 재귀 종료
    {
        sum++; // 총 개수에 추가
        for(int i=0; i<r; i++) printf("%d ", res[i]);
        puts("");
        return;
    }
    for(int i=1; i<=n; i++) // @@@ For문 : num의 모든 숫자를 검사해서 체크가 된 것은 사용 안함 @@@
    {
        if(!ch[i]) // 방문했는지 검사, 방문하지 않았으면 DFS호출
        {
            res.push_back(num[i]); 
            ch[i] = 1; // 방문했다고 체크
            DFS(i, cnt+1);
            ch[i] = 0; // 재귀 갔다 오면 방문 체크 해제
            res.pop_back(); // 집어 넣은 값도 뺌(배열로 만들었으면 인덱스 값으로 접근할 때 빼는 거 필요 없음)
        }
    }
}

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    scanf("%d %d", &n, &r);
    for(int i=1; i<=n; i++) scanf("%d", &num[i]);
    
    DFS(0, 0); // 0번째 번호를 선택하고 0개째 선택했다.
    printf("%d", sum);
    
    return 0;
}