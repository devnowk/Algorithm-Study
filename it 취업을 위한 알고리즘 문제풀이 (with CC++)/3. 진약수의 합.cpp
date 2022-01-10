#include <iostream>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(3<=n<=100)
    int sum=1; // 출력 : n의 진약수의 합
    
    std::cin >> n;
    std::cout << "1"; // 마지막 수를 알 수 없으므로 1을 먼저 찍어줌
    
    for(size_t i=2; i<n; i++)
    {
        if(n%i==0)
        {
            std::cout << " + " << i;
            sum += i;
        }
    }
    
    std::cout << " = " << sum;
	
	return 0;
}