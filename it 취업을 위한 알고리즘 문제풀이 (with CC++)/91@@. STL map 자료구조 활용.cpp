#include <iostream>
#include <map>
#include <string>

int main()
{
    // 어떤 알파벳이 가장 많이 쓰였는가
    std::ios_base::sync_with_stdio(false); // 동기화 해제해서 cin, cout 속도 빠르게
    
    int n; // 입력 : 단어의 개수
    std::cin >> n;
    //std::map<char, int> ch; // 알파벳의 개수를 세기 위한 맵 선언
    //std::map<char, int>::iterator it; // @@@ map에 반복문으로 접근하기 위해서는 반복자가 필요함 @@@
    std::map<std::string, int> ch;
    std::map<std::string, int>::iterator it;
    
    
    // 단어를 세는 경우
    for(int i=0; i<n; i++)
    {
        char a[100]; // 단어를 읽을 배열
        std::cin >> a;
        
        ch[a]++; // 단어 자체를 map의 키로 정함
    }
    
    /* 알파벳을 세는 경우
    for(int i=0; a[i]!='\0'; i++)
    {
        ch[a[i]]++; // a[i]에 들어있는 문자로 map배열의 key에 접근해서 value 값을 증가시켜줌
    }*/
    
    int max=0; // 가장 많이 나온 개수
    std::string res;
    for(it=ch.begin(); it!=ch.end(); it++) // map의 처음에 접근해서 마지막에 가면 반복 끝
    {
        //std::cout << it->first << " " << it->second << "\n"; // 키와 값에 접근
        if(it->second > max) 
        {
            max = it->second; // value 값이 큰 걸 max에 넣음
            res = it->first; // max에 대응되는 key 값 넣음
        }
    } // @@@ 반복자로 접근 시 키 값이 오름차순으로 출력되게 됨 @@@
    
    std::cout << res << " : " << max << "\n";
    
    return 0;
}