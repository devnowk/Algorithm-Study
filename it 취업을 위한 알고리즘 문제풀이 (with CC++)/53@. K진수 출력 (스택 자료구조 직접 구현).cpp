#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int st[100]; // 스택 배열
int top=-1; // 스택의 마지막을 가리킴

int pop()
{
    return st[top--];
}

void push(int x)
{
    st[++top] = x;
}
    
int main() {
    // freopen("input.txt", "rt", stdin);
    
    //std::stack<int> st;
    int n; // 입력 : 10진수 값(10<=n<=1,000)
    int k; // 입력 : 진수 종류(k = 2, 5, 8, 16)
    
    scanf("%d %d", &n, &k);
    while(n>0)
    {
        //st.push(n%k);
        push(n%k); // 나머지를 스택에 넣음
        n/=k;
    }
    
    char str[20]="0123456789ABCDEF"; // @@@ 16진수에서 10 넘으면 처리해주는 부분 @@@
    while(top!=-1)
    //while(!st.empty()) // 스택이 비어있으면 참 반환
    {
        printf("%c", str[pop()]);
        // printf("%c", str[st.top()]);
        // st.pop();
    }
    
	return 0;
}