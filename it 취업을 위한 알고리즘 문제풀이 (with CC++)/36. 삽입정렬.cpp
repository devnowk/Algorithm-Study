#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(1<=n<=100)
    scanf("%d", &n);
    
    std::vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
        
    // 삽입정렬 : 1번째 숫자부터 앞과 비교하여 자기 자리 찾아서 삽입
    for(int i=1; i<n; i++) // 0번째는 정렬된거로 봄(i-1까지는 모두 정렬된 것)
    { 
        int j; // 삽입할 위치 기억해야 함
        int tmp = arr[i];
        for(j=i-1; j>=0; j--)
        {
            if(tmp < arr[j]) // 왼쪽에 있는 수가 tmp보다 더 크면
                arr[j+1] = arr[j]; // j를 i있는 방향으로 땡김
                // 원래 j+1에 있던 수는 tmp나 그 다음에 저장돼있음
            else // i가 더 크면
                break;
        }
        arr[j+1] = tmp;
    }
    
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    
	return 0; 
}