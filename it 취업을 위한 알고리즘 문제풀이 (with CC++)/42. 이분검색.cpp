#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력 : 숫자 개수(3<=n<=1,000,000)
    int m; // 입력 : n개의 수 중 m 찾기
    int idx = -1; // 출력 : m이 있는 곳(몇 번째인지)
    scanf("%d %d", &n, &m);
    std::vector<int> a; // 아직 메모리에 공간은 잡히지 않음
    
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp); // 배열 뒤에 동적으로 값이 추가됨
    }
    // begin()은 0번째를 가리키는 포인터, end()는 마지막 다음을 가리키는 포인터
    sort(a.begin(), a.end()); // 이분검색을 하기 위해서는 정렬이 필요함
    
    int i=0, j=n-1; // 이분 검색을 할 포인터
    while(i<=j) // 같을 때까지 해줘야 모두 검사함
    {
        int mid = (i+j)/2;
        if(a[mid] == m) // m을 찾음
        {
            idx = mid;
            break;
        }else if(m < a[mid]) // m이 더 작은 곳에 있음
        {
            j = mid-1;
        } else // m이 더 큰 곳에 있음
        {
            i = mid+1;
        }
    }
    
    printf("%d", idx+1);
    
	return 0;
}