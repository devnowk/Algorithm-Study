#include <iostream>
#include <vector>

std::vector<int> mem(101, 1); // 모두 1로 초기화
std::vector<int> arr(101); // 입력 : 번호 정보

int DP(int n) // 겹치지 않게 선 연결하기 위해서는 가장 오름차순 되는 순열이 많아야 함
{
    for(int i=2; i<=n; i++) // 가장 마지막 숫자 인덱스를 i로 가정
    {
        for(int j=1; j<i; j++)
        {
            if(arr[i]>arr[j] && mem[j]+1>mem[i]) mem[i]=mem[j]+1; // 부분증가 순열이 되는 것 중 값이 가장 큰 것+1
        }
    }
    int max=0; // mem 중에 값이 가장 큰 것
    for(int i=1; i<=n; i++)
    {
        if(max<mem[i]) max=mem[i];
    }
    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    // 겹치지 않게 선 연결 => 최대 증가수열의 개수 문제와 동일함
    int n;
    std::cin >> n;
    for(int i=1; i<=n; i++) std::cin >> arr[i];
    
    std::cout << DP(n);
    
    return 0;
}