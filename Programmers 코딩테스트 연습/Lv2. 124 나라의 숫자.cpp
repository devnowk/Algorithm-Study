#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";

    while (n != 0) // n이 0일 때까지 계속 나눔
    {
        if (n % 3 == 0)
        {
            answer.insert(0, 1, '4'); // 0번째 인덱스에 '4' 1개 넣음
            n /= 3;
            n--; // n이 나누어 떨어질 때 몫을 하나 더 빼줘야 맞는 규칙
        }
        else if (n % 3 == 1)
        {
            answer.insert(0, 1, '1');
            n /= 3;
        }
        else
        {
            answer.insert(0, 1, '2');
            n /= 3;
        }
    }

    return answer;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

    cout << solution(42);

	return 0;
}
