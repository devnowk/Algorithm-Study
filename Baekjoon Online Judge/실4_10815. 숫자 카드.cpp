#include<iostream>
#include<algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);std::cout.tie(NULL);
    
    int n, m; // 입력 : 가진 카드 개수, 확인할 카드 개수(1<=n, m<=500,000)
    std::cin >> n;
    int card[500001];
    for(int i=0; i<n; i++) std::cin >> card[i];
    std::sort(card, card+n);
    std::cin >> m;
    for(int i=0; i<m; i++) // 이분 검색을 통해 카드가 있는지 확인
    {
        int target; // 찾을 카드
        std::cin >> target;
        int lt=0, rt=n-1;
        bool isExist=false;
        while(lt<=rt)
        {
            int mid=(lt+rt)/2;
            if(card[mid]<target) lt=mid+1;
            else if(target<card[mid]) rt=mid-1;
            else if(target==card[mid]) 
            {
                isExist=true;
                break;
            }
        }
        if(isExist) std::cout << 1 << " ";
        else std::cout << 0 << " ";
    }

    return 0;
}
