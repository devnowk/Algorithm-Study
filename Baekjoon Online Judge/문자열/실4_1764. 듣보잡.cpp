#include<iostream>
#include<string>
#include<unordered_set>
#include<set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    int n, m; // 입력 : 듣도 못한 사람 수 n, 보도 못한 사람 수 m(1<=n, m<=500,000)
    std::unordered_set<std::string> us; // 듣도 못한 사람 입력(정렬x)
    std::set<std::string> set; // 출력 : 듣도 보도 못한 사람(정렬)
    int cnt = 0; // 출력 : 듣도 보도 못한 사람 수

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        us.insert(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        if (us.find(tmp) != us.end())
        {
            set.insert(tmp);
            cnt++;
        }
    }
    std::cout << cnt << "\n";
    for (std::set<std::string>::iterator it = set.begin(); it!=set.end(); it++)
    {
        std::cout << *it << "\n";
    }

    return 0;
}