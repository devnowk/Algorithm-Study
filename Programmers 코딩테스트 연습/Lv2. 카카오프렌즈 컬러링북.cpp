#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0; // 영역의 개수
    int max_size_of_one_area = 0; // 영역의 최대 사이즈

    for (int i = 0; i < m; i++) // 행
    {
        for (int j = 0; j < n; j++) // 열
        {
            if (picture[i][j]==0) continue;

            // 각 칸을 BFS로 검사해서 같은 영역이면 -1로 값을 바꿈
            int num = picture[i][j]; // 칸의 값
            int area_size = 1; // 영역의 크기
            queue<pair<int, int> > q; // BFS 큐
            q.push(make_pair(i, j));
            picture[i][j] = 0;
            while (!q.empty())
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                //cout << row << " " << col << "\n";
                int dx[4] = { 0,0,-1,1 };
                int dy[4] = { 1,-1,0,0 };
                for (int k = 0; k < 4; k++) // 상하좌우 검사
                {
                    if (row + dy[k] < 0 || row + dy[k] >= m || col + dx[k] < 0 || col + dx[k] >= n) continue;
                    if (picture[row + dy[k]][col + dx[k]] == num) // 같은 숫자를 가지면 같은 영역
                    {
                        picture[row+dy[k]][col+dx[k]] = 0;
                        area_size++;
                        q.push(make_pair(row + dy[k], col + dx[k]));
                    }
                }
            }
            //cout << "\n";
            if (area_size > max_size_of_one_area) max_size_of_one_area = area_size;
            number_of_area++;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main()
{
    //vector<string> tmp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    vector<int> num = { 1, 5, 3, 5, 1, 2, 1, 4 };
    //string tmp = "right";
    vector<vector<int> > tmp = { {1, 1, 1, 0},{1, 1, 1, 0},{0,0,0,1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };

    vector<int> v = solution(6, 4, tmp);
    cout << v[0] << " " << v[1];

    return 0;
}