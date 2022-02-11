#include <stdio.h>
#include <vector>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(7<=n<1000)
    int cnt=0;// 출력 : 2개 이상의 연속된 자연수의 합으로 n을 표현하는 가짓수
	scanf("%d", &n);
	
	// 15 = 7+8 = 4+5+6 = 1+2+3+4+5
	// 연속된 숫자들의 조합이므로 두 개짜리(x, x+1)에서 (n-1)%2==0이면 만족
	// 세 개짜리(x, x+1, x+2)에서 (n-3)%3==0이면 만족
	// 네 개짜리(x, x+1, x+2, x+3)에서 (n-6)%4==0이면 만족
	/*****@@@ sum을 더하지 않고 n에서 빼는 방법도 있음@@@*****
	int sum=1; // 1, 2, 3, 4, ..더하는 곳
	int num=2; // 2개짜리, 3개짜리, ...
	while(1)
	{
	    int mok = (n-sum)/num; // 몫(x 값을 의미함)
	    
	    if(mok==0) // 몫이 0이면 숫자를 표현할 수 없음
	        break;
	    else if((n-sum)%num==0) // 연속된 숫자들로 n 표현 가능
	    { 
	        cnt++;
	        for(int i=0; i<num-1; i++) // num개 짜리 
	            printf("%d + ", mok+i);
	        printf("%d = %d\n", mok+num-1, n);
	    }
	    sum+=num;
	    num++;
	}
	**********************************************************/
	int num = 2; // 2개짜리부터 시작
	int tmp = n;
	while(n > 0)
	{
	    n-=(num-1);
	    if(n%num == 0 && n/num!=0)
	    {
	        cnt++;
	        for(int i=0; i<num-1; i++)
	            printf("%d + ", (n/num)+i);
	        printf("%d = %d\n", (n/num)+(num-1), tmp);
	    }
	    num++;
	}
	
	printf("%d", cnt);
	// @@@ x가 0이 될 수 있으므로 되도록 x+1, x+2, x+3 형태로 하는게 더 좋음 @@@
	return 0;
}
