#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

// @@@ 배열의 이진 트리- 왼쪽 자식(부모*2), 오른쪽 자식(부모*2+1) @@@
// 깊이우선탐색 - 연결된 노드 하나를 끝까지 방문

void Preorder(int x) // 루트 먼저
{
    if(x>7) return; // 종료 조건 : 7까지만 순회
    else
    {
        printf("%d ", x); // 루트 먼저 출력
        Preorder(x*2); // 왼쪽 자식트리 출력
        Preorder(x*2+1); // 오른쪽 자식트리 출력
    }
}

void Inorder(int x) // 왼쪽 다음 루트
{
    if(x>7) return; // 재귀 종료 지점
    else
    {
        Inorder(x*2); // 왼쪽 먼저 호출
        printf("%d ", x);
        Inorder(x*2+1);
    }
}

void Postorder(int x) // 왼쪽 오른쪽 다음 루트
{
    if(x>7) return; // 재귀 종료 지점
    else
    {
        Postorder(x*2); // 왼쪽 먼저
        Postorder(x*2+1); // 오른쪽 다음
        printf("%d ", x); // 루트 마지막
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    Preorder(1); // 전위순회 : 루트 먼저 순회한다. 
    printf("\n");
    Inorder(1); // 중위순회 : 왼쪽 순회 후 루트 순회
    printf("\n");
    Postorder(1); // 후위순회 : 왼쪽 오른쪽 순회 후 루트 순회
    
    
	return 0;
}