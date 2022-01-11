#include <stdio.h>
#include <vector>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n, m; // 입력 : 배열의 크기(1<=n, m<=100)
    
    scanf("%d", &n);
    std::vector<int> a(n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    scanf("%d", &m);
    std::vector<int> b(m);
    for(int i=0; i<m; i++)
        scanf("%d", &b[i]);
    
    std::vector<int> res(n+m); // 출력 : 배열 a, b를 오름차순으로 합친 배열
    
    /*****************************************************************
    int i=0, j=0; // 각각 a, b배열의 값을 가리키는 변수

    for(int k=0; k<n+m; k++)
    {
        if(i==n) // a가 모두 res에 들어가면 b 남은 걸 한 번에 집어 넣음
        {
            res[k] = b[j];
            j++;
        } else if(j==m) // b가 모두 res에 들어가면 a 남은 걸 한 번에 집어 넣음
        {
            res[k] = a[i];
            i++;
            // res[k] = a[i++]; // @@@ 이 문장으로 한 번에 가능 @@@
        } else if(a[i] < b[j])
        {
            res[k] = a[i]; // 작은 수를 먼저 넣고
            i++; // a에서 그 다음 값을 가리킴
        } else
        {
            res[k] = b[j];
            j++;
        }
        printf("%d ", res[k]);
    }
    *****************************************************************/
    
    int i=0, j=0; // 각각 a, b배열의 값을 가리키는 변수
    int k=0;
    
    while(i<n && j<m) // while문을 사용해서 가능
    {
        if(a[i] < b[j])
            res[k++] = a[i++];
        else
            res[k++] = b[j++];
    }
    // @@@ 한 번에 쓸어 담기 - while문 조건 맞는 게 아무거나 들어감 @@@
    while(i<n) res[k++] = a[i++]; // a가 남았으면 여기가 참이돼서 다 쓸어 담음
    while(j<m) res[k++] = b[j++]; // b가 남았으면 여기가 참이돼서 다 쓸어 담음
    
    for(int i=0; i<k; i++)
        printf("%d ", res[i]);
	
	return 0;
}