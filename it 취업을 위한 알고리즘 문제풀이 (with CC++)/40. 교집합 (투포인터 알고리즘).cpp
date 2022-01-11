#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n, m; // 입력 : 집합 a, b의 크기(1<=n, m<=30,000)
    
    scanf("%d", &n);
    std::vector<int> a(n); // 입력 : 집합 a, 원소 중복X
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
        
    scanf("%d", &m);
    std::vector<int> b(m); // 입력 : 집합 b, 원소 중복X
    for(int i=0; i<m; i++)
        scanf("%d", &b[i]);
    
    // 투포인터 알고리즘 쓰기 위해선 두 배열이 정렬돼있어야 함
    sort(a.begin(), a.end()); // 퀵 정렬(algorithm에서 제공)
    sort(b.begin(), b.end()); // 기본 오름차순
    
    
    int p1=0, p2=0, p3=0; // 각각 a, b, res 배열을 가리키는 변수
    std::vector<int> res(n); // n이나 m 중 아무거나 해도 됨
    while(p1 < n && p2 < m) // 둘 중에 하나가 먼저끝나면 끝
    {
        if(a[p1] == b[p2])
        {
            res[p3++] = a[p1]; // a나 b 둘 중 아무거나 넣고
            p1++; p2++; // 둘 다 증가
        } else if(a[p1] < b[p1]) // a가 더 작으면 b가 기다려줌
        {
            p1++;
        } else // b가 더 작으면 a가 기다려줌
        {
            p2++;
        }
    }
    
    for(int i=0; res[i]!=0; i++) // i를 p3전까지 돌려도됨
        printf("%d ", res[i]);
    
	
	return 0;
}