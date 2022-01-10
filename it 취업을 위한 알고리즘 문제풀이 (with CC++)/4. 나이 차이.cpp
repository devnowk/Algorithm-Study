#include <iostream>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(2<=n<=100)
    int max=0, min=100; // 출력
    
    std::cin >> n;
    for(size_t i=0; i<n; i++)
    {
        int tmp;
        std::cin >> tmp;
        if(tmp > max)
            max = tmp;
        if(tmp < min)
            min = tmp;
    }
    std::cout << max - min;
	
	return 0;
}