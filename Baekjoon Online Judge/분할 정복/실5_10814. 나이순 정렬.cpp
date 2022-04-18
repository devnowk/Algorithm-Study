#include <iostream>
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
std::vector<Member> tmp; // 병합할 때 정렬에 이용하는 임시 벡터
void MergeSort(int left, int right)
{
    int mid=(left+right)/2; // 분할 기준
    if(left<right) // 분할이 가능하면 계속 분할
    {
        MergeSort(left, mid);
        MergeSort(mid+1, right);
    }
    // 정렬 순서에 맞게 병합하는 과정
    int p1=left, p2=mid+1, p3=left;
    while(p1<=mid && p2<=right) // p1과 p2 둘 중 한 쪽이 모두 정렬될 때까지 반복
    {
        if(members[p1].age==members[p2].age) // 나이가 같으면 가입한 순으로 정렬
        {
            tmp[p3++]=members[p1++]; // 가입한 순서는 p1이 무조건 빠름(가입순서로 입력된 것이므로)
        }else // 나이가 같지 않으면 나이 순서로(오름차순)
        {
            if(members[p1].age<members[p2].age) tmp[p3++]=members[p1++];
            else tmp[p3++]=members[p2++];
        }
    }
    while(p1<=mid) tmp[p3++]=members[p1++];
    while(p2<=right) tmp[p3++]=members[p2++];
    for(int i=left; i<=right; i++) members[i]=tmp[i]; // 정렬된 걸로 업데이트
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 가입한 회원 수
    std::cin >> n;
    members.reserve(n);
    tmp.reserve(n);
    for(int i=0; i<n; i++) 
    {
        int a;
        std::string s;
        std::cin >> a >> s;
        members.push_back(Member(a, s));
    }
    MergeSort(0, n-1); // 0번째부터 n-1번째 사람까지 병합정렬을 통해 정렬한다.
    
    for(int i=0; i<n; i++)
    {
        std::cout << members[i].age << " " << members[i].name << "\n";
    }
    
    return 0;
}