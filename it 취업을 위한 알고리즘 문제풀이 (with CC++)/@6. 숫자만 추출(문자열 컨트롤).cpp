#include <stdio.h>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    char a[51]; // 입력 : 문자와 숫자가 섞인 문자열
    int res=0, cnt=0; // 출력 : 결과 숫자, 약수 개수
    
    scanf("%s", a);
    for(int i=0; a[i]!='\0'; i++) // 문자열 마지막에 null 문자 '\0'
    {
        if(a[i]-48 >=0 && a[i]-48 <=9) // Askii 문자 '0' ~ '9'
            res = res*10 + (a[i]-48); // @@@ 0일 때는 1의 자리만 @@@
    }
    
    for(int i=1; i<=res; i++) // 약수 개수 구하기(1부터 끝까지)
    {
        if(res%i ==0) // 나누어지면 약수
            cnt++;
    }
    
    printf("%d\n%d", res, cnt);
	
	return 0;
}