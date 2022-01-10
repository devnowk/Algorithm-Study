#include <stdio.h>

int main()
{
    // freopen("input.txt", "rt", stdin);
    
    int n; // 입력(3<=n<=100)
    int height[100]; // 입력(키 정보)
    int cnt=0; // 뒷 사람 모두를 방해하는 학생 수
    
    scanf("%d", &n);
    for(size_t i=0; i<n; i++)
        scanf("%d", &height[i]);
        
    /*뒤에서부터 max값을 업뎃할 때 마다 cnt++하면 더 간단
    for(size_t i=0; i<n-1; i++) // 맨 마지막 사람 제외
    {
        bool flag = true; // 뒷 사람 모두를 방해하는 지
        for(size_t j=i+1; j<n; j++)
        {
            if(height[i] <= height[j]) // 뒷 사람이 더 크면
            {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
    ****************************************************/
    //@@@뒷 사람들 보다는 제일 크다는 아이디어@@@
    int max=height[n-1]; // 맨 뒷사람의 키를 최대로 설정
    for(int i=n-2; i>=0; i--)
    {
        if(height[i] > max)
        {
            max = height[i];
            cnt++;
        }
    }
    
    printf("%d", cnt);
    
	return 0;
}