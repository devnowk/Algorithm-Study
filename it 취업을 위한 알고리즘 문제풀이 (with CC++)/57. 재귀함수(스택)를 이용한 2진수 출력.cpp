#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

void recur(int x)
{
    if(x==0) return; // 0이면 더 나누지 못하므로 재귀 종료
    else
    {
        int tmp = x%2; // 처음 나머지 기억(나중에 출력해야 함)
        recur(x/2);
        printf("%d", tmp); //재귀 호출 종료되면 거꾸로 출력
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 10진수 (1<=n<=1,000)
    scanf("%d", &n);
    
    recur(n); // 10진수 n이 입력되면 2진수로 변환하여 출력하는 재귀 함수
    
	return 0;
}