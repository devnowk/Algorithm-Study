#include <stdio.h>

int reverse(int x) // 숫자 뒤집기 함수
{
    int tmp=0;
    while(x > 0)
    {
        tmp *= 10; // 한 자리씩 이동
        tmp += x%10; // x의 숫자를 뒤에서부터 넣어줌
        x/=10;
    }
    return tmp;
}

bool isPrime(int x) // 소수인지 확인 함수
{
    if(x==1)
        return false;
        
    bool flag=true;
    for(size_t i=2; i<x; i++)
    {
        if(x%i == 0)
        {
            flag=false;
            break;
        }
    }
    return flag;
}

int main()
{
    //int n, arr[100]; // 입력 값(자연수의 개수, 자연수)
    int n, num; // 하나만 받아도 됨
    int res=0; // 출력 값(뒤집은 수)
    
    scanf("%d", &n);
    for(size_t i=0; i<n; i++)
    {
        //scanf("%d", &arr[i]);
        scanf("%d", &num);
        res = reverse(num); // 뒤집은 숫자
        
        if(isPrime(res))
            printf("%d ", res);
    }   
    
	return 0;
}