#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    vector<bool> win(46, false);
    int cnt = 0; // 최대 정답 갯수
    int zero = 0; // 0의 갯수
    
    for(int i=0; i<6; i++)
    {
        // 정답 배열 등록
        int num = win_nums[i];
        win[num] = true;
        
        // 민우 번호 0개 갯수 등록
        if(lottos[i] == 0) zero++;
    }
    
    for(int i=0; i<6; i++)
    {
        int minwoo = lottos[i];
        if(win[minwoo] == true) cnt++; // 민우가 갖고 있는 번호가 정답번호면 cnt늘려줌 
    }
    
    answer[1] = 7-cnt; // 7에서 정답 개수 빼면 등수임, 최소 등수 먼저 등록
    
    cnt+=zero; // 0의 갯수만큼 정답 번호 갯수 늘려줌
    if(cnt > 6) cnt = 6; // 최대 정답 개수는 6
    answer[0] = 7-cnt; // 최고 등수 등록
    
    if(answer[0] == 7) answer[0] = 6;
    if(answer[1] == 7) answer[1] = 6;
    
    return answer;
}