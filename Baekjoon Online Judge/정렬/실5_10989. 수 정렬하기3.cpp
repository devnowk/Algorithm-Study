#include <iostream>
#include <vector>

int main()
{
    // 카운팅 정렬 : 숫자를 비교하지 않고 정렬할 수 있음, 단 숫자의 범위가 작아야 효율적
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // short를 사용하면 2Byte(약 65천개) 크기로 10000까지는 사용 가능
    int n; // 입력 : 정렬할 개수 (1<=n<=10,000,000)
    std::cin >> n;
    std::vector<int> count(10001); // 카운팅 정렬에 사용될 배열(count[i]의미 : i라는 숫자의 개수)
    // count의 값은 천만까지 가야하므로 int 써야함
    
    for(int i=0; i<n; i++) 
    {
        int tmp;
        std::cin >> tmp;
        count[tmp]++; // 받은 값의 개수를 카운팅에 대응해서 증가시킴
    }
    
    short i=0;
    while(i<=10000) // count의 전체를 돌면서 숫자의 개수만큼 출력함
    {
        if(count[i]==0) i++; // 없으면 다음 수로 넘어감
        else
        {
            std::cout << i << "\n";
            count[i]--; // 숫자 출력하면 개수 한 개 줄임
        }
    }
    
    return 0;
}