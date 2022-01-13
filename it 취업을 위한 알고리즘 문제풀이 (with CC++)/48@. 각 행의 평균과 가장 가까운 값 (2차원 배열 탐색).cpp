#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    //std::vector<std::vector<int> > map(9, std::vector<int>(9));
    int a[9][9]; // 입력(100이하 자연수)
    
    for(int i=0; i<9; i++)
    {
        int rowAvg=0; //  출력 : 각 행의 평균(소수 첫 째 자리에서 반올림)
        int distMin=100; // 평균과 가장 적은 차이
        int res=0; // 평균과 가장 가까운 수(두 개일 경우 그 중 큰 값)
        for(int j=0; j<9; j++)
        {
            scanf("%d", &a[i][j]);
            rowAvg+=a[i][j];
        }
        rowAvg = (double)rowAvg/9 + 0.5; // @@@0.5를 더하면 0.499까지는 버림이 되고 0.5부터는 올림이 됨@@@
        for(int j=0; j<9; j++)
        {
            int tmp = rowAvg - a[i][j];
            if(tmp < 0) tmp = -tmp; // 양수로 변환
            // tmp = abs(rowAvg - a[i][j]) 해줘도 됨(algorithm 제공)
            if(tmp < distMin)
            {
                distMin = tmp; // 더 가까우면 차이를 바꿔줌
                res = a[i][j];
            }else if(tmp == distMin)
            {
                if(a[i][j] > res) // 차이가 동일 할 때 더 큰 값이 답
                    res = a[i][j];
            }
        }
        printf("%d %d\n", rowAvg, res);
    }
    
	return 0;
}