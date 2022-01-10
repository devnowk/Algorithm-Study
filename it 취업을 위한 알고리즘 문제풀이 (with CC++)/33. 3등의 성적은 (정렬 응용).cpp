#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(1<=n<=100)
    int cnt=1; // 등수 세기(동일한 점수는 같은 등수)
    scanf("%d", &n);
    
    std::vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
        
    for(int i=0; i<n-1; i++) // 선택정렬로 정렬 해놓기
    {
        int maxIdx = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] > arr[maxIdx])
                maxIdx = j;
        }
        int tmp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = tmp;
    }
    
    for(int i=1; i<n; i++)
    {
        if(arr[i-1] != arr[i]) // 전의 값과 다르다면
            cnt++; // 2등, 3등인 것임
        if(cnt == 3) // 3등이면
        {
            printf("%d", arr[i]);
            break;
        }
    }
    
	return 0; 
}