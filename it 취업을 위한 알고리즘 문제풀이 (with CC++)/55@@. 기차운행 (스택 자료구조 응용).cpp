#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 기차의 개수(3<=n<=30)
    //int a[31]; // 입력 : 기차의 원래 순서
    
    std::stack<int> s; // 자기 순서가 아닌 기차는 집어넣는 스택
    std::vector<char> v; // 출력 : @@@ PO기억하는 배열 - Impossible 때문에 필요 @@@
    int cnt=1; // B도시로 들어가야하는 기차 번호
    
    scanf("%d", &n);
    
    /*******************경우의 수가 복잡함**************
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    
    int i=1;
    while(cnt<=n) // B로 가야하는 순서가 n까지 가야함
    {
        if(!s.empty() && s.top() == cnt) // 스택에 있는 기차가 나갈 순서이면 먼저 꺼냄
        {
            s.pop();
            v.push_back('O');
            cnt++; // 순서 증가
        } else if(i<=n) // 스택에는 나갈 게 없고 a에서 꺼내올 게 있다면
        {
            s.push(a[i]); // 스택에 넣음
            v.push_back('P');
            i++;
        } else // a에서 꺼낼 것도 없고 스택에 있는 기차가 나갈 수도 없으면
        {
            printf("impossible");
            return 0;
        }
    }
    ***************************************************/
    for(int i=1; i<=n; i++) // 바로 입력 받아서 스택에 넣음
    { // @@@ 입력 받은 걸 무조건 집어넣어서 경우의 수를 최대한 간단히 @@@
        int tmp;
        scanf("%d", &tmp);
        s.push(tmp); // 바로 교차로로 이동함
        v.push_back('P'); // 벡터에 P 기억함
        
        while(1)
        {
            if(s.empty()) break; // 스택이 비었으면 빠져나감
            if(s.top() == cnt) // 스택에 숫자가 있고 그게 나갈 순서라면 계속 뺌
            {
                s.pop();
                cnt++;
                v.push_back('O');
            } else break; // 순서가 아니라면 빠져나감
        }
    }
    if(!s.empty()) // 스택에 숫자가 아직 남아있다면 불가능
    {
        printf("impossible");
        return 0;
    }
    
    for(int j=0; v.size(); j++) // 벡터의 사이즈만큼 반복
        printf("%c", v[j]); // 블록 안씌울거면 i쓰면 안됨
    
	return 0;
}
