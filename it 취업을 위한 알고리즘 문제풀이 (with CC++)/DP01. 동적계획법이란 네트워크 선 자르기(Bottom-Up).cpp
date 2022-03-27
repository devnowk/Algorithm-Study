#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false); // scanf, printf 사용 못함
    
    // 동적 계획법 : 아주 복잡한 문제를 직관적으로 풀 수 있을 정도의 문제로 작게 분해해서 해를 저장해둠
    //               조금 더 큰 문제의 해를 구해서 이전에 구했던 해와 관계식을 찾음
    //               최종 점화식을 구해서 문제의 답을 찾음 (Bottom-Up)
    
    // n미터의 선을 1m, 2m 길이로만 자를 때의 경우의 수
    // 1) 끝이 1m인 경우 -> n-1미터를 자르는 경우의 수
    // 2) 끝이 2m인 경우 -> n-2미터를 자르는 경우의 수
    // f(n) = f(n-2) + f(n-1) 식이 성립한다.
    
    int n; // 입력 : 네트워크 선의 총 길이(3<=n<=45)
    int mem[46]; // 메모이제이션, 답을 저장해둠
    
    std::cin >> n;
    mem[1]=1; mem[2]=2;
    for(int i=3; i<=n; i++)
    {
        mem[i] = mem[i-2] + mem[i-1]; // 점화식
    }
    
    std::cout << mem[n];
    
    return 0;
}