#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 좌표의 개수(1<=n<=1,000,000)
    std::cin >> n;
    std::vector<int> v(n); // 입력되는 숫자
    std::vector<int> vSort(n); // v벡터가 정렬된 벡터
    std::map<int, int> count; // 자신보다 작은 값이 저장돼있는 맵
    for(int i=0; i<n; i++) std::cin >> v[i];
    vSort = v;
    sort(vSort.begin(), vSort.end());
    
    count[vSort[0]]=0; // 제일 낮은 수 먼저 등록
    for(int i=1; i<n; i++) // 0번째 수는 무조건 0이므로 그 다음부터 진행
    {
        if(vSort[i]!=vSort[i-1]) // 이전 값과 현재 값이 달라야 함
            count[vSort[i]]=count[vSort[i-1]]+1; // 이전 값의 +1
    }
    
    for(int i=0; i<n; i++) 
    {
        std::cout << count[v[i]] << " ";
    }
    
    return 0;
}