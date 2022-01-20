#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int n; // 입력(1<=n<=10)
int group[11]; // 두 개의 부분집합으로 나눠야 하므로 1과 2로 나눔
int a[11]; // 입력 : 집합 원소
bool flag = false; // 출력 : 두 부분집합의 합이 같은 경우가 존재하면 true

// @@@ 합이 집합 전체의 1/2이 되는 부분집합을 구하는 방법으로도 가능 @@@
int total=0; // 집합 전체의 합 main에서 담음
void DFS(int L, int sum) // 부분집합이 total/2가 되면 멈춤
{
    if(flag) return; // 모든 재귀 종료
    if(sum == total/2) // 재귀함수 종료 지점
    {
        flag = true;
        return;
    } // else if(sum > total/2) return; // 부분집합의 합이 total/2보다 커지면 답이 절대 불가능 
    // @@@ 안되는 조건이 더 있음 부분집합 합이 더 작은 경우도 return 필요함 @@@
    else if(L == n+1) return;
    else // 재귀함수 도는 중
    {
        DFS(L+1, sum+a[L]); // 다음 레벨의 자식한테 넘기는데, 자신을 더해서 넘김(부분집합에 자기도 포함하겠다는 뜻)
        DFS(L+1, sum); // 다음 레벨의 자식한테 넘기는데, 자신은 부분집합에 포함하지 않고 넘김
    }
    
}

void Subset(int x) // 인덱스 번호 전달
{
    if(flag) return; // @@@ 종료 지점2 재귀함수 연달아 종료됨 @@@
    if(x == n+1) // 종료 지점
    { // 트리의 끝까지 가면 합을 비교함
        int sum1=0, sum2=0;
        for(int i=1; i<=n; i++)
        {
            if(group[i] == 1) sum1+=a[i]; // 1그룹이면 sum1에 더함
            else sum2+=a[i]; // 2그룹이면 sum2에 더함
        }
        if(sum1 == sum2) flag = true;
        
        return;
    } else
    {
        group[x] = 1; // 그룹1로 바꾸고
        Subset(x+1); // 왼쪽 자식 노드 호출
        group[x] = 2; // 그룹2로 바꾸고
        Subset(x+1); // 오른쪽 자식 노드 호출
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        total += a[i];
    }
    // @@@ total/2로 계산할 거면 홀수일 경우 바로 NO 해야함(소수점은 버리기 때문에) @@@
    if(total % 2 == 1)
    {
        printf("NO");
        return 0;
    }
    
    //Subset(1); // 집합을 두 개의 부분집합으로 나누어서 두 집합의 합이 동일한지 체크
    DFS(1, 0); // 레벨과 부분집합의 합계 넘김
    
    if(flag) printf("YES");
    else printf("NO");
    
	return 0;
}
