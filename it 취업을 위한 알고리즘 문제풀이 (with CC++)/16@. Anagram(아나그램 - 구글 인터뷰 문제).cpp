#include <stdio.h>

//@@@한 배열에 +하고 -하는 아이디어@@@
int cnt[52]; // 출력 값 문자 개수 넣을 배열(알파벳 52개)
int main()
{
    // freopen("input.txt", "rt", stdin);
    
    char a[101]; // 입력 값(비교할 두 문자열)
    // bool isAna = true; // 출력 값(아나그램이면 true)
    
    scanf("%s", a);
    for(size_t i=0; a[i]!='\0'; i++)
    {
        int tmp = 0;
        if(a[i] <= 90) // 대문자일 때
        {
            tmp = a[i] - 65; // 대문자 0~25
            cnt[tmp]++;
        }else // 소문자일 때
        {
            tmp = (a[i] - 97) + 26; // 소문자 26~51
            cnt[tmp]++;
        }
    }
    
    scanf("%s", a);
    for(size_t i=0; a[i]!='\0'; i++)
    {
        int tmp = 0;
        if(a[i] <= 90) // 대문자일 때
        {
            tmp = a[i] - 65; // 대문자 0~25
            cnt[tmp]--;
        }else // 소문자일 때
        {
            tmp = (a[i] - 97) + 26; // 소문자 26~51
            cnt[tmp]--;
        }
        if(cnt[tmp] < 0) // 두 번째 문자열에서 뭔가 더 많음
        {
            printf("NO");
            return 0;
        }
    }
    for(size_t i=0; i<52; i++)
    {
        if(cnt[i]!=0) // 문자의 개수가 하나라도 다를 때
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    
	return 0;
}