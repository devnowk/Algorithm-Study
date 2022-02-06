#include <stdio.h>
#include <vector>
#include <queue>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // 최대힙 : priority_queue로 구현 가능
    // 큐와 동일하게 앞쪽에 있는 걸 빼고 뒤로 넣음
    // 부모 노드에 있는 수가 자식 노드보다 커야함
    
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
                printf("%d\n", pQ.top()); // 우선순위 큐의 루트 값은 top
                pQ.pop(); 
                // 루트 노드가 빠지고 동시에 말단 노드가 루트 자리로 이동하면서 맥스힙 구조를 다시 만듦
            }
        }else pQ.push(a); // 자연수가 입력되면 큐에 넣음
    }
     
	return 0;
}