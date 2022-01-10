#include <stdio.h>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    char str[101]; // 입력 값(바이러스에 걸린 영어문자열)
    char res[101]; // 출력 값(원래 문자열)
    int pos = 0; // 문자열 옮길 때 사용하는 idx
    
    // scanf("%s", str); // 띄어쓰기까지 읽을 수 없음
    scanf("%[^'\n']", str); // 한 줄을 읽음
    for(size_t i=0; str[i]!='\0'; i++)
    {
        if(str[i]!=' ')
            if(str[i]>=65 && str[i]<=90) // 대문자 askii(65-90)
                res[pos++] = str[i]+32; // 소문자 askii(97-122)
            else // 소문자일 때
                res[pos++] = str[i];
    }
    // res[pos]='\0'; // 문자열 끝에 NULL입력
    
    printf("%s", res);
    
	return 0;
}