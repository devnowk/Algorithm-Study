#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> left_idx = { 3, 0 };// 왼쪽 손의 초기 위치
    pair<int, int> right_idx = { 3, 2 };// 오른쪽 손의 초기 위치

    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i]; // 누를 숫자
        if (number == 1 || number == 4 || number == 7) // 왼손으로 누르고 왼손 위치 바꿔줌
        {
            answer += 'L';
            left_idx = { number / 3, 0 };
        }
        else if (number == 3 || number == 6 || number == 9) // 오른손 누르고 위치 바꿔줌
        {
            answer += 'R';
            right_idx = { number / 3 - 1, 2 };
        }
        else // 가운데 열의 숫자를 누를 경우 두 손 중 가까운 손 선택
        {
            pair<int, int> numXY = { number / 3, 1 }; // 숫자의 위치 저장
            if (number == 0) numXY = { 3, 1 };

            int lt_dis = abs(numXY.first - left_idx.first) + numXY.second - left_idx.second;
            int rt_dis = abs(numXY.first - right_idx.first) + right_idx.second - numXY.second;
            if (lt_dis > rt_dis) // 오른쪽 손이 더 가까우면 오른손으로 누르고 위치 바꿈
            {
                answer += 'R';
                right_idx = { numXY.first, numXY.second };
            }
            else if (lt_dis < rt_dis) // 왼쪽 손이 더 가까우면 왼손으로 누르고 위치 바꿈
            {
                answer += 'L';
                left_idx = { numXY.first, numXY.second };
            }
            else // 두 손의 위치가 같다면 어느 손잡인지에 따름
            {
                if (hand == "right")
                {
                    answer += 'R';
                    right_idx = { numXY.first, numXY.second };
                }
                else
                {
                    answer += 'L';
                    left_idx = { numXY.first, numXY.second };
                }
            }
        }
    }

    return answer;
}
int main()
{
    //vector<string> tmp = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    vector<int> num = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string tmp = "right";
    cout << solution(num, tmp);

    return 0;
}