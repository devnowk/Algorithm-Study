#include <iostream>
#include <vector>

int arr[1000000]; // 입력 : 정렬할 숫자 배열

void DnC(int lt, int rt) // 정렬할 왼쪽 끝 숫자 lt와 오른쪽 끝 숫자 rt
{
    if(lt<rt) // 분리할 숫자가 남아 있으면 분리
    {
        int mid = (lt+rt)/2; // 중심을 기준으로 나눔
        DnC(lt, mid); // 왼쪽 먼저 한 개까지 분리
        DnC(mid+1, rt); // 오른쪽 분리
        
        // 분리하고 부모로 돌아와서 정렬에 맞게 병합하는 과정
        int p1=lt, p2=mid+1, p3=lt; // p1, p2는 정렬에 맞게 넣는 포인터, p3는 새로운 배열에 넣을 위치 가리킴
        std::vector<int> tmp(1000000); // 정렬된 데이터를 임시로 넣을 배열
        while(p1<=mid && p2<=rt) // 범위를 넘길 수 없음
        {
            if(arr[p1]<arr[p2]) tmp[p3++]=arr[p1++]; // 작은 걸 tmp에 넣음
            else tmp[p3++]=arr[p2++];
        }
        // 남은 숫자 몽땅 넣음
        while(p1<=mid) tmp[p3++]=arr[p1++];
        while(p2<=rt) tmp[p3++]=arr[p2++];
        
        for(int i=lt; i<=rt; i++) {
        	arr[i]=tmp[i]; // tmp의 내용 arr로 옮김
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n; // 입력 : 정렬할 숫자 개수
    std::cin >> n;
    for(int i=0; i<n; i++) std::cin >> arr[i];
    
    DnC(0, n-1); // 0부터 n-1번째까지 정렬하는 함수(Divide and Conquer)
    
    for(int i=0; i<n; i++) std::cout << arr[i] << "\n"; // 함수 갔다 오면 정렬 돼 있음
    
    return 0;
}