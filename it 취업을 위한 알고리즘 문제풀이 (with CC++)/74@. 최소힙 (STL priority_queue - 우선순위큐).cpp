#include <stdio.h>
#include <vector>
#include <queue>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // 최소 힙 : 부모 노드가 자식 노드의 값보다 작음
    // @@@ 부호를 반대로 붙이면 우선순위 큐를 통해 최소 힙 구현 가능 @@@
    
    std::priority_queue<int> pQ; // 최대힙 구현하는 우선순위 큐
    int a;

    while(true)
    {
        scanf("%d", &a);
        if(a==-1) break; // -1이 입력되면 종료
        else if(a==0) // 0이 입력되면 최댓값을 꺼내어 출력
        {
            if(pQ.empty()) printf("-1\n"); // 큐가 비어있으면 -1 출력
            else
            {
                printf("%d\n", -pQ.top()); // 우선순위 큐의 루트 값은 top
                pQ.pop(); 
                // 루트 노드가 빠지고 동시에 말단 노드가 루트 자리로 이동하면서 맥스힙 구조를 다시 만듦
            }
        }
        else pQ.push(-a); // 자연수가 입력되면 큐에 넣음
    }
    
	return 0;
}