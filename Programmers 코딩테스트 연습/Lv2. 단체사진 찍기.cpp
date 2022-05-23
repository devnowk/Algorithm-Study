#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<char, int> name; // 프렌즈 이름
vector<int> arr(8); // 인덱스는 각 프렌즈 이름을 가리키고 값은 위치를 가리킴
vector<string> data_copy; // 입력받은 조건들

bool Condition() // 입력받은 조건에 맞는지 확인
{
    bool check = true;
    for (int i = 0; i < data_copy.size(); i++)
    {
        string tmp = data_copy[i];
        char p1 = tmp[0], p2 = tmp[2]; // 거리를 구할 두 사람 이름
        char oper = tmp[3]; // 연산자
        int dis = (tmp[4] - 48) + 1; // 거리조건(원래 조건은 사이의 사람 수를 센 것이므로 거리는 +1 해줘야 함)
        int real_dis = abs(arr[name[p1]] - arr[name[p2]]);

        if (oper == '=' && real_dis != dis) check = false;
        else if (oper == '>' && real_dis <= dis) check = false;
        else if (oper == '<' && real_dis >= dis) check = false;
    }
    return check;
}


int solution(int n, vector<string> data) {

    // 전역변수 초기화
    data_copy = data;
    for (int i = 0; i < 8; i++) arr[i] = i;
    name = { {'A',0}, {'C',1}, {'F',2}, {'J',3}, {'M',4}, {'N',5}, {'R',6}, {'T',7} };

    int answer = 0; // 조건에 맞는 경우의 수
    do
    {
        if (Condition()) answer++;

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