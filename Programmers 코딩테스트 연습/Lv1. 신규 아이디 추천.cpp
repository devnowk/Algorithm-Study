#include <string>
#include <vector>

using namespace std;
char tmp[1001]; // 고친 비밀번호를 넣을 문자열

string solution(string new_id) {
    string answer = "";
    
    int idx=-1; // tmp의 인덱스 담당
    bool flag=false; // 연속된 마침표 체크
    
    for(int i=0; new_id[i]!='\0'; i++)
    {
        char c = new_id[i];

        if('A'<=c && c<='Z') c+=32; // 대문자면 소문자로 변경
        if(!(('a'<=c && c<='z') || (48<=c && c<=57) || c=='-' || c=='_' || c=='.')) continue; // 소문자, 숫자, 빼기, 밑줄, 마침표 외에 제거
        if(c=='.')
        {
            if(flag) continue; // 바로 전에 마침표였으면 이번 것은 제거
            if(idx == -1) continue; // 맨 처음 마침표는 제거, @@@ 맨 뒤 마침표는 인덱스 번호 모르므로 마지막에 처리 @@@
            flag = true;
        } else if(flag) flag = false; // 마침표 아니면 다시 false
        tmp[++idx] = c; // 검사한 문자를 tmp에 넣는다.
    }

    if(tmp[idx] == '.') idx--; // 마지막에 마침표 있으면 뺌
    if(idx==-1) 
    {
        tmp[0] = 'a'; // 빈 문자열이면 a 대입
        idx = 0;
    }
    if(idx >= 15) 
    {
        idx = 14; // 16자리를 넘어가면 15자리까지만 기록
        if(tmp[idx] == '.') idx--; // 마지막에 마침표 있으면 뺌
    }
    
    for(int i=0; i<=idx; i++) answer.push_back(tmp[i]); // answer에 문자 하나씩 넣음
    
    if(idx<=1) // 2자리 이하일 경우
    {   
        char c = tmp[idx]; // 마지막 값
        while(idx!=2)
        {
            idx++;
            answer.push_back(c);
        }
    }
    
    return answer;
}
