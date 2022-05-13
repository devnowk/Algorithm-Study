#include<iostream>
#include<string>
#include<unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m; // 입력: 포켓몬의 수 n, 문제의 개수 m (1<=n, m<=100,000)
    std::unordered_map<std::string, int> name; // 포켓몬의 이름이 key
    std::unordered_map<int, std::string> idx; // 포켓몬의 인덱스 값이 key
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        name[tmp] = i;
        idx[i] = tmp;
    }
    for (int i = 0; i < m; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        if (std::isdigit(tmp[0]))
        {
            int i = std::stoi(tmp);
            std::cout << idx[i] << "\n";
        }
        else
        {
            std::cout << name[tmp] << "\n";
        }
    }

    return 0;
}