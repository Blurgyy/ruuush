#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
const int maxm = 10010;

int T, a[maxn], b[maxm];
int n, m, Next[maxm];

void Get_next(){
	int i = 0, j = -1;
	memset(Next, 0, sizeof(Next));
	Next[0] = -1;
	while(i < m){
		if(j == -1 || b[i] == b[j]){
			++ i, ++ j;
			if(b[i] != b[j])
				Next[i] = j;
			else Next[i] = Next[j];
		}
		else j = Next[j];
	}
}

int KMP(){
	Get_next();
	int i = 0, j = 0;
	while(i < n){
		if(j == -1 || a[i] == b[j])
			++ i, ++ j;
		else j = Next[j];
		if(j == m)return i - j + 1;
	}
	return -1;
}

void out(){
	for(int i = 0; i < m; ++ i)
		printf("%d ", Next[i]);
	printf("\n");
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++ i)
			scanf("%d", a + i);
		for(int i = 0; i < m; ++ i)
			scanf("%d", b + i);
		printf("%d\n", KMP());
		//out();
	}
	return 0;
}