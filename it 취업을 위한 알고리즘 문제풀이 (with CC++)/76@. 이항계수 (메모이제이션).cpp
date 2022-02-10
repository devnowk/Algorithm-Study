#include <stdio.h>
#include <vector>

int ch[21][21]; // @@@ 메모이제이션 : 이미 구한 값을 중복 계산하지 않기 위해 저장해둠 @@@
int DFS(int n, int r) // 이항계수 공식 사용해서 이항계수 구하기
{
    if(r == 0 || n == r) return 1;
    else 
    {
        if(ch[n][r] == 0)
            ch[n][r] = DFS(n-1, r) + DFS(n-1, r-1); // 배열에 이항계수 구한 값 저장
        return ch[n][r];
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n, r; // 입력 : n개의 원소(1<=n<=20), r개를 뽑음(0<=r<=20)
    long long cnt; // 출력 : n개 중 r개를 뽑아 만드는 부분집합의 경우의 수(이항계수)
    scanf("%d %d", &n, &r);
    // nCr = n-1Cr + n-1Cr-1 공식 활용 n-1Cr은 한 명이 참여하지 않을 경우 n-1Cr-1는 한 명이 참여할 경우로 나눈 것
    cnt = DFS(n, r);

    printf("%lld", cnt);
    
	return 0;
}