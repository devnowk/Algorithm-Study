#include <stdio.h>
#include <vector>

int n, r;    
int ch[20];
int sum=0;

void DFS(int num, int L) // 뽑은 숫자, 몇 번째로 뽑았는지
{
    if(L == r)
    {
        for(int i=0; i<r; i++) printf("%d ", ch[i]);
        puts("");
        sum++;
        return;
    }
    for(int i=num+1; i<=n; i++) // @@@ 뽑은 수 다음부터 DFS 돌림(0부터 돌리면 순열) @@@
    {
        ch[L] = i;
        DFS(i, L+1);
    }
}

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    scanf("%d %d", &n, &r);
    DFS(0, 0); // 0을 뽑고 0개를 뽑음
    printf("%d", sum);
    
    return 0;
}