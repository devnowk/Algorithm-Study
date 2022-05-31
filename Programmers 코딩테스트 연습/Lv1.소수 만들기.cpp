#include <vector>
#include <iostream>
using namespace std;

int answer;
int arr[3]; // 이전 값 알기 위한 배열
bool check[51]; // 방문하면 true
vector<int> n;

bool IsPrime(int num) // 소수 판정
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

void DFS(int idx, int sum)
{
    if (idx > 3)
    {
        //cout << sum << " ";
        if (IsPrime(sum)) answer++;
        return;
    }
    for (int i = arr[idx - 1]; i < n.size(); i++) // 이전 인덱스 값부터 돌림
    {
        if (!check[i])
        {
            arr[idx] = i; // 현재 인덱스 저장
            check[i] = true;
            DFS(idx + 1, sum + n[i]);
            check[i] = false;
        }
    }
}

int solution(vector<int> nums) {
    answer = 0;
    n = nums;

    arr[0] = 0;
    DFS(1, 0); // 첫 번째 숫자를 고름, 숫자의 합은 sum

    return answer;
}

int main()
{
    vector<int> nums = { 1, 2, 3, 4 };

    cout << solution(nums);

    return 0;
}