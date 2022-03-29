#include <iostream>

int arr[1001]; // 입력 : n개의 자연수로 이루어진 수열
int mem[1001]; // DP :인덱스의 값이 마지막 수열이라고 가정할 때의 최대 부분 수열의 길이
// DP는 최대 부분 수열의 길이가 한 번 값이 정해지면 변하지 않기때문에 성립함

int DP(int n)
{
    for(int i=2; i<=n; i++) // i가 수열의 마지막 인덱스 값이라고 가정한 상황
    {
        for(int j=1; j<i; j++) // j를 1부터 i-1까지 돌리면서 i가 가리키는 값이 j보다 크면 부분 증가수열을 만족한다.
        {
            if(mem[i]==0) mem[i]=1; // 일단 mem에 값 없으면 1로 초기화(0이 되면 안되므로) 
            if(arr[j]<arr[i] && mem[j]+1>mem[i]) mem[i]=mem[j]+1; // 부분 순열 중 길이가 가장 컸던 수+1
        }
        //std::cout << mem[i] << " ";
    }
    int max=0; // mem에 담겨있는 값 중에서 가장 최댓값이 부분증가수열의 최대 길이이다.
    for(int i=1; i<=n; i++)
    {
        if(max<mem[i]) max = mem[i];
    }
    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 입력되는 데이터 수(2<=n<=1,000)
    std::cin >> n;
    for(int i=1; i<=n; i++) std::cin >> arr[i];
    mem[1]=1; // 맨 처음은 숫자 하나밖에 없으므로 1을 넣어줌(아주 작은 단위)
    std::cout << DP(n);
    
    return 0;
}