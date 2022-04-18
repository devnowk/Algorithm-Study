#include <iostream>
#include <algorithm>
#include <vector>

struct Member // 회원의 나이와 이름 구조체
{
    int age; // 회원의 나이(1<=age<=200)
    std::string name; // 회원의 이름(알파벳 대소문자, length()<=100)
    Member(int a, std::string n) // 생성자
    {
        this->age=a;
        this->name=n;
    }
};

std::vector<Member> members; // 입력 : 회원들의 목록

bool compare(Member a, Member b)
{
    return a.age<b.age; // 나이 오름차순으로 정렬
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 가입한 회원 수
    std::cin >> n;
    for(int i=0; i<n; i++) 
    {
        int a;
        std::string s;
        std::cin >> a >> s;
        members.push_back(Member(a, s));
    }
    
    // 안정정렬 함수 : 기존의 순서를 유지한 채 compare 조건에 따른다.
    stable_sort(members.begin(), members.end(), compare);
    
    for(int i=0; i<n; i++)
    {
        std::cout << members[i].age << " " << members[i].name << "\n";
    }
    
    return 0;
}