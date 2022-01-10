#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(3<=n<=100)
    int pre; // 입력(이전 값 저장)
    
    scanf("%d", &n);
    std::vector<int> cnt(n); // 숫자 차 값 저장하는 배열
    
    scanf("%d", &pre); // 첫 값 저장
    for(size_t i=1; i<n; i++)
    {
        int now; // 현재 값 저장
        scanf("%d", &now);
        
        int tmp = pre -  now; // 차이 값 저장
        if(tmp < 0) // 차이 값 양수로 만듦
            tmp = -tmp;
        
        /*if(cnt[tmp]!=0 || tmp==0 || tmp>=n)
        {
            printf("NO");
            return 0;
        }
        ************************************/
        // @@@cnt에 없는 index 참조 가능해서 &&로 바꿈@@@
        if(tmp>0 && tmp<n && cnt[tmp]==0)// 반복문 나가서 또 체크 안해도됨
            cnt[tmp]++; // 배열에 차이 값 저장
        else // 절대 Jolly Jumpers가 될 수 없는 조건(중복, 범위 외)
        {
            printf("NO");
            return 0;
        }
        
        pre = now;
    }
    
    printf("YES");
    
	return 0;
}