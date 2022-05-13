#include<iostream>
#include<unordered_map>
#include<unordered_set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m; // 입력 : 집합s의 개수 n, 검사하는 문자 개수 m(1<=n, m<=10,000)
    int sum = 0; // 출력 : 집합s에 포함된 문자열의 개수
    
    std::unordered_set<std::string> us; // 집합 s를 저장하는 set(us은 정렬을 하지 않음, 해슁 테이블 형태, 키만 저장)
    std::unordered_map<std::string, bool> um; // 집합 s를 저장하는 map(um은 정렬을 하지 않음, 트리 형태, 키와 값 저장)

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        us.insert(tmp);
        um[tmp] = true;
    }
    for (int i = 0; i < m; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        //if (um[tmp]) sum++; // 이미 true로 되어 있으면 s에 포함된다는 뜻
        if (us.find(tmp) != us.end()) sum++; // us에서 반복자가 찾다가 끝까지 못찾으면 us.end가리키게 됨
    }
    std::cout << sum;

    return 0;
}