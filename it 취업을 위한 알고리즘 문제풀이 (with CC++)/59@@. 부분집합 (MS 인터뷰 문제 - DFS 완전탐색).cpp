#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int n; // 입력(1<=n<=10)
int ch[11]; // 출력 : 부분집합에 포함되면 1 아니면 0 넣는 배열

void Subset(int x) // 부분집합 구하는 함수
{
    if(x==n+1) // 재귀함수 종료지점
    {
        for(int i=1; i<=n; i++)
        { // 1이면 부분집합에 포함되있으므로 원소 출력
            if(ch[i] == 1)
                printf("%d ", i);
        } 
        // printf("\n");
        puts(""); // 줄바꿈
    }else 
    { // @@@ 공유되는 배열의 값에 따라 동일한 자식을 호출해도 다른 경우를 따질 수 있음 @@@
        ch[x]=1; // 부분집합에 포함한 다음에
        Subset(x+1); // 왼쪽 자식노드 호출
        ch[x]=0; // 부분집합에서 제외한 다음에
        Subset(x+1); // 오른쪽 자식노드 호출
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);
    // @@@ 어떤 원소가 부분집합에 참여하는 지 여부를 트리로 만듦 @@@
    // 예를 들어, root노드의 왼쪽은 1이 포함, 오른쪽은 1이 제외되는 경우
    // 이 트리를 전위순회한다.
    Subset(1);
    
    
	return 0;
}