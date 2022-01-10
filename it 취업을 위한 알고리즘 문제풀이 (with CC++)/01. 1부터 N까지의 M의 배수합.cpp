#include <iostream>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n, m; // 입력 : 1-n 중 m의 배수의 합
    int sum=0; // 출력
    
    std::cin >> n >> m;
    
    for(size_t i=0; i<=n; i++)
    {
        if(i%m == 0)
            sum+=i;
    }
	
	std::cout << sum;
	
	return 0;
}