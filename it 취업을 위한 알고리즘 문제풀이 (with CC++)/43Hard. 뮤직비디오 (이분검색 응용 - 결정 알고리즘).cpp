#include <stdio.h>
#include <vector>
#include <algorithm>

int a[1001];
int n; // DVD에 들어가는 총 곡의 개수(1<=n<=1,000)
int m; // DVD의 총 개수(1<=m<=n), dvd의 크기는 모두 동일

bool DVDCount(int s) // 사이즈(mid)를 주면 가능한지 판단하는 함수
{
    int dvdNum=1; // 필요한 dvd 개수
    int sum=0; // 동영상의 합 저장
    for(int i=0; i<n; i++)
    {
        sum += a[i];
        if(sum > s) // 최대 사이즈를 넘어가면
        {
            sum = a[i];
            dvdNum++; // dvd 개수 증가시킴
        }
        if(dvdNum > m) return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int res; // 출력 : dvd의 최소 용량 크기
    //int sum=0; // 동영상의 총 길이
    int lt=0, rt=0;
    
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        //sum+=tmp; // rt에 더해주면 됨
        rt += a[i];
    }
    // dvd의 길이는 최소 sum/m부터 최대 sum까지이다.
    // 45분 길이를 3개로 나눠야 할 때 15분~45분까지 가능
    lt=rt/m;
    while(lt<=rt)
    {
        int mid = (lt+rt)/2;
        
        if(DVDCount(mid)) // 성공하면 더 작은 것도 해봐야함
        {
            res = mid;
            rt = mid-1;
        }
        else // 실패하면 더 큰 것도 해봐야함
        {
            lt = mid+1;
        }
        
        /*********함수로 대체(DVDCount)*************
        int tmp=0; // 동영상 합 임시 저장
        int number=1; // 몇 번째 dvd인지(최대 m까지)
        bool flag = true; // 저장되는지 확인
        for(int i=0; i<n; i++)
        {
            tmp += a[i];
            if(tmp > mid) // dvd용량을 넘어가면
            {
                tmp = a[i];
                number++; // 다음 dvd로 넘김
            }
            if(number > m) // dvd 용량을 초과함
            {
                flag = false;
                break;
            }
        }
        if(flag) // 성공하면 더 작은 것도 되는 지 확인해봐야함
        {
            res = mid;
            rt = mid-1;
        }else // 실패하면 더 크게 해봐야함
        {
            lt = mid+1;
        }
        ********************************************/
    }
    
    printf("%d", res);
    
	return 0;
}