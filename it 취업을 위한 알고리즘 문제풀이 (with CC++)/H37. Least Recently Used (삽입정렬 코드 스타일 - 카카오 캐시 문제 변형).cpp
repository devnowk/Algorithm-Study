#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int s; // 입력 : 캐시의 크기(3<=s<=10)
    int n; // 입력 : 작업의 개수(5<=n<=1,000)
    
    scanf("%d %d", &s, &n);
    std::vector<int> a(s+1); // s번째는 없으면 오류남(캐시 미스일 때 필요)
    
    //scanf("%d", &a[0]); // 첫 값만 받아옴
    
    for(int i=0; i<n; i++) // 작업의 개수만큼 반복
    {
        int tmp;
        scanf("%d", &tmp);
        int j; // 캐시 히트 장소 기억
        for(j=0; j<s; j++) // 캐시에서 작업을 찾음
        {
            if(a[j] == tmp || a[j] == 0) // 캐시 히트가 발생하면 break
                break;
        } // 캐시 미스가 발생하면 j가 s인 상태로 빠져나감(맨 뒤에서 부터 땡겨줌)
        
        for(int t=j; t>=1; t--) // j부터 0까지 뒤로 하나씩 밂
        { // j가 s일 경우 때문에 s번째 배열이 필요
            a[t] = a[t-1]; // 앞의 값을 뒤로 밂
        }
        a[0] = tmp; // 가장 최근 작업 맨 앞에 저장
    }
    for(int i=0; i<s; i++)
        printf("%d ", a[i]);
    
	return 0; 
}