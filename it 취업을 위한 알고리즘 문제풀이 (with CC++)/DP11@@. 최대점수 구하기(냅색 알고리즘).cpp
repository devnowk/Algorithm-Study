#include <iostream>
#include <vector>
#include <algorithm>

int dp[101][1001];
//std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1)); // dp[i][j]의미 : i문제까지 j시간 안에 풀 수 있는 최대점수
std::vector<std::pair<int, int> > Question; // 문제 점수와 걸리는 시간 정보

int DFS(int i, int j)
{
    //std::cout << "DFS(" << i << ", " << j << ")" << std::endl;
    if(i==1) return dp[1][j]; // 1행이면 값 반환
    if(dp[i][j]>0) return dp[i][j]; // 이미 값이 들어 있으면 그거 반환
    
    int score = Question[i].first;
    int time = Question[i].second;
    
    if(j-time<0) return dp[i][j]=DFS(i-1, j); // j가 음수가 되면 확인 안함
    else return dp[i][j] = std::max(DFS(i-1, j), DFS(i-1, j-time)+score);
    //std::cout << " " << dp[i][j] << " ";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n, m; // 문제의 개수 n(1<=n<=100), 제한 시간 m(10<=m<=1000)
    std::cin >> n >> m;
    Question.push_back(std::make_pair(0,0)); // 한 칸 비워줌
    
    /* dp[n+1][m+1]의 최대 메모리 개수는 약 40만Byte 이상, 시간도 오래 걸림 -> 비효율적(값이 커지면 시간 초과할 수도 있음)
    std::vector<std::vector<int> > dp(n+1, std::vector<int>(m+1)); // dp[i][j]의미 : i문제까지 j시간 안에 풀 수 있는 최대점수
    for(int i=1; i<=n; i++)
    {
        int score, time; // 문제를 풀었을 때 점수와 걸리는 시간
        std::cin >> score >> time;
        
        for(int j=time; j<=m; j++) // 문제 푸는 시간은 넘겨야 점수를 얻을 수 있음
        {
            // 한 문제만 풀 수 있으므로 i-1 행의 값을 가져와서 비교해야 함
            dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-time]+score);
            //std::cout << dp[i][j] << " ";
        }
        //std::cout << std::endl;
    }
    std::cout << dp[n][m];
    */
    /* @@@ 뒤에서부터 거꾸로 구하면 dp[i-time]의 값을 참조해도 문제를 풀기 전이므로 두 개 이상 중복해서 푸는 일이 없음 @@@
    std::vector<int> dp(m+1); // dp[i]의미 : i초 일 때 풀 수 있는 최대 점수
    for(int i=1; i<=n; i++)
    {
        int score, time; // 문제를 풀었을 때 점수와 걸리는 시간
        std::cin >> score >> time;
        
        for(int j=m; j>=time; j--) // j를 m에서 time까지 거꾸로 계산
        {
            dp[j]=std::max(dp[j], dp[j-time]+score);
        }
    }
    std::cout << dp[m];
    위 방법으로 하면 첫 번째보다는 빠르지만 제한시간이 커질수록 느려짐*/ 
    
    // @@@ 개선된 냅색 알고리즘 @@@
    // 첫 번째 방법에서 이차원 배열 모두를 채울 필요 없이, DFS 방법으로 dp[i-1][j]와 dp[i-1][j-time]만 구한다.
    for(int i=1; i<=n; i++)
    {
        int score, time;
        std::cin >> score >> time; // 문제 점수와 걸리는 시간 입력
        Question.push_back(std::make_pair(score, time));
    }
    for(int i=Question[1].second; i<=m; i++) dp[1][i]=Question[1].first; // 1행 값 초기화
    
    std::cout << DFS(n, m);
    
    return 0;
}