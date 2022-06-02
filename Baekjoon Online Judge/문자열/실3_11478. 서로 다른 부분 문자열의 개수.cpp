#include <iostream>
#include <unordered_set>

std::string s; // 입력 : 문자열 s(알파벳 소문자, 길이 1,000이하)
std::string tmp; // DFS에서 검사하는 문자 저장소
std::unordered_set<std::string> us; // 부분 문자열 저장

void DFS(int idx, int end) // 현재 어디서부터 반복 돌려야 하는지(idx)
{
	if (tmp.length() == end)
	{
		us.insert(tmp);
		return;
	}
	for (int i = idx; i < s.length(); i++)
	{
		tmp += s[i];
		DFS(idx + 1, end);
		tmp.pop_back(); // DFS 돌린 후 끝 값 빼기
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL); std::cin.tie(NULL);

	std::cin >> s;
	int cnt = 0; // 출력 : 서로 다른 부분 문자열의 개수

	for (int i = 1; i <= s.length(); i++) // 탐색할 개수
	{
		for (int j = 0; j <= s.length() - i; j++)
		{
			std::string tmp = s.substr(j, i); // j번째부터 i개 문자 추출
			us.insert(tmp);
		}
	}

	cnt = us.size(); // 최종적으로 us의 개수가 부분 문자열의 개수가 된다.
	std::cout << cnt;

	return 0;
}