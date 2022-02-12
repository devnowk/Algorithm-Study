#include <stdio.h>
#include <vector>

int unf[1001]; // 인덱스 번호 의미 : 학생 번호, 값 의미 : 어떤 집합에 있는 지 
// @@@ 1차원 배열로 트리 형태를 의미할 수 있음 @@@

int Find(int v) // @@@ 집합의 루트 노드를 반환하는 함수 @@@
{
    if(v == unf[v]) return v; // 집합의 루트노드였을 경우
    else return Find(unf[v]); // 루트노드를 추적해 나감
}

void Union(int a, int b) // 어떤 집합인지 만들어줌
{
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a] = b; // a가 b를 가리키게 해주면서 트리 구조를 이룸  
}

int main() {
    // freopen("input.txt", "rt", stdin);
    
    // 어떤 두 집합 사이에 교집합이 존재하면 한 집합으로 만들기
    // Disjoint-set : 위 방법으로 만들어진 A 집합과 B 집합은 서로소 집합이다.
        
    int n, m; // 입력  : 학생수 n(1<=n<=1,000), 친구관계 수 m(1<=m<=3,000)
    scanf("%d %d", &n, &m);
   
    for(int i=1; i<=n; i++)
        unf[i] = i; // 1~n까지 넣음, 처음은 모두 각자 집합
   
    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        Union(a, b); // 친구관계를 유니온 함수에 넘기면 트리구조가 만들어짐
    }
    
    int a, b; // 입력 : 친구인지 확인하는 학생
    scanf("%d %d", &a, &b);
    if(Find(a) == Find(b)) printf("YES"); // 루트 노드가 같으면 둘이 친구
    else printf("NO");
    
	return 0;
}