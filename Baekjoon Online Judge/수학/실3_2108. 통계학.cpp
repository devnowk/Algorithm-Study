#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> arr; // 입력 : 입력되는 숫자들(|x|<=4,000)
int n; // 숫자들의 개수(1<=n<=500,000, n은 홀수)

int mean() // 산술평균 함수
{
    long sum=0;
    for(int i=0; i<n; i++) sum+=arr[i];
    int tmp=sum*10/n; // 평균에 10 곱한 값
    
    if(tmp>0) return (tmp+5)/10; // 5를 더하고 다시 10으로 나누면 소수점 첫째자리에서 반올림 한 값이 됨
    return (tmp-5)/10; // sum이 음수라면 -5를 더해야 반올림 값이 나옴
}

int median() // 중앙값 함수
{
    std::sort(arr.begin(), arr.end()); // 오름차순으로 정렬
    return arr[(n-1)/2];
}

int frequent() // 최빈값 함수
{
    std::vector<int> count1(4001); // 숫자의 개수를 세는 배열
    std::vector<int> count2(4001); // 마이너스 숫자의 개수를 세는 배열
    int max=0;
    int first=4001, second=4001;
    for(int i=0; i<n; i++) // 숫자의 개수를 셈
    {
        int tmp=arr[i]; // 배열의 값이 양수이면 count1, 음수이면 count2에 센다.
        if(tmp>=0) 
        {
            count1[tmp]++;
            if(count1[tmp]>max) max=count1[tmp]; // max값은 미리 찾아놓음
        }
        else 
        {
            count2[-tmp]++;
            if(count2[-tmp]>max) max=count2[-tmp];
        }
    }
    //std::cout << "max : " << max <<"\n";
    
    for(int i=0; i<4001; i++) // 최빈값 확인
    {
        if(count1[i]==max) // 양의 정수
        {
            if(i<first) // 최솟값 갱신
            {
                second=first; // first에 이미 값이 있었다면 second가 됨
                first=i;
            }
            else if(i<second) second=i; // second에 값이 없을 때 갱신됨
        }
        if(count2[i]==max) // 음의 정수
        {
            if(-i<first) 
            {
                second=first;
                first=-i;
            }
            else if(-i<second) second=-i;
        }
    }
    
    if(second==4001) return first; // second가 없으면 first 반환
    return second;
}

int difference() // 범위 함수(최대ㆍ최소 차이)
{
    std::sort(arr.begin(), arr.end());
    int min=arr[0];
    int max=arr[n-1];
    //std::cout << "min-max : " << min << " " << max << "\n";
    return max-min;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    std::cout << mean() << "\n" << median() << "\n" << frequent() << "\n" << difference();
    
    return 0;
}