#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

int a[101]; // 입력 : n개의 자연수(정수형 범위)

// 시간 복잡도 Level 당 n번씩 비교, Level의 개수는 logn => O(nlogn)
void divide(int lt, int rt) // lt와 rt 사이의 수를 정렬
{
    int mid;
    if(lt < rt) // 쪼갤 수 있는 범위(한 개가 되면 그만 쪼갬)
    {
        // @@@ 후위 순회 : 왼쪽 -> 오른쪽 -> 루트 순회 @@@
        mid = (lt+rt)/2; // 중심을 기준으로 나눌 것임
        divide(lt, mid); // 왼쪽 부분 쪼갬
        divide(mid+1, rt); // 오른쪽 부분 쪼갬
        
        // 왼쪽 자식과 오른쪽 자식 끝나고 부모로 다시 돌아온 부분
        // 두 자식들을 합쳐서 정렬해야 함(투 포인터 알고리즘)
        int p1=lt, p2=mid+1, p3=lt; // p3 : 임시 배열의 포인터
        int tmp[101]; // 임시배열
        
        while(p1<=mid && p2<=rt) // 정렬된 두 배열 lt~mid, mid+1~rt 비교
        {
            if(a[p1] < a[p2]) tmp[p3++] = a[p1++];
            else tmp[p3++] = a[p2++];
        }
        while(p1<=mid) tmp[p3++] = a[p1++]; // p1쪽이 남아있으면 몽땅 집어넣음
        while(p2<=rt) tmp[p3++] = a[p2++]; // p2쪽이 남아있으면 몽땅 집어넣음
        
        for(int i=lt; i<=rt; i++) a[i] = tmp[i]; // 정렬된 tmp배열을 a에 옮김
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(1=n<=100)
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    
    divide(1, n); // 1부터 n까지 쪼개고 정렬하는 함수(Divide and Conquer)
    for(int i=1; i<=n; i++) printf("%d ", a[i]);

	return 0;
}