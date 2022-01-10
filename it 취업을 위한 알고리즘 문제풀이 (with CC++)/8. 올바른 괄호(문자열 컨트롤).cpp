#include <stdio.h>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    char str[31]; // 입력 값(괄호)
    int cnt=0; // 괄호 수 세기(여는 괄호 : +1, 닫는 괄호 : -1)
    
    scanf("%s", str);
    
    for(size_t i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='(') cnt++;
        else if(str[i]==')') cnt--;
        
        if(cnt < 0) // 닫는 괄호가 먼저 나올 때
            break;
    }
    
    if(cnt == 0)
        printf("YES");
    else // 음수도 여기 포함
        printf("NO");
    
	return 0;
}