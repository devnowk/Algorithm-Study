#include <stdio.h>
#include <vector>

// 복면산 : SEND+MORE=MONEY 알파벳 각각이 가리키는 숫자는 0~9 중 하나이다. 각각이 가리키는 숫자가 뭔지 구하는 문제
// 순열을 통해 모든 숫자의 경우의 수를 생각하여 조건에 맞는지 확인한다.

int a[9]; // 각각 SENDMORY 알파벳이 가리키는 숫자가 담긴 배열
int ch[10]; // 어떤 숫자가 사용되었는지 체크
bool flag = false;

// @@@ 객체 지향적 코드짜기.. @@@
int Send()
{
    return a[1]*1000+a[2]*100+a[3]*10+a[4];
}

int More()
{
    return a[5]*1000+a[6]*100+a[7]*10+a[2];
}

int Money()
{
    return a[5]*10000+a[6]*1000+a[3]*100+a[2]*10+a[8];
}

void DFS(int cnt) // 몇 번째 번호까지 정했는지
{
    if(cnt == 9) // 마지막 알파벳까지 모두 숫자가 정해졌으면 식이 맞는지 체크
    {
        if(Send() + More() == Money()) flag = true; // 식이 성립하면 빠져나옴
        return;
    }
    for(int i=0; i<=9; i++) // 숫자 0부터 9까지 집어넣어서 순열로 경우의 수 따짐
    {
        if(flag) return; // 한 번에 다 빠져나옴
        if(cnt==1&&i==0 || cnt==5&&i==0) continue; // 첫째짜리는 0 불가능
        if(ch[i] == 0) // 숫자 i가 사용되지 않았을 때만 사용할 수 있음
        {
            ch[i] = 1;
            a[cnt] = i;
            DFS(cnt+1); // cnt++하면 돌이킬 수 없음..
            ch[i] = 0; // 갔다 오면 체크 해제
        }
    }
}

int main()
{
    // freopen("파일이름", "rt", stdin);
    
    DFS(1); // 1번부터 호출
    
    printf(" %d\n+%d\n------\n%d", Send(), More(), Money());
    return 0;
}