#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0; // 터뜨려 사라진 인형의 개수

    stack<int> st; // 인형이 쌓이는 스택
    for (int i = 0; i < moves.size(); i++)
    {
        int col = moves[i] - 1; // 뽑을 열
        int row; // 뽑을 행
        for (int j = 0; j < board.size(); j++) // 가장 위에 있는 인형의 위치 찾기
        {
            if (board[j][col] > 0)
            {
                row = j;
                break;
            }
        }
        int num = board[row][col]; // 뽑을 인형
        if (num == 0) continue; // 뽑을 인형이 없으면 넘어감
        board[row][col] = 0; // 인형 뽑기

        if (st.empty()) st.push(num); // 비어 있으면 그냥 넣음
        else if (st.top() == num) // 맨 위에 스택에 있던 인형과 동일하면 터뜨림
        {
            answer += 2;
            st.pop();
        }
        else st.push(num);
    }

    return answer;
}
int main()
{
    //vector<string> tmp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    vector<int> num = { 1, 5, 3, 5, 1, 2, 1, 4 };
    //string tmp = "right";
    vector<vector<int> > tmp = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    cout << solution(tmp, num);

    return 0;
}