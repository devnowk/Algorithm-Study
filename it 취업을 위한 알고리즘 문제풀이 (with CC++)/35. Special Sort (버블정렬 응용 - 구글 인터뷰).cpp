#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(5<=n<=100)
    scanf("%d", &n);
    
    std::vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    // 음의 정수와 양의 정수 순서를 바꾸지 않고 나누기
    // 선택정렬은 서로 떨어져 있는 숫자를 바꾸기 때문에 적절X
    // 버블정렬은 인접한 숫자를 서로 바꾸기 때문에 순서를 바꾸지 않않고
    for(int i=n-1; i>=1; i--)
    {
        for(int j=0; j<i; j++)
        { // 반복문 한 번 돌면 맨 뒤 숫자가 양수가 됨
            if(arr[j] > 0 && arr[j+1] < 0)
            { // 앞 숫자가 양수고 바로 뒤가 음수일 때 바꿈
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    
	return 0; 
}