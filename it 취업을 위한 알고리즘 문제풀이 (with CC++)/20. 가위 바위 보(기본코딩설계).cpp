#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(게임 횟수 1<=n<=100)
    int a[100], b[100]; // a가 낸 정보, b가 낸 정보
    
    scanf("%d", &n);
    for(size_t i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(size_t i=0; i<n; i++)
        scanf("%d", &b[i]);
        
    for(size_t i=0; i<n; i++)
    {
        if(a[i]-b[i] == 1 || a[i]-b[i] == -2) // a가 이겼을 경우
            printf("A ");
        else if(a[i]==b[i]) // 비겼을 경우
            printf("D ");
        else // b가 이겼을 경우
            printf("B ");
    }
        
	return 0;
}