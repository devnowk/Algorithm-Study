#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;

    for (int i = 0; i < numbers.size(); i++)
    {
        answer -= numbers[i];
    }

    return answer;
}

int main()
{
    //vector<string> tmp = { "N~F=0", "R~T>2" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    vector<int> num = { 1,2,3,4,6,7,8,0 };
    //string tmp = "right";
    //vector<vector<int> > tmp = { {1, 1, 1, 0},{1, 1, 1, 0},{0,0,0,1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };

    cout << solution(num);
    //cout << v[0] << " " << v[1];

    return 0;
}