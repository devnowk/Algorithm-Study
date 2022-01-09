#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 값(학생수 1<=n<=10)
    int num, ans; // 입력(숫자, 학생이 말한 정답)
    //int res;
    
    scanf("%d", &n);
    for(size_t i=0; i<n; i++)
    {
        scanf("%d", &num);
        scanf("%d", &ans);
        
        int sum = num*(num+1)/2; // 수학 공식
        if(ans == sum)
            printf("YES\n");
        else
            printf("NO\n");
    }
      
	return 0;
}