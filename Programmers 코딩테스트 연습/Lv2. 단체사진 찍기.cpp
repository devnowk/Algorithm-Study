#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<char, int> arr; // 순열 맵(이름과 인덱스 저장)
vector<char> names(8); // 프렌즈 이름
vector<bool> visit(8); // A,C,F,J,M,N,R,T 방문 체크
vector<string> data_copy; // 입력받은 조건들
int answer; // 조건에 맞는 경우의 수

bool Condition() // 입력받은 조건에 맞는지 확인
{
    bool check = true;
    for (int i = 0; i < data_copy.size(); i++)
    {
        string tmp = data_copy[i];
        char p1 = tmp[0], p2 = tmp[2]; // 거리를 구할 두 사람 이름
        char oper = tmp[3]; // 연산자
        int dis = (tmp[4]-48) + 1; // 거리조건(원래 조건은 사이의 사람 수를 센 것이므로 거리는 +1 해줘야 함)
        int real_dis = abs(arr[p1] - arr[p2]);

        switch (oper)
        {
        case '=':
            if (real_dis != dis) check = false;
            break;
        case '>':
            if (real_dis <= dis) check = false;
            break;
        case '<':
            if (real_dis >= dis) check = false;
            break;
        }
    }
    return check;
}

void DFS(int idx)
{
    if (idx == 8)
    {
        //for (int i = 0; i < 8; i++) cout << arr[i] << " ";
        //cout << "\n";
        if (Condition()) answer++; // 현재 순열(arr)이 조건에 맞으면 ++

        return;
    }
    // 중복되지 않는 순열 구하기
    for (int i = 0; i < 8; i++)
    {
        if (!visit[i]) // 방문한 적이 없을 때 순열에 넣을 수 있음
        {
            arr[names[i]] = idx;
            visit[i] = true;
            DFS(idx + 1);
            visit[i] = false; // 방문 후에는 체크 해제
        }
    }
}

int solution(int n, vector<string> data) {
    // 전역변수 초기화
    answer = 0;
    arr.clear();
    names = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    visit.assign(20, false);
    data_copy = data;

    DFS(0); // 0번째 값 정하기

    return answer;
}
int main()
{
    vector<string> tmp = { "N~F=0", "R~T>2" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    vector<int> num = { 1, 5, 3, 5, 1, 2, 1, 4 };
    //string tmp = "right";
    //vector<vector<int> > tmp = { {1, 1, 1, 0},{1, 1, 1, 0},{0,0,0,1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };

    cout << solution(2, tmp);
    //cout << v[0] << " " << v[1];

    return 0;
}