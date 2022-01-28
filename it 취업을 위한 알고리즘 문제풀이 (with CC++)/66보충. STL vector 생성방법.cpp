#include <iostream>
#include <vector>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // int를 저장하는 빈 벡터(배열과 유사)를 생성(사이즈가 없음)
    std::vector<int> a;
    a.push_back(6); // 이 때 메모리에 공간이 할당됨
    a.push_back(8);
    a.push_back(11);
    std::cout << a.size() << std::endl; // 사이즈가 3이됨(가변적 배열)
    std::cout << a[1] << std::endl; // 8 출력
    
    // 빈 벡터가 아닌 사이즈가 5이고 원소 값이 0인 벡터 생성
    std::vector<int> b(5);
    b[1] = 5; // 사이즈가 없는 빈 벡터에 바로 접근해서 넣을 수는 없음
    std::cout << b[1] << std::endl;
    
    // 대괄호를 사용하면 빈 벡터 3개가 생성(2차원 배열과 유사)
    std::vector<int> c[3];
    c[0].push_back(1);
    c[0].push_back(3);
    c[0].push_back(5);
    c[1].push_back(2);
    c[1].push_back(4);
    c[1].push_back(6);
    c[2].push_back(7);
    std::cout << c[1][1] << std::endl;
    std::cout << c[2][0] << std::endl;
    
    // pair은 두 개짜리 공간 생성 first와 second 멤버 변수 사용 가능
    std::vector<std::pair<int, int> > graph[3]; // pair형 벡터 3개가 생성
    graph[1].push_back({3, 5}); // 중괄호의 초기화된 리스트형으로 넣을 수 있음
    graph[1].push_back({4, 7});
    graph[1].push_back({5, 9});
    graph[2].push_back(std::make_pair(7, 7));
    std::cout << graph[1][2].first << " " << graph[1][2].second << std::endl;
    
	return 0;
}