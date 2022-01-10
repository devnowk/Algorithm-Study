#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    // 1. CaHb 2. CaH 3. CHb 4. CH 
    char ch[9]; // 입력(1<=a, b<=100)
    int cnt=0; // 출력(탄화수소의 질량 C : 12g, H : 1g)
    int a=0, b=0; // 각각 탄소의 개수, 수소의 개수
    
    scanf("%*c%d", &a); // C 다음 숫자만 받음
    if(a == 0) // 문자인 H가 바로 있으면 아무것도 안들어가서 0이 들어있음(1이 생략된 경우)
        a = 1;
    scanf("%*c%d", &b); // H도 없애고 숫자 b를 받음
    if(b == 0)
        b = 1;
        
    /*****************정석****************
    int pos; // 문자열 어디까지 검사했는지
    scanf("%s", &ch);
    if(ch[1]=='H') // 탄소 개수가 1일경우
    {
        a=1;
        pos=1;
    }else
    {
        for(int i=1; a[i]!='H'; i++)
        {
            a = a*10+(ch[i]-48); // 처음에 0돼서 1의자리만
            pos++;
        }
        pos++; // H가 있는 자리
    }
    if(a[pos+1]=='\0') // H의 숫자가 있는 자리가 비면
        b=1; // 1이 생략된 것
    else
    {
        for(int i=pos+1; a[i]!='\0'; i++)
        {
            b = b*10+(ch[i]-48);
        }
    }
    ************************************/
    
    cnt = a * 12 + b * 1;
    printf("%d", cnt);
    
	return 0; 
}