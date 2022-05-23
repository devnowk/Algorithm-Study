#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool Condition(int dis, int real_dis, char oper) // 입력받은 조건에 맞는지 확인
{
    if (oper == '=' && real_dis != dis) return false;
    else if (oper == '>' && real_dis <= dis) return false;
    else if (oper == '<' && real_dis >= dis) return false;

    return true;
}


int solution(int n, vector<string> data) {

    vector<int> arr(8); // 인덱스는 각 프렌즈 이름을 가리키고 값은 위치를 가리킴
    string name = "ACFJMNRT";
    int answer = 0; // 조건에 맞는 경우의 수

    for (int i = 0; i < 8; i++) arr[i] = i;

    do
    {
        bool check = true;
        for (int i = 0; i < n; i++)
        {
            char p1 = data[i][0], p2 = data[i][2]; // 거리를 구할 두 사람 이름
            char oper = data[i][3]; // 연산자
            int dis = (data[i][4] - '0') + 1; // 거리조건(원래 조건은 사이의 사람 수를 센 것이므로 거리는 +1 해줘야 함)
            int real_dis = abs(arr[name.find(p1)] - arr[name.find(p2)]);

            if (!Condition(dis, real_dis, oper)) check = false;
        }
        if (check) answer++;
    } while (next_permutation(arr.begin(), arr.end()));

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