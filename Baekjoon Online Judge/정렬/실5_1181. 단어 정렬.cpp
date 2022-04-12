#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::string a, std::string b) // 단어 정렬 조건 정하는 함수
{
    if(a.length()==b.length()) return a<b; // 두 단어의 길이가 같다면 사전 순으로 정렬
    return a.length()<b.length(); // 두 단어의 길이가 다르면 짧은 게 먼저
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 단어의 개수(1<=n<=20,000)
    std::cin >> n;
    std::vector<std::string> words; // 입력 : 입력 받은 단어들
    for(int i=0; i<n; i++) 
    {
        std::string str;
        std::cin >> str;
        words.push_back(str);
    }
    
    sort(words.begin(), words.end(), compare); // compare함수에 나와 있는 조건대로 정렬
    
    std::string tmp=""; // 이전 단어 기록 해놓기
    for(int i=0; i<n; i++)
    {
        if(tmp==words[i]) continue; // 이전 단어와 동일하면 무시
        tmp=words[i]; // 새 단어 담기
        std::cout << words[i];
    }
    
    return 0;
}