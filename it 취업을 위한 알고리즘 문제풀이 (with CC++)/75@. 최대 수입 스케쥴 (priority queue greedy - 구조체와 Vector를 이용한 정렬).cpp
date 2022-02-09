#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

// 클래스는 정보의 은닉, 상속 가능 구조체는 가벼운 느낌
struct Company // 기업의 강연료와 강연료 정보
{
    int money; // 입력 : 강연료 (1<=m<=10,000)
    int deadline; // 입력 : 강연 기한(1<=d<=10,000)
    
    Company(int m, int d) // 생성자
    {
        this->money = m;
        this->deadline = d;
    }
    
    bool operator <(const Company &b) const
    {
        return this->deadline > b.deadline;
    }
};

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 강연 요청한 기업의 수(1<=n<=10,000)
    scanf("%d", &n);
    int sum=0; // 출력 : 최대 강연료

    std::vector<Company> v;
    for(int i=0; i<n; i++)
    {
        int m, d;
        scanf("%d %d", &m, &d);
        v.push_back(Company(m, d)); // 생성자 호출시 메모리에 Company형(int 두 개) 생김
    }
    sort(v.begin(), v.end()); // 강연기한을 기준으로 내림차순
    std::priority_queue<int> pQ; 
    // 강연 기한이 많이 남은 일부터 강연료를 모두 push하고 가장 높은 강연료 하나를 pop하는 큐
    
    // @@@ 기간이 많은 날부터 어떤 강의를 할 지 정해야 한다.
    // 기간보다 높은 날의 강의는 할 수 없지만 반대는 가능하기 때문이다. @@@
    int day = v[0].deadline; // 강연 날짜 정하는 변수(기간이 제일 많은 날)
    int i=0; // v에 접근하는 변수
    while(day > 0) // 강연날짜가 남아있으면 반복
    {
        if(v[i].deadline == day) // 강연 날짜가 데드라인에 해당이 되면 강연료 모두 큐에 push
        {
            pQ.push(v[i].money);
            i++;
        } else // 강연 날짜가 데드라인에 해당이 안되면(더 작으면) 최대 강연료 pop함
        {
            if(!pQ.empty())
            {
                sum += pQ.top();
                pQ.pop();
            }
            day--; // 큐가 비어있어도 날짜는 감소해야함
        }
    }
    printf("%d", sum);
    
	return 0;
}