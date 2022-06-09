#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = ""; // 완주하지 못한 선수

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++) // participant로 하면 completion OutOfRange됨
	{
		if (participant[i] != completion[i]) // 정렬 후 다른 값이면 그게 답
		{
			answer = participant[i];
			break;
		}
	}

	if (answer == "") answer = participant[participant.size() - 1];
	return answer;
}
int main()
{
	vector<string> t1 = { "leo", "kiki", "eden" };
	vector<string> t2 = { "eden", "kiki" };
	cout << solution(t1, t2);

	return 0;
}