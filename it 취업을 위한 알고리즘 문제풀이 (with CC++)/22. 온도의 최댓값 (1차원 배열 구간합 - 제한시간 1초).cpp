#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(온도를 측정한 전체 날짜 수)
    int k; // 입력(합을 구하기 위한 연속적인 날짜 수)
    // int arr[100000]; // 매번 십만 번씩 잡으면 메모리 낭비
    int max; // 출력(연속적인 k일 온도 합 최대값)
    int sum=0; // k일 합(빼고 더하며 반복문 실행)
   
    scanf("%d %d", &n, &k);
    std::vector<int> arr(n); // 입력(온도 집합, 동적할당)
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=0; i<k; i++) // sum값 k일 만큼 더해놓음
        sum += arr[i];
    max = sum;
    
    for(int i=0; i+k<n; i++)
    {// arr[i]값을 빼고 arr[i+k]값을 더해줘야 함
        sum -= arr[i];
        sum += arr[i+k];
        // i+k가 배열의 마지막일 때까지 반복
        
        if(sum > max)
            max = sum;
    }
    
    printf("%d", max);
    
	return 0;
}