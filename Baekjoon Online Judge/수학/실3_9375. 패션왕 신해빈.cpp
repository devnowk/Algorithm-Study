#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int t; // 입력 : 테스트 케이스 개수(1<=t<=100)
    std::cin >> t;
    for(int i=0; i<t; i++)
    {
        int n; // 입력 : 의상의 수(0<=n<=30)
        std::cin >> n;
        if(n==0)
        {
            std::cout << 0 << "\n";
            continue;
        }
        int sum=1; // 출력 : 옷을 입는 경우의 수
        std::map<std::string, int> clothes; // <옷의 종류, 옷의 개수>
        std::map<std::string, int>::iterator it; // 맵의 반복자 미리 선언
        for(int j=0; j<n; j++)
        {
            std::string name, type; // 옷의 이름과 종류
            std::cin >> name >> type;
            clothes[type]++; // 옷의 종류 개수 ++ 해줌
        }
        // (type1 옷의 개수+1) * (type2 옷의 개수+1) 을 하면 알몸을 포함한 모든 옷을 입는 경우의 수가 됨(+1은 옷을 입지 않는 경우)
        for(it=clothes.begin(); it!=clothes.end(); it++) // 옷의 종류 수만큼 반복
        {
            sum*=(it->second+1);
        }
        std::cout << sum-1 << "\n";
    }
    
    return 0;
}