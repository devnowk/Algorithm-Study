#include <iostream>
#include <map>

int main()
{
    // 어떤 알파벳이 가장 많이 쓰였는가
    std::ios_base::sync_with_stdio(false); // 동기화 해제해서 cin, cout 속도 빠르게
    
    std::map<char, int> ch; // 알파벳의 개수를 세기 위한 맵 선언
    // @@@ map에 반복문으로 접근하기 위해서는 반복자가 필요함 @@@
    std::map<char, int>::iterator it; // map의 반복자 선언
    char a[100]; // 단어를 읽을 배열
    std::cin >> a;
    
    for(int i=0; a[i]!='\0'; i++)
    {
        ch[a[i]]++; // a[i]에 들어있는 문자로 map배열의 key에 접근해서 value 값을 증가시켜줌
    }
    
    for(it=ch.begin(); it!=ch.end(); it++) // map의 처음에 접근해서 마지막에 가면 반복 끝
    {
        std::cout << it->first << " " << it->second << "\n"; // 키와 값에 접근
    } // @@@ 반복자로 접근 시 키 값이 오름차순으로 출력되게 됨 @@@
    
    return 0;
}