#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // 여는 괄호가 나오면 스택에 push, 닫는 괄호가 나오면 pop
    // pop하기 전에 스택이 비어있으면 올바르지 않는 괄호
    char str[31]; // 입력 : 괄호 문자열 (최대 30)
    std::stack<char> a;
    scanf("%s", str);
    
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == '(') // 여는 괄호이면 push
            a.push(str[i]);
        else if(a.empty()) // 스택이 비어있는데 닫는 괄호 들어오면 NO
        {
            printf("NO");
            return 0;
        } else // 스택에 괄호가 있고 닫는 괄호가 들어오면
            a.pop();
    }
    if(a.empty()) // 스택에 아무것도 없으면 YES
        printf("YES");
    else
        printf("NO");
    
	return 0;
}