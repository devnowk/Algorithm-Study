#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 수열 a의 크기(1<=n<=1,000)
    std::cin >> n;
    std::vector<int> a(n); // 입력 : 수열 a(1<=a[i]<=1,000)
    std::vector<int> dp1(n, 1); // dp1[i] : i번째 수가 부분 수열의 끝일 때 LIS 개수(좌측부터 계산)
    std::vector<int> dp2(n, 1); // dp2[i] : i번째 수가 부분 수열의 처음일 때 LDS 개수(우측부터 계산)
    for(int i=0; i<n; i++) std::cin >> a[i];
    
    // LIS 구하기(Longest Increase Subsequence)
    for(int i=0; i<n; i++) // i번째 수가 수열의 끝이라고 가정
    {
        int max=1; // i 이전에 계산됐던 가장 큰 LIS 수
        for(int j=0; j<i; j++) // i가 수열의 끝이므로 j는 i 전까지 검사
        {
            if(a[j]<a[i] && dp1[j]+1>max) max=dp1[j]+1; 
        }
        dp1[i]=max;
        //std::cout << dp1[i] << " ";
    }
    // LDS 구하기(Longest Decrease Subsequence)
    for(int i=n-1; i>=0; i--) // i번째 수가 수열의 처음이라고 가정
    {
        int max=1; // i 이전에 계산됐던 가장 큰 LDS 수
        for(int j=n-1; j>i; j--) // i가 수열의 처음이므로 j는 i 이후까지 검사
        {
            if(a[j]<a[i] && dp2[j]+1>max) max=dp2[j]+1; 
        }
        dp2[i]=max;
        //std::cout << dp2[i] << " ";
    }
    
    // i의 왼쪽에 존재하는 LIS와 i의 오른쪽에 존재하는 LDS 값을 더하고 i는 두 번 더해졌으므로 1개를 빼면 바이토닉 수열의 길이
    int max=0; // 출력 : 가장 긴 바이토닉 수열의 길이
    for(int i=0; i<n; i++)
    {
        int tmp=dp1[i]+dp2[i]-1;
        if(tmp > max) max=tmp;
    }
    std::cout << max;
    
    return 0;
}