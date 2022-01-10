#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    // 선택정렬 : 가장 작은 수부터 선택하여 맨 앞에 배치(오름차순)
    int n; // 입력(1<=n<=100)
    scanf("%d", &n);
    
    std::vector<int> a(n); // 출력(오름차순으로 정렬할 배열)
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    for(int i=0; i<n; i++) // n-2까지만 돌아도됨
    {
        int minIdx = i; // 가장 작은 값의 인덱스
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[minIdx])
                minIdx = j;
        }
        int tmp = a[i];
        a[i] = a[minIdx];
        a[minIdx] = tmp;
        
        printf("%d ", a[i]);
    }
    
	return 0; 
}