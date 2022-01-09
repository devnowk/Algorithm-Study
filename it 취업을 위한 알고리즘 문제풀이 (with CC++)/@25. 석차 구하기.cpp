#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(1<=n<=100)
    scanf("%d", &n);
    
    std::vector<int> arr(n); // 입력(학생들의 점수 배열)
    std::vector<int> rank(n); // 출력(석차 배열)
    for(size_t i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        rank[i] = 1;
    }
        
    //@@@이중 반복문 돌리면서 자기보다 큰 값 나오면 등수++@@@
    for(size_t i=0; i<n; i++) // i의 등수 구하기
    {
        for(size_t j=0; j<n; j++)
        {
            //if(i==j)    continue;
            //위에꺼 안적어도 자기 자신은 그냥 넘어가게 돼있음
            if(arr[i] < arr[j]) // 다른 사람이 더 높은 점수면
                rank[i]++; // 등수를 올림
        }
        printf("%d ", rank[i]); // i의 석차는 정해짐
    }
    
	return 0;
}