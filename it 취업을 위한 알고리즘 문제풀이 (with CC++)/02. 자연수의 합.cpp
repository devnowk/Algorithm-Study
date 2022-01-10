#include <iostream>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int a, b; // 입력 : a~b 합을 수식과 함께 출력
    int sum=0; // 출력
    
    std::cin >> a >> b;
    
    for(size_t i=a; i<b; i++)
    {
        std::cout << i << " + ";
        sum+=i;
    }
    
    std::cout << b << " = " << sum+b;
	
	return 0;
}