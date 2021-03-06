// #include <iostream>
#include<bits/stdc++.h> // 모든 스탠다드 라이브러리 파일 포함 c++14(GCC컴파일러), 컴파일 타임이 늘어남
// 백준 문제(+보통 채점 사이트)는 런타임 시간을 채점함. 위 헤더 파일은 컴파일 타임에 일어나므로 상관 X

int main()
{
    // 입력과 출력을 사용할 때, 원래 동기화를 함(cin, cout 표준 스트림 버퍼와 printf, scanf 표준 스트림 버퍼를 병행해서 사용)
    std::ios_base::sync_with_stdio(false); // 동기화를 해제시켜서, c++표준 스트림만 사용함, 훨씬 빨라짐
    std::cin.tie(NULL); // cin, cout 사용하는 버퍼 묶음을 해제시켜 조금만 더 빠르게 만든다.
    
    int n, min = 2147000000;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i=0; i<n; i++) std::cin >> a[i];
    
    for(auto x : a) std::cout << x << " "; // for-each 구문 c++14이상
    
    return 0;
}