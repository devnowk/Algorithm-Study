#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 작업의 개수(1<=n<=2,000)
    int k; // 입력 : 정전이 발생한 시간(1<=k<=2,000,000)
    int sum=0; // 총 작업 시간
    
    scanf("%d", &n);
    std::vector<int> a(n); // 입력 : 작업을 처리하는데 걸리는 시간(1,000이하)
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    scanf("%d", &k);
    
    int pos=0; // 출력 : 처리 중이던 작업 번호 가리킴
    int timer=0;
    while(sum > 0) // 남은 작업시간이 0이면 탈출
    {
        if(pos==n) pos=0; // 마지막 작업 다음은 처음 작업으로 설정
        
        if(timer == k && a[pos]>0) // 정전이 일어났을 때 다음 작업이 0보다 커야 pos가 답
            break;
            
        if(a[pos]==0) // 남은 작업이 없으면 다음 작업으로 넘어감
            pos++;
        else if(a[pos]>0)
        {
            a[pos]--; // 작업 처리
            timer++; // 시간 경과 
            pos++; // 한 번만 처리 후 다음으로 넘김
            sum--; // 총 작업 수에서 뺌
        }
    }
    if(sum==0) // @@@ while문 돌기 전에 k>=sum이면 -1 하고 끝내도 됨(정전 나기 전에 모두 끝남) @@@
        printf("-1");
    else
        printf("%d", pos+1);

	return 0;
}