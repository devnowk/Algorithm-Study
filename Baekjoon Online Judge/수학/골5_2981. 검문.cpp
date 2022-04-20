#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) // 유클리드 알고리즘 - 최대공약수 구하기
{
    if(b==0) return a;
    return gcd(b, a%b); // a와 b의 최대공약수는 b와 a%b의 최대공약수와 같음
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 숫자의 개수(2<=n<=100)
    std::cin >> n;
    std::vector<int> v(n); // 입력 : 숫자 목록(1<=v[i]<=1,000,000,000)
    for(int i=0; i<n; i++) std::cin >> v[i];
    sort(v.begin(), v.end());
    
    // 모든 수의 나머지가 같은 m은 인접수를 뺀 값들의 최대공약수의 약수이다.
    int max=v[1]-v[0]; // 인접수의 최대공약수 
    for(int i=2; i<n; i++) // 최대공약수 구하기
    {
        max = gcd(max, v[i]-v[i-1]);
    }

    std::vector<int> divisor;
    for(int i=2; i*i<=max; i++) // 약수 구하기
    {
        if(max%i==0)
        {
            divisor.push_back(i);
            if(i!=max/i) divisor.push_back(max/i); // 대응되는 약수 값도 넣기
            //std::cout << i << " " << max/i << " ";
        }
    }
    divisor.push_back(max); // 자기 자신 넣기(1과 대응되는데 1은 없으므로)
    sort(divisor.begin(), divisor.end());
    
    for(int i=0; i<divisor.size(); i++) std::cout << divisor[i] << " ";
    
    return 0;
}