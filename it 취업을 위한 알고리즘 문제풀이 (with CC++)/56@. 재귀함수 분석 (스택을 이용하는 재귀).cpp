#include <stdio.h>
#include <vector>
#include <stack>

// 재귀함수 - 스택 프레임에 호출되는 정보를 기록함
// 1. main()의 매개변수, 지역변수, 복귀주소 저장
// 2. recursive(3)의 매개변수 n=3, 지역변수, 복귀주소 - main의 30라인 저장
// 3. recursive(2)의 매개변수 n=2, 지역변수, 복귀주소 - recursive(3)의 19라인 저장
// 스택에 더 이상 저장할 수 없으면 stack overflow

void recursive(int n)
{
    // @@@ 재귀함수는 반드시 종료 조건이 필요함 @@@
    //if(n > 1) recursive(n-1); // 1보다 크면 재귀호출
    
    if(n == 0) return; // 0이면 종료하고 ( 종료 지점 명시 )
    else // 종료지점이 아니면 계속 뻗어나감
    {
        recursive(n-1);
        printf("%d ", n); // 재귀호출 끝나면 n출력
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 자연수(1<=n<=20)
    scanf("%d", &n);
    
    recursive(n); // 1부터 n까지 자연수를 출력
      
	return 0;
}
