#include<iostream>

int sum[26][200001]; // sum[i][j] : i번째 문자(i : asckii code-97)의 문자열 j번째까지 누적 개수
int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::string str; // 입력 : 문자열(str.length()<=2,000)
    int q; // 입력 : 질문의 수(q<=2,000)
    std::cin >> str >> q;
    
    for(unsigned int i=1; i<=str.length(); i++) // i-1번째 문자의 누적 개수 저장
    {
        int idx=str[i-1]-97; // a~z => 0~25
        for(int j=0; j<26; j++) // 모든 알파벳 행 다 검사
        {
            if(j==idx) sum[j][i]=sum[j][i-1]+1; // 해당 알파벳에 +1
            else sum[j][i]=sum[j][i-1]; // 나머지는 전 값과 동일
        }
    }
    for(int i=0; i<q; i++)
    {
        char a; // 입력 : 찾는 문자
        int l, r; // 입력 : 찾을 구간
        std::cin >> a >> l >> r;
        std::cout << sum[a-97][r+1]-sum[a-97][l] << "\n"; // 누적 값이므로 5번째에서 0번째 빼면 1~5 사이 누적 값 나옴
    }


    return 0;
}
