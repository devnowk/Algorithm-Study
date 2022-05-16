#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.length() / 2; i++) // 문자 길이의 반 초과로 쪼개면 쪼개는 의미가 없음
    {
        string str = ""; // 문자열 압축 결과

        // 문자 i개로 쪼갠 배열
        vector<string> tok;
        for (int j = 0; j < s.length(); j += i)
            tok.push_back(s.substr(j, i)); // 문자 쪼개서 벡터에 넣음(개수 초과시 있는 것만 넣음)

        //for(int j=0; j<tok.size(); j++) cout << tok[j] << " ";
        //cout << "\n";

        int cnt = 1; // 동일한 문자열이 몇 개 있는지
        int idx = 0; // 기준이 될 tok문자
        for (int j = 1; j < tok.size(); j++) // tok들을 하나씩 확인
        {
            if (tok[idx] == tok[j]) cnt++; // 같은 문자면 숫자 늘림
            else // 다른 문자면 이전 문자 넣어주고 idx바꾸기
            {
                if (cnt > 1) str += to_string(cnt) + tok[idx];
                else str += tok[idx];
                idx = j;
                cnt = 1;
            }
        }
        if (cnt > 1)str += to_string(cnt) + tok[idx];
        else str += tok[idx];
        //cout << str << " ";
        if (str.length() < answer) answer = str.length();
    }

    //if (s.length() == 1) answer = 1;
    return answer;
}

int main()
{
    //vector<string> tmp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    string tmp = "aabbaccc";
    cout << solution(tmp);

    return 0;
}