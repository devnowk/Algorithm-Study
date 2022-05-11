#include<iostream>
#include<map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);std::cout.tie(NULL);
    
    int n, m; // 입력 : 집합s의 개수 n, 검사하는 문자 개수 m(1<=n, m<=10,000)
    int sum=0; // 출력 : 집합s에 포함된 문자열의 개수
    std::map<std::string, bool> map; // 집합 s를 저장하는 맵
    std::cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        map[tmp]=true;
    }
    for(int i=0; i<m; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        if(map[tmp]) sum++; // 이미 true로 되어 있으면 s에 포함된다는 뜻
    }
    std::cout << sum;
    
    return 0;
}
