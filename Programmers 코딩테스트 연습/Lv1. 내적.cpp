#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    for (int i = 0; i < a.size(); i++)
    {
        answer += a[i] * b[i];
    }

    return answer;
}
int main()
{
    //vector<string> tmp = { "N~F=0", "R~T>2" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    vector<int> num = { 4,7,12 };
    vector<int> num2 = { -1,0,2 };
    //string tmp = "right";
    //vector<vector<int> > tmp = { {1, 1, 1, 0},{1, 1, 1, 0},{0,0,0,1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };

    cout << solution(num, num2);
    //cout << v[0] << " " << v[1];

    return 0;
}