#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 진약수의 개수(1<=n<=50)
    std::cin >> n;
    std::vector<int> v(n); // 입력 : 진약수 목록(2<=v[i]<=1,000,000)
    int min=1000001, max=0; // 진약수의 최솟값과 최댓값
    for(int i=0; i<n; i++)
    {
        std::cin >> v[i];
        if(v[i]>max) max=v[i];
        if(v[i]<min) min=v[i];
    }
    std::cout << max*min;

    return 0;
}