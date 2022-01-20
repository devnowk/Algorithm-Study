#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int n; // 입력(1<=n<=10)
int group[11]; // 두 개의 부분집합으로 나눠야 하므로 1과 2로 나눔
int a[11]; // 입력 : 집합 원소
bool flag = false; // 출력 : 두 부분집합의 합이 같은 경우가 존재하면 true

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
    }
    
    Subset(1); // 집합을 두 개의 부분집합으로 나누어서 두 집합의 합이 동일한지 체크
    
    if(flag) printf("YES");
    else printf("NO");
    
	return 0;
}