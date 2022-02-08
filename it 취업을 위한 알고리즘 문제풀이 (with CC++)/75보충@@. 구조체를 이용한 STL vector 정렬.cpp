#include <iostream>
#include <vector>
#include <algorithm>
// pair는 두개 값이 한 쌍인 순서쌍을 나타냄
// 구조체를 이용하면 세개 이상 값을 한 쌍으로 나타낼 수 있음
    
struct Loc
{
    int x, y, z; // 멤버 변수
    // 구조체는 생성자(구조체 이름과 동일한 멤버 함수) 필요
    Loc(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    // 크기 비교 연산자 <를 연산자 오버로딩함
    bool operator<(const Loc &b)const // b를 레퍼런스로 받아서 원본 바꾸지 말라고 const
    { // @@@ 함수 헤더 뒤쪽에 const하면 상수 멤버함수가 돼서 멤버변수의 값들을 변경할 수 없음 @@@
        // return this->x<b.x; // x 값으로 비교
        // return this->x > b.x; // @@@ sort()사용 시 내림차순 정렬하게 됨 @@@ 
        
        if(this->x != b.x) return this->x < b.x; // x값이 다르면 x로 정렬
        else if(this->y != b.y) return this->y < b.y; // x값이 같고 y값이 다르면 y로 정렬
        else if(this->z != b.z) return  this->z < b.z; // x와 y값이 같고 z값이 다르면 z로 정렬
    }
};

int main() {
    // freopen("input.txt", "rt", stdin);
    
    std::vector<Loc> XYZ;
    XYZ.push_back(Loc(2, 3, 5)); // 구조체의 생성자를 통해 호출하면 생성자가 객체 생성
    XYZ.push_back(Loc(3, 6, 7));
    XYZ.push_back(Loc(2, 3, 1));
    XYZ.push_back(Loc(5, 2, 3));
    XYZ.push_back(Loc(3, 1, 6));
    
    // <연산자를 이용하여 정렬하게됨
    sort(XYZ.begin(), XYZ.end());
    
    for(auto pos : XYZ) 
        std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    
	return 0;
}