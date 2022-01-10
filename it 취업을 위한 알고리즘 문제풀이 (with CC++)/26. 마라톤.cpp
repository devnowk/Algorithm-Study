#include <stdio.h>
#include <vector>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    // 각 선수가 앞으로 얻을 수 있는 최선의 등수
    // 자신의 앞에 있는 선수가 자기보다 잘하면 등수+1
    int n; // 입력(3<=n<=10,000)
    
    scanf("%d", &n);
    std::vector<int> arr(n); // 각 선수의 실력 배열
    //std::vector<int> rank(n); // 출력(각 선수의 최선의 등수)
    // 배열 안만들고 변수에 넣어도됨
    
    for(size_t i=0; i<n; i++) // 미리 받아야 등수 측정 가능
    {
        scanf("%d", &arr[i]);
        //rank[i] = 1;
    }
    
    printf("1 "); // 0번째 사람은 항상 1등
    for(size_t i=1; i<n; i++) // 1번째부터 시작
    {
        int cnt=1; // 출력(선수의 최선의 등수)
        for(size_t j=0; j<i; j++) // 자신 앞에 사람만 넘을 수 있는지 판별
        {
            if(arr[j] >= arr[i]) // 자기보다 실력이 좋거나 같으면
                cnt++; // 등수가 올라감 (실력이 같아도 추월할 수 없다는 말)
        }
        printf("%d ", cnt);
    }

	return 0;
}