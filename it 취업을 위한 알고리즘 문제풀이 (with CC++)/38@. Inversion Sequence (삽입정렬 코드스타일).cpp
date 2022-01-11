#include <stdio.h>
#include <vector>

int main() {
    // freopen("input.txt", "rt", stdin);
    
    //Inversion Sequence : 자기 앞에 자신보다 큰 수의 개수를 표현한 수열
	//원래 : 4 8 6 2 5 1 3 7 -> IS : 5 3 4 0 2 1 1 0
	
    int n; // 입력 : 수열의 개수(3<=n<=100)
    scanf("%d", &n);
    
    std::vector<int> is(n+1); // 입력 : 1~n이 가진 Inversion Sequence
	for(int i=1; i<n+1; i++) // 1~n 번째 배열에 넣음(인덱스가 원래 숫자를 가리킴)
	    scanf("%d", &is[i]);
	
	std::vector<int> res(n+1); // 출력 : 원래의 수열
	for(int i=n; i>=0; i--) // n부터 처리(큰 수의 개수를 구하면 마지막은 무조건 0)
	{ // @@@뒤로 옮기면서 자기 자리 찾아감(자기 뒤에 숫자들이 모두 자신보다 큰 수이므로)@@@
	    //res[i] = i;
	    int pos = i;
	    for(int j=0; j<is[i]; j++) // is가 가진 개수만큼 뒤로 옮김(큰 수를 앞으로 가져옴)
	    {
	        //res[i+j] = res[i+j+1];
	        res[pos]=res[pos+1];
	        pos++; // j를 이용한 것보다는 직관적임
	    }
	    //res[i+is[i]] = i; // i는 자리 찾아서 넣음
	    res[pos] = i;
	}
	
	for(int i=1; i<=n; i++)
	    printf("%d ", res[i]);
	
	return 0;
}