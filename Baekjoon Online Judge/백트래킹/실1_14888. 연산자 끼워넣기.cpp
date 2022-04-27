#include <iostream>
#include <vector>

int n; // 입력 : 수의 개수(2<=n<=11)
int oper[4]; // 입력 : 연산자의 개수(각각 덧셈, 뺄셈, 곱셈, 나눗셈)
int min=1000000000, max=-1000000000; // 출력 : 연산 결과 최솟값, 최댓값
std::vector<int> num; // 입력 : 연산할 숫자들(1<=num[i]<=100)

void DFS(int idx, int sum)
{
    if(idx==n)
    {
        // 최대, 최솟값 갱신
        if(sum>max) max=sum;
        if(sum<min) min=sum;
        return;
    }
    for(int i=0; i<4; i++)
    {
        if(oper[i]==0) continue;
        oper[i]--; // 연산자 하나 사용
        if(i==0) DFS(idx+1, sum+num[idx]); // 덧셈 적용
        if(i==1) DFS(idx+1, sum-num[idx]); // 뺄셈 적용
        if(i==2) DFS(idx+1, sum*num[idx]); // 곱셈 적용
        if(i==3 && num[idx]!=0) DFS(idx+1, sum/num[idx]); // 나눗셈 적용(분모 0이면 안됨)
        oper[i]++; // DFS 끝나면 다음 탐색을 위해 다시 더해줌
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        int tmp;
        std::cin >> tmp;
        num.push_back(tmp);
    }
    for(int i=0; i<4; i++) std::cin >> oper[i];
    
    DFS(1, num[0]); // 0번째 수를 총 합으로 놓고 1번 째 수 사이의 연산자 구하기
    
    std::cout << max << "\n" << min;
    
    return 0;
}