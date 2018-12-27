#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<malloc.h>
using namespace std;
const int maxn = 1000010;
/***********************/
struct Trie
{
	int finish;
	Trie *nxt[26], *fail;
	void init(){
		for(int i = 0; i < 26; ++ i)
			nxt[i] = NULL;
		fail = NULL;
		finish = 0;
	}
}root;
int T, N;
char word[55], text[maxn];
/************************/
void Insert(char *s){
	int index;
	Trie *now = &root;
	while(*s){
		index = *s - 'a';
		if(now->nxt[index] == NULL){
			Trie *tmp = (Trie*)malloc(sizeof(Trie));
			tmp->init();
			now->nxt[index] = tmp;
		}
		now = now->nxt[index];
		++ s;
	}
	now->finish ++;
}

void Get_fail(){
	queue<Trie*> Q;
	Trie *now, *ancestor;
	Q.push(&root);
	while(!Q.empty()){
		now = Q.front();
		Q.pop();
		for(int i = 0; i < 26; ++ i){
			if(now->nxt[i]){
				Q.push(now->nxt[i]);
				if(now == &root){
					now->nxt[i]->fail = &root;
					continue;
				}
				ancestor = now->fail;
				while(ancestor){
					if(ancestor->nxt[i]){
						now->nxt[i]->fail = ancestor->nxt[i];
						break;
					}
					ancestor = ancestor->fail;
				}
				if(ancestor == NULL){
					now->nxt[i]->fail = &root;
				}
			}
		}
	}
}

int AC_Automation(char *s){
	Get_fail();
	Trie *now = &root, *tmp;
	int index, ans = 0;
	while(*s){
		index = *s - 'a';
		while(!now->nxt[index] && now != &root)
			now = now->fail;
		now = now->nxt[index];
		if(!now)now = &root;
		tmp = now;
		while(tmp != &root && tmp->finish >= 0){
			ans += tmp->finish;
			tmp->finish = -1;
			tmp = tmp->fail;
		}
		++ s;
	}
	return ans;
}

void Del(Trie *now = &root){
	for(int i = 0; i < 26; ++ i){
		if(now->nxt[i]){
			free(now->nxt[i]);
		}
		now->fail = NULL;
	}
}
/*********/
int main(){
	scanf("%d", &T);
	while(T--){
		root.init();
		scanf("%d", &N);
		while(N--){
			scanf("%s", word);
			Insert(word);
		}
		scanf("%s", text);
		printf("%d\n", AC_Automation(text));
		Del();
	}
	return 0;
}

/**

1
5
she
he
say
shr
her
yasherhs

*/