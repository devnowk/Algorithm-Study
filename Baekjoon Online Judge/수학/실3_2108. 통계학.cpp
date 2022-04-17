#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> arr; // 입력 : 입력되는 숫자들(|x|<=4,000)
int n; // 숫자들의 개수(1<=n<=500,000, n은 홀수)

int mean() // 산술평균 함수
{
    int sum=0;
    for(int i=0; i<n; i++) sum+=arr[i];
    int tmp=sum*10/n; // 평균에 10 곱한 값
    if(tmp>0) return (tmp+5)/10; // 5를 더하고 다시 10으로 나누면 소수점 첫째자리에서 반올림 한 값이 됨
    return (tmp-5)/10;
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
    for(int i=0; i<n; i++) 
    {
        if(arr[i]>=0) 
        {
            int tmp=arr[i];
            count1[tmp]++;
            if(count1[tmp] > max) 
            {
                max=count1[tmp]; // 숫자 개수가 가장 많은 걸로 업데이트
                first=tmp;
                second=4001;
            }
            else if(count1[tmp]==max)
            {
                if(tmp<first) 
                {
                    second=first;
                    first=tmp; // 맨 첫번째로 작은 값
                }
                else if(tmp<second) second=tmp; // 첫번째보다 크면 두번째로 작은 값
            }
        }
        else 
        {
            int tmp=arr[i];
            count2[-tmp]++;
            if(count2[-tmp] > max) 
            {
                max=count2[-tmp];
                first=tmp;
                second=4001;
            }
            else if(count2[-tmp]==max)
            {
                if(tmp<first) 
                {
                    second=first;
                    first=tmp; // 맨 첫번째로 작은 값
                }
                else if(tmp<second) second=tmp; // 첫번째보다 크면 두번째로 작은 값
            }
        }
    }
    if(second==4001) return first;
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