#include <stdio.h>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    char id[20]; // 입력 : 주민등록 번호
    int age; // 출력 : 한국 나이(2019년도 기준)
    char gender; // 출력 : W - 여자, M - 남자
    
    scanf("%s", id);
    if(id[7] == '1' || id[7] == '2') // 2000년도 이전 탄생
        age = 119-((id[0]-48)*10 + (id[1]-48)); // 년도 문자 -> 숫자 나이로
    else // if(id[7] == '3' || id[7] == '4')
        age = 19-((id[0]-48)*10 + (id[1]-48));
        
    if((id[7]-48)%2 == 0) // 짝수는 여자 성별
        gender = 'W';
    else
        gender = 'M';
        
    printf("%d %c", age+1, gender); // 한국 나이 1 더해줌
	
	return 0;
}