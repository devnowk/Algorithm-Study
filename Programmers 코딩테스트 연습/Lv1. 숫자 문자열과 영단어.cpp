#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;

    unordered_map<string, int> number; // 문자열과 해당 숫자가 들어 있는 맵
    number["zero"] = 0;
    number["one"] = 1;
    number["two"] = 2;
    number["three"] = 3;
    number["four"] = 4;
    number["five"] = 5;
    number["six"] = 6;
    number["seven"] = 7;
    number["eight"] = 8;
    number["nine"] = 9;

    int idx = 0; // 문자열 s 검사하는 인덱스
    string str = ""; // 임시 문자열
    while (idx < s.length())
    {
        if (isdigit(s[idx])) answer = answer * 10 + (s[idx++] - '0'); // 검사한 값이 숫자면 바로 answer에 넣어줌
        else if (number.count(str) == 0)// 검사한 값이 문자면 맵에 해당되는 문자열이 될때까지 str에 문자 추가
        {
            str += s[idx++];
        }
        if (number.count(str) == 1) // 맵에 해당되는 문자열이 있으면 str초기화하고 answer에 넣어줌
        {
            answer = answer * 10 + number[str];
            str = "";
        }

    }

    return answer;
}

int main()
{
    //vector<string> tmp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    string tmp = "one4seveneight";
    cout << solution(tmp);

    return 0;
}