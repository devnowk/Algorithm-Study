#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string> > m; // 신고 내역 저장할 map
map<string, int> singo; // 신고자가 메일을 받을 수

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    int num = id_list.size(); // 사람들 수
    
    for(int i=0; i<report.size(); i++) // 신고 내역 정리
    {
        string p1, p2;
        for(int j=0; j<report[i].size(); j++) // report의 문자열 자르기
        {
            int tmp = report[i].find(" ");
            p1 = report[i].substr(0, tmp); // 신고자
            p2 = report[i].substr(tmp+1); // 신고 당한 사람
        }
        
        bool flag = false; // 중복 신고인지 확인하는 변수
        for(int j=0; j<m[p2].size(); j++)
        {
            if(m[p2][j] == p1) flag = true; // 이미 신고 되어 있으면 true
        }
        if(!flag) m[p2].push_back(p1); // 신고 되어 있지 않을 때만 추가함, 신고 당한 사람을 기준으로 신고자를 추가함
    }
    
    for(int i=0; i<num; i++)
    {
        if(m[id_list[i]].size() >= k) // 신고내역이 기준치를 넘으면 신고자의 메일 증가시킴
        {
            for(int j=0; j<m[id_list[i]].size(); j++)
            {
                string p = m[id_list[i]][j]; // 신고자의 이름 가져옴 
                singo[p]++; // 신고자의 메일 숫자 증가시킴
            }
        }
    }
    
    // singo에 신고자와 메일 숫자가 나와있음 id_list 순서대로 정렬만 하면됨
    for(int i=0; i<num; i++)
    {
        answer.push_back(singo[id_list[i]]);
    }
    
    return answer;
}