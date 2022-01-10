#include <stdio.h>

int digit_sum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += x%10;
        x/=10;
    }
    return sum;
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 값(3<=n<=100)
    //int nArr[100]; // 입력 값(최대 10,000,000)
    int number; // 입력 값 한 번씩 받아서도 가능
    int sum=0, max=0, res=0; // 출력 값(자릿수 합이 최대인 수의 인덱스)
    
    scanf("%d", &n);
    
    for(size_t i=0; i<n; i++)
    {
        scanf("%d", &number);
        sum = digit_sum(number);
        
        if(sum > max)
        {
            max = sum;
            res = number; // 원래 숫자를 기억해야함
        }else if(sum == max) // 합이 동일한 경우 큰 값
        { 
            if(number > res) // 현재 숫자가 max인 숫자보다 크면
            {
                max = sum;
                res = number;
            }
        }
        sum = 0;
    }
    printf("%d", res);
	
	return 0;
}