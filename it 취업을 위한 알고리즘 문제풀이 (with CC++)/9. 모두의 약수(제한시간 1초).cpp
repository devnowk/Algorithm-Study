#include <stdio.h>

int cnt[50001]{};  
int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 값(5<=n<=50,000)
    
    scanf("%d", &n);
    printf("1 ");
    /************Time Limit**O(N^2)************************
    int cnt; // 출력 값(1~n 약수의 개수)
    for(size_t i=1; i<=n; i++) // 1~n까지 돌림
    {
        for(size_t j=1; j<=i; j++) // i의 약수의 개수를 구함
            if(i%j == 0)    cnt++;
        printf("%d ", cnt); // i의 약수의 개수
        cnt = 0;
    }
    *******************************************************/
	// 약수의 개수를 구하라 했지만 반대로 i가 약수인 수를 찾는 문제(배수)
	for(size_t i=1; i<=n; i++)
	{
	    for(size_t j=i; j<=n; j=j+i) // i는 j의 배수
	        cnt[j]++; // j가 i의 배수이다.
	    printf("%d ", cnt[i]);
	}
	
	return 0;
}