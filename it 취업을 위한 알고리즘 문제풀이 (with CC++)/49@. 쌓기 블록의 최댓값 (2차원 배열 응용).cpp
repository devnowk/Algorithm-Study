#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 블록의 크기 n*n (3<=n<=10)
    scanf("%d", &n);
    int sum=0; // 출력 : 블록의 최대 개수
    
    int front[10], side[10];
    for(int i=0; i<n; i++)
        scanf("%d", &front[i]);
    for(int i=n-1; i>=0; i--)
        scanf("%d", &side[i]); 
    // 1 1 2 3이 들어오면 3이 a의 1행을 검사하고 2가 a의 2행, 1이 3행, 1이 4행
    // 이렇게 거꾸로 계산한다. 따라서 배열을 거꾸로 받아야 나중에 계산이 쉬워짐
    
    std::vector<std::vector<int> > a(n, std::vector<int>(n, 9));
    // 블록을 최대로 쌓아서 깎는 식으로 진행 (9로 초기화)
    // @@@ 정면 블록을 쌓는 걸로 시작해도 됨 @@@
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // a[i][j] = front[j] 로 초기화 해도됨
            if(a[i][j] > front[j]) // 정면 블록은 열을 검사
                a[i][j] = front[j]; // 정면 블록 수를 넘으면 거기에 맞춤
            if(a[i][j] > side[i]) // 옆면 블록은 행을 검사
                a[i][j] = side[i]; // 옆면 블록 수를 넘으면 거기에 맞춤
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+= a[i][j];
            //printf("%d ", a[i][j]);
        }
        //printf("\n");
    }
    
    printf("%d", sum);
    
	return 0;
}