#include <stdio.h>
#include <vector>
#include <algorithm>

int n; // 입력 : 마구간의 개수(3<=n<=200,000)
int HorseCount(int mid, int xi[]) // 마구간에 들어갈 수 있는 말의 수를 반환
{
    int cnt=1; // 말의 수
    int horse=xi[0]; // 말이 있는 좌표를 기억(첫 번째 위치에는 무조건 있어야 함)
    for(int i=1; i<n; i++)
    {
        if(xi[i]-horse>=mid) // 거리가 같거나 더 높으면 말을 넣어도 됨
        {
            cnt++;
            horse=xi[i];
        }
    }
    return cnt;
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // 각 마구간에 한 마리의 말, 말의 거리가 최대가되는 최대값 구하기
    int c; // 입력 : 말의 수(2<=c<=n)
    int res; // 출력 : 말의 거리가 최대가 되는 거리
    
    scanf("%d %d", &n, &c);
    int *xi = new int[n]; // 동적으로 배열 잡음(0<=xi<=1,000,000,000)
    for(int i=0; i<n; i++)
        scanf("%d", &xi[i]);
    std::sort(xi, xi+n); // 가장 가까운 거리를 측정하기 위해 정렬
    
    int rt = xi[n-1]/(c-1); // 최대로 가질 수 있는 값 (마구간의 젤 큰 좌표/말의 수-1)
    int lt = 1; // 최소 거리
    
    while(lt<=rt)
    {
        int mid = (lt+rt)/2;
        if(HorseCount(mid, xi) >= c) // 말의 수가 같거나 많으면 거리를 더 늘려도됨
        {
            res = mid;
            lt = mid+1; // 최댓값을 찾기 위해 더 큰쪽으로 검색해봄
        }
        else // 말의 수가 적으면 거리를 좁혀야함
        {
            rt = mid-1;
        }
    }
    printf("%d", res);
    delete[] xi; // 동적 배열 할당 해제
    
	return 0;
}