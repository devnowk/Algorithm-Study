#include<iostream>
#include<map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::map<int, bool> map; // 입력 : 상근이 숫자 카드
    int n; // 입력 : 상근이가 가진 카드 개수(1<=n<=500,000)
    std::cin >> n;
    for(int i=0; i<n; i++) 
    {
        int tmp;
        std::cin >> tmp;
        map[tmp]=true;
    }
    int m; // 입력 : 확인할 카드 개수
    std::cin >> m;
    for(int i=0; i<m; i++)
    {
        int tmp;
        std::cin >> tmp;
        if(map[tmp]) std::cout << 1 << " ";
        else std::cout << 0 << " ";
    }

    return 0;
}
