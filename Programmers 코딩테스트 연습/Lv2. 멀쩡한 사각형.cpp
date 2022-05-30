#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
}

long long solution(int w, int h) {
    long long answer = w * h;

    int gcd = GCD(w, h); // 가로 세로의 최대 공약수(겹치는 패턴의 개수)
    // 패턴의 세로 빈 칸은 h/gcd개, 가로는 두 칸일 가능성이 있는게 w/gcd-1개이다.
    answer -= (w + h - gcd);

    return answer;
}
int main()
{
    //vector<string> tmp = { "N~F=0", "R~T>2" };
    //vector<string> str = solution(tmp);
    //for (int i = 0; i < str.size(); i++) std::cout << str[i] << "\n";
    //vector<int> num = { 4,7,12 };
    //vector<int> num2 = { -1,0,2 };
    //string tmp = "right";
    //vector<vector<int> > tmp = { {1, 1, 1, 0},{1, 1, 1, 0},{0,0,0,1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };

    cout << solution(8, 12);
    //cout << v[0] << " " << v[1];

    return 0;
}