#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int h, w; // 입력 : 영지의 세로, 가로 길이(5<=h, w<=50)
    int hh, ww; // 입력 : 현수가 하사받을 땅의 크기
    scanf("%d %d", &h, &w);
    int max=0; // 출력 : 오렌지나무가 가장 많은 땅(hh*ww) 구역의 개수
    
    std::vector<std::vector<int> > map(h+1, std::vector<int>(w+1));
    // @@@ 배열에는 누적된 값을 집어넣음 ((3,4) : (0,0)부터(3,4)까지 직사각형 값의 합 @@@
    // 식 map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + scanf로 받은 값
    // 위 식을 만족하기 위해서 0행0열은 비워놔야함
    // @@@ O(n^2)로 하기 위해 다 더해놓은 것부터 시작하는 것임 @@@
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + tmp;
        }
    }
    scanf("%d %d", &hh, &ww);
    for(int i=hh; i<=h; i++)
    {
        for(int j=ww; j<=w; j++)
        {
            // (ww, hh)크기의 오렌지나무 합계
            int sum = map[i][j] - map[i-hh][j] - map[i][j-ww] + map[i-hh][j-ww];
            
            if(sum > max) max = sum;
        }
    }

    printf("%d", max);
    
	return 0;
}