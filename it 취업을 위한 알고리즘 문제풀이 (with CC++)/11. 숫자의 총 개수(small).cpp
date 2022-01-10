#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 값(3<=n<=100,000)
    int cnt=0; // 출력 값(자리수의 총 개수)
    
    scanf("%d", &n);
    for(size_t i=1; i<=n; i++)
    {
        int tmp = i; // i를 나눠버리면 안됨
        while(tmp > 0)
        {
            cnt++;
            tmp/=10;
        }
    }
    printf("%d", cnt);
    
	return 0;
}