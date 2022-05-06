#include<iostream>

int sum[26][2001]; // sum[i][j] : i번째 문자(i : asckii code-97)의 문자열 j번째까지 누적 개수
int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::string str; // 입력 : 문자열(str.length()<=2,000)
    int q; // 입력 : 질문의 수(q<=2,000)
    std::cin >> str >> q;
    
    for(int i=1; i<=str.length(); i++)
    {
        int idx=str[i]-97; // a~z => 0~25
        for(int j=i-1; j>=0; j++)
        {
            if(sum[idx][j]>0)
                sum[idx][i]=sum[idx][i-1]+1; // 이전 값에서 하나 더해야 누적 개수가 됨
        }
    }
    for(int i=0; i<q; i++)
    {
        char a; // 입력 : 찾는 문자
        int l, r; // 입력 : 찾을 구간
    }


    return 0;
}
