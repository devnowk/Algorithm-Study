#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(1<=n<=100)
    scanf("%d", &n);
    
    std::vector<int> a(n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    // 버블정렬 : 인접한 값을 비교하여 큰 값을 점점 뒤로 
    //            보내 맨 뒤에서부터 정렬됨(오름차순)
    for(int i=n-1; i>=1; i--) // j가 n-1번 반복 ----> 1번까지
    { //@@@ i를 무조건 0-n까지 돌리지 않아도됨 j기준일 경우@@@
        for(int j=0; j<i; j++)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
	return 0; 
}