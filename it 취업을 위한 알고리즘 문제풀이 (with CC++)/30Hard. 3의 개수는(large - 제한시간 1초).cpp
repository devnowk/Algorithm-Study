#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    // 1 ~ 5327
    // 1의자리, 10의자리, 100의자리, 1000의자리에 위치한 3의 개수 각각 구하기
    // 1의자리의 경우(3보다 큰 경우) lt : 532, rt : 0, k : 1
    // (lt+1)*k => 533개(lt에 있는 자리 수와 겹치지 않는 오로지 1의 자리만의 개수)
    // 10의자리의 경우(3보다 작은 경우) lt : 53, rt : 7, k : 10
    // (lt*k) => 530개(lt : 0~52, lt : 53인 경우는 없음)
    // 100의자리의 경우(3인 경우) lt : 5, rt : 27, k : 100
    // (lt*k)+(rt+1) => 528개(lt : 0~5, lt : 5인 경우 rt : 0~27)
    // 1000의자리의 경우(3보다 큰 경우) lt : 0, rt : 327, k : 1000
    // (lt+1)*k => 1000개(rt : 0~999모두 가능)
    
    long long n; // 입력(3<=n<=1,000,000,000)
    long long cnt=0; // 출력(3의 개수)
    long long lt, cur, rt=0, k=1;
    // cur : 현재 자리수, lt : 왼쪽에 있는 수, rt : 오른쪽에 있는 수, k : 자리수 체크
    
    scanf("%lld", &n);
    lt = n/10; // lt값 먼저 세팅
    cur = n%10; // cur은 1의자리로 세팅
    while(1)
    {
        if(cur > 3) // 3보다 큰 경우
            cnt += (lt+1)*k;
        else if(cur < 3) // 3보다 작은 경우
            cnt += lt*k;
        else // 3인 경우
            cnt += (lt*k)+(rt+1);
        
        if(lt == 0)
            break;
        
        rt += cur*k; // k는 자리수를 가리킴
        cur = lt%10; // cur은 lt 마지막 수 하나만 가져오면 됨
        lt /= 10; // lt는 마지막 수만 빼면 됨
        k *= 10; // 자리수 올려줌
    }
    
    printf("%lld", cnt);
    
	return 0; 
}