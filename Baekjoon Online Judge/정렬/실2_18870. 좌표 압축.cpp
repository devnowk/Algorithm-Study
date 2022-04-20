#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 좌표의 개수(1<=n<=1,000,000)
    std::cin >> n;
    std::vector<int> v(n); // 입력되는 숫자
    std::vector<int> vSort(n); // v벡터가 정렬된 벡터
    //std::map<int, int> count; // 자신보다 작은 값이 저장돼있는 맵
    for(int i=0; i<n; i++) std::cin >> v[i];
    vSort = v;
    sort(vSort.begin(), vSort.end());
    vSort.erase(unique(vSort.begin(), vSort.end()), vSort.end()); // unique함수는 중복된 수들을 뒤로 모아줌 -> 뒷부분만 삭제 해주면 됨
    
    for(int i=0; i<n; i++) 
    {
        std::cout << lower_bound(vSort.begin(), vSort.end(), v[i])-vSort.begin() << " ";
    }
    
    return 0;
}