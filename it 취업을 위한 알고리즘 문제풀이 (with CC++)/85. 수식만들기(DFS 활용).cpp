#include <stdio.h>
#include <vector>

std::vector<int> v; // 입력 : 수열
int n; // 입력 : 수열의 개수(2<=n<=10)
int operNum[4]; // 입력 : 연산자의 개수 (덧셈, 뺄셈, 곱셈, 나눗셈 순서)
int max=0; // 출력 : 수식의 최댓값
int min=2147000000; // 출력 : 수식의 최솟값

void DFS(int L, int sum)
{
    //printf("DFS(%d, %d)\n", L, sum);
    if(L == n)
    {
        if(sum > max) max = sum;
        if(sum < min) min = sum;
        return;
    }
    
    if(operNum[0]>0) // 덧셈의 개수가 남아 있다면
    {
        operNum[0]--; // 개수-1
        DFS(L+1, sum+v[L]); // 덧셈을 선택하고 재귀
        operNum[0]++; // 재귀 끝나면 다시 덧셈 개수 올려줌
    }
    if(operNum[1]>0) // 뺄셈의 개수가 남아 있다면
    {
        operNum[1]--;
        DFS(L+1, sum-v[L]);
        operNum[1]++;
    }
    if(operNum[2]>0) // 곱셈의 개수가 남아 있다면
    {
        operNum[2]--;
        DFS(L+1, sum*v[L]);
        operNum[2]++;
    }
    if(operNum[3]>0) // 나눗셈의 개수가 남아 있다면
    {
        operNum[3]--;
        DFS(L+1, sum/v[L]); // 실수 처리 해줘야 한다면 해주기
        operNum[3]++;
    }
}

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    scanf("%d", &n);
    for(int i=0; i<n; i++) // 수열 입력 받기
    {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    for(int i=0; i<4; i++) // 연산자 개수 입력 받기
    {
        int a;
        scanf("%d", &a);
        operNum[i] = a;
    }
    
    DFS(1, v[0]); // 0번째 숫자는 무조건 더한 채로 시작함
    
    printf("%d\n%d", max, min);
    
    return 0;
}