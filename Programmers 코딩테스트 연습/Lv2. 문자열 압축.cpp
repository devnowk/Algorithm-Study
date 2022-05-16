#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 2147000000;
    for (int i = 1; i <= s.length() / 2; i++) // 문자 길이의 반 초과로 쪼개면 쪼개는 의미가 없음
    {
        string str = ""; // 임시 저장 문자열
        string tmp = s.substr(0, i); // 처음 기준 문자열 변수

        int cnt = 1; // 동일한 문자열이 몇 개 있는지
        for (int j = i; j + i <= s.length(); j += i) // 문자열 끝까지 검사함
        {
            string a = s.substr(j, i); // 다음 문자열 자름
            if (tmp.compare(a) == 0) // 기준 문자열과 동일한 문자열이 나오면
            {
                cnt++;
            }
            else if (tmp.compare(a) != 0)// 다른 문자열이면
            {
                if (cnt > 1) // 이전에 연속인 문자열이 있었다는 뜻
                {
                    str.append(to_string(cnt)); // 문자 개수 추가
                    str.append(tmp); // 기준 문자 추가
                    cnt = 1;
                    tmp = a;
                }
                else if (cnt == 1) // 이전에 연속인 문자가 없었으면
                {
                    str.append(tmp); // 한 개 이므로 숫자 없이 문자만 추가
                    tmp = a;
                }
            }
            if (j + i + i > s.length()) // 반복문의 마지막일 때, str에 넣지 않은 문자 넣기
            {
                if (cnt > 1) str.append(to_string(cnt)); // 연속인 문자가 있었으면 숫자 넣어줌
                str.append(tmp);
            }
        }
        if (s.length() % i != 0) // 쪼개는 수가 나누어 떨어지지 않으면 남는 문자들 한 번에 넣음
        {
            string tmp = s.substr(s.length() - s.length() % i, s.length() % i);
            str.append(tmp);
        }
        //cout << str << " ";
        if (str.length() < answer) answer = str.length();
    }

    if (s.length() == 1) answer = 1;
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