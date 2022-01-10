#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 값(3<=n<=100,000,000)
    int res=0; // 출력 값(자릿수의 총 개수)
    int sum=0, cnt=1, dig=9;
    // sum : 0,  9,  99,  999,  9999 (n의 범위를 알기 위해 사용)
    // cnt : 1,  2,   3,    4,     5 (digit에 따른 자릿수)
    // dig : 9, 90, 900, 9000, 90000 (cnt 자릿수를 가지는 숫자의 개수)
    
    scanf("%d", &n);
    
    while(sum+dig < n) // n이 9보다 크고 99보다 크고 999보다 크고..
    {
        res+=cnt*dig;
        sum+=dig; // n을 판별하는 값 sum 증가
        cnt++; // 자릿수 더해줌
        dig*=10; // 자릿수에 해당하는 수 증가
    }
    res+=(n-sum)*cnt;
    printf("%d", res);
    
	return 0;
}