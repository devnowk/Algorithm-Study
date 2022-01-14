#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    int h, w; // 입력 : 영지의 세로, 가로 길이(5<=h, w<=50)
    int hh, ww; // 입력 : 현수가 하사받을 땅의 크기
    scanf("%d %d", &h, &w);
    int max=0; // 출력 : 오렌지나무가 가장 많은 땅(hh*ww) 구역의 개수
    
    std::vector<std::vector<int> > map(h, std::vector<int>(w));
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
            scanf("%d", &map[i][j]);
    }
    scanf("%d %d", &hh, &ww);
    
    for(int i=0; i<=h-hh; i++) // 행의 반복 횟수
    {
        for(int j=0; j<=w-ww; j++) // 열의 반복 횟수
        {
            int sum=0; // 오렌지 나무 개수 세기
            for(int a=0; a<hh; a++)
                for(int b=0; b<ww; b++)
                    sum += map[i+a][j+b]; // 오렌지 나무 개수 초기화
            
            if(sum > max) max = sum;
        }
    }
    
    printf("%d", max);
    
	return 0;
}