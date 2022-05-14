#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 기존 채팅방에 남아있는 이름도 바뀜
vector<string> solution(vector<string> record) {
    vector<string> answer; // 최종적으로 보게 되는 문자열 배열
    unordered_map<string, string> um; // 유저 아이디-닉네임
    vector<string> order(100000), id(100000), nickname(100000); // 주문, 아이디, 닉네임

    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        ss >> order[i];
        ss >> id[i];
        ss >> nickname[i];

        // 새 닉네임 변경, 새로 들어옴
        if (order[i] == "Enter" || order[i] == "Change")
        {
            um[id[i]] = nickname[i];
        }
    }
    for (int i = 0; i < record.size(); i++)
    {
        string tmp = um[id[i]]; // 최종 바뀐 닉네임
        if (order[i] == "Enter") tmp += "님이 들어왔습니다.";
        else if (order[i] == "Leave") tmp += "님이 나갔습니다.";
        else continue;
        answer.push_back(tmp);
    }

    return answer;
}

int main()
{
    vector<string> tmp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    vector<string> str = solution(tmp);
    for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";

    return 0;
}