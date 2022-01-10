#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(10<=n<=1,000)
    int cnt=0; // 출력(일의 자리부터 연속된 0의 개수)
    // 5와 2의 조합 개수 세기(소수에 곱하면 10이 되는 게 이 두 개임)

    scanf("%d", &n);
    std::vector<int> prime(n+1); // n!을 소수로 나타낼 배열
    for(size_t i=2; i<=n; i++)
    {
        int tmp = i;
        /*소인수 분해 할 필요없이 5 개수만 구하면 됨
        int j=2;
        while(tmp>1)
        {
            if(tmp%j == 0)
            {    
                prime[j]++;
                tmp/=j;
            }
            else j++;
        }******************************************/
        while(1)
        {
            if(tmp%5 == 0)
            {    
                cnt++;
                tmp/=5;
            }
            else
                break;
        }
    }
    
    //printf("%d", prime[5]); // 결국 2보다는 5가 적으므로 5의 개수가 0의 개수가 됨
     printf("%d", cnt);
        
	return 0;
}