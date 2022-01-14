#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(3<=n<=1500)
    //int cnt=1; // ugly number 세기(1부터 시작)
    //int res; // 출력 : n 번째 ugly number(소인수분해시 2, 3, 5로 이루어진 수)
    
    scanf("%d", &n);
    std::vector<int> a(n+1);
    a[1]=1;
    /*******************Time Limit***************
    int i=2;
    while(cnt!=n)
    {
        int j=2;
        int tmp=i;
        bool flag=true; // Ugly Number인지 체크
        while(tmp>1)
        {
            if(tmp%j==0) tmp/=j; // 소인수분해
            else j++;
            
            if(j==6) // 6이상이면 UN이 아님
            {
                flag = false;
                break;
            }
        }
        if(flag) cnt++; // i가 ugly number일 경우
        if(cnt == n) // i가 n번째 UN일 경우
        {
            printf("%d", i);
            break;
        }
        i++;
    }
    *******************Time Limit***************/
    // @@@ 이전의 값을 이용해서 a의 배열을 완성시킬 수 있음 @@@
    // 1 2 3 4 5 6 8 9 10 12 15에서 6은 2*3을 한 값, 8은 4*2를 한 값
    int p2=1, p3=1, p5=1; // 이전의 값을 가리킬 포인터 변수
    // a[p2]*2, a[p3]*3, a[p5]*5 중 가장 작은 값을 넣고 ++
    for(int i=2; i<=n; i++)
    {
        int x=a[p2]*2, y=a[p3]*3, z=a[p5]*5;
        
        // 최솟값 판별
        if(x<y) a[i] = x; // 일단 a[i]에 넣고 봄
        else a[i] = y;
        if(z < a[i]) a[i] = z;
        
        // @@@ 같은 값이면 포인터를 모두 증가시킴 @@@
        if(a[i] == x) p2++;
        if(a[i] == y) p3++;
        if(a[i] == z) p5++;
    }
    
    printf("%d", a[n]);
    
	return 0;
}