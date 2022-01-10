#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    int n; // 입력 값(2<=n<=200,000)
    int cnt=0; // 출력 값(1~N까지 소수 개수)
    
    scanf("%d", &n);
   
    for(size_t i=2; i<=n; i++)
    {
        bool flag = true; // 소수면 true
        for(size_t j=2; j*j<=i; j++) 
        //@@@제곱근 대신에 반대편 제곱@@@ 
        {
            if(i%j == 0){
                flag = false;
                break;
            }
        }
        if(flag)
            cnt++;
    }
    printf("%d", cnt);
    
	return 0;
}