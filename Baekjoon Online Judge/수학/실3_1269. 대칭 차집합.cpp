#include<iostream>
#include<unordered_set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int a, b; // 입력 : a 원소의 개수, b 원소의 개수(1<=a, b<=200,000)
    int cnt = 0; // 출력 : a와 b의 대칭 차집합((a-b)U(b-a))
    std::unordered_set<int> as; // a의 원소
    std::unordered_set<int> bs; // b의 원소
    std::cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int tmp;
        std::cin >> tmp;
        as.insert(tmp);
    }
    for (int i = 0; i < b; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (as.find(tmp) != as.end())
        {
            as.erase(tmp); // as = a-b 만듦
            continue; // bs에도 넣지 않음 : 자동 bs = b-a
        }
        bs.insert(tmp);
    }
    cnt = as.size() + bs.size();
    std::cout << cnt;

    return 0;
}