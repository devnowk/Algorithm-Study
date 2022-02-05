#include <stdio.h>
#include <vector>
#include <queue>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n, k; // 입력 : 왕자 수 n(5<=n<=1,000), 제외할 번호 k(2<=k<=9)
    scanf("%d %d", &n, &k);
    std::queue<int> Q; // 왕자들을 빼고 넣고 할 큐
    int cnt=0; // k번째 세는 변수
    
    for(int i=1; i<=n; i++) Q.push(i); // 왕자들을 모두 큐에 넣음
    while(Q.size()!=1) // 마지막 한 명이 남을 때까지 반복
    {
        cnt++;
        if(cnt==k) // k번째가 되면 왕자 제거함
        {
            cnt=0;
            Q.pop();
        }
        else // k번째가 아니면 맨 뒤로 보냄
        {
            Q.push(Q.front()); // 맨 앞에 있는 걸 맨 뒤로 보냄
            Q.pop();
        }
    }
    printf("%d", Q.front());
     
	return 0;
}