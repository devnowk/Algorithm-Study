#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 왕자의 수(5<=n<=1,000)
    int k; // 외치면 제외되는 수(2<=k<=9)
    scanf("%d %d", &n, &k);
    
    std::vector<int> a(n+1);
    int num=n; // 살아남은 왕자의 수
    int pos=0; // 왕자를 가리키는 포인터 변수
    int cnt=0; //k번째 왕자를 세는 변수
    while(num!=1) // 한 명만 남으면 탈출
    {
        pos++;
        if(pos==n+1) // 동그랗게 앉아있으므로 n을 넘어가면 1로 설정
            pos=1;
        if(a[pos]==0) // 0을 가진 사람만 세야함
            cnt++;
            
        if(a[pos]==0 && cnt==k) // 왕자가 k번째라면 제외함
        {
            a[pos]=1;
            num--;
            cnt=0;
        } 
    }
    for(int i=1; i<=n; i++)
    {
        if(a[i] == 0)
            printf("%d", i);
    }
   
	return 0;
}