#include <iostream>
#include <vector>

int main()
{
    // 카운팅 정렬 : 숫자를 비교하지 않고 정렬할 수 있음, 단 숫자의 범위가 작아야 효율적
    std::ios_base::sync_with_stdio(false);
    
    // short를 사용하면 2Byte(약 65천개) 크기로 10000까지는 사용 가능
    int n; // 입력 : 정렬할 개수 (1<=n<=10,000,000)
    std::cin >> n;
    std::vector<short> arr(n); // 입력 : 정렬할 숫자 배열
    std::vector<short> res(n); // 출력 : 정렬된 결과 배열
    std::vector<short> count(10001); // 카운팅 정렬에 사용될 배열(count[i]의미 : i라는 숫자의 개수)
    // count의 값은 천만까지 가야하므로 int 써야함
    
    for(int i=0; i<n; i++) 
    {
        std::cin >> arr[i];
        count[arr[i]]++; // 받은 값의 개수를 카운팅에 대응해서 증가시킴
    }
    for(short i=1; i<10001; i++) count[i]+=count[i-1]; // 카운팅의 개수를 누적으로 바꿈(count[i]의미 : i숫자가 정렬 될 때, count[i]-1번째로 들어가게 됨) 
    for(int i=n-1; i>=0; i--)
    {
        short num=arr[i]; // 정렬할 수
        short p=count[num]-1; // 넣을 위치
        res[p]=num; // 넣을 위치에 숫자를 넣음
        count[num]--; // 한 번 넣으면 개수 줄임
    }
    
    for(int i=0; i<n; i++) std::cout << res[i] << "\n";
    
    return 0;
}