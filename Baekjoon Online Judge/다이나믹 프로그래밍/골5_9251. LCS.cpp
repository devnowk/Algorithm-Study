#include <iostream>
#include <vector>

int dp[1001][1001]; // dp[i][j] : str1 i번째까지와 str2 j번째문자까지 중 LCS 개수
// ACAYKP, CAPCAK dp[4][2] : ACAY와 CA의 LCS 개수
int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::string str1, str2; // 입력 : LSC(Longest Common Subsequence)를 구할 두 문자열
    std::cin >> str1 >> str2;
    int size1 = str1.length(), size2 = str2.length(); // 두 문자열의 길이 저장
    
    for(int i=1; i<=size1; i++)
    {
        for(int j=1; j<=size2; j++)
        {
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1; // 같은 문자이면 바로 전에 구했던 LCS+1
            // AC와 CAPC의 C가 같을 때, C가 없었던 A와 CAP의 LCS+1을 하는 것임
            else dp[i][j]=std::max(dp[i-1][j], dp[i][j-1]); // 다른 문자이면 한 문자씩 없을 때 구했던 LCS+1
            // ACA와 CAPC가 다를 때, AC-CAPC와 ACA-CAP의 LCS를 비교하여 큰 쪽을 따라감
        }
    }
    std::cout << dp[size1][size2];
    
    return 0;
}