#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int n, m; // 입력 : n개 원소로 + - 이용하여 m만들기(1<=n<=10, 1<=m<=100)
int a[11]; // 입력 : n개의 원소 값
int cnt=0;
int path[11]; // m이 만들어지는 과정까지 출력

void DFS(int L, int sum) // level과 sum을 받음
{
    if(L==n+1) 
    {
        if(sum == m)
        {
            cnt++; // 합이 m이 되면 count++  
            for(int i=1; i<=n; i++)
            {   
                if(path[i] != 0)
                    printf("%d ", path[i]);
            }
            puts("");
        }
        return; // 끝까지 탐색하면 리턴 @@@리턴 안해도 다음 코드 없으므로 자동 리턴됨@@@
    } else
    {
        path[L] = a[L];
        DFS(L+1, sum+a[L]); // 1) a[i]를 + 연산
        path[L] = -a[L];
        DFS(L+1, sum-a[L]); // 2) a[i]를 - 연산
        path[L] = 0; // @@@ path[L] 값이 자꾸 바뀌므로 해줘야 함 @@@
        DFS(L+1, sum); // 3) a[i]를 포함하지 않음
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // 3가지의 경우를 고려하여 DFS를 돈다.
    // 1) +x인 경우 2) -x인 경우 3) 포함하지 않는 경우
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    
    DFS(1, 0); // a 원소들과 + - 연산을 이용하여 m만들기
    
    if(cnt==0) printf("-1");
    else printf("%d개", cnt);
    
	return 0;
}