#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> command = commands[i];
        vector<int> tmp;
        for (int j = command[0] - 1; j < command[1]; j++)
        {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[command[2] - 1]);
    }

    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int> > commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };

    vector<int> answer = solution(array, commands);

    for (int i=0; i<answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
