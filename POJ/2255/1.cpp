/**
    ���ǣ��������ѧ����������
    ��������.jpg
    ��ʱ��û̫�� ʲô������BLABLABLA��
    ˯��
    ���Ӷࡣ��
*/
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define maxn 100
using namespace std;

int n = 0;

char pre[30] = {0}, in[30] = {0};

void build(int l, int r)
{
    int i;
    if(l > r)return;
    for(i = l; i <= r; i++)
        if(pre[n] == in[i])
            break;
    n++;
    build(l, i-1);
    build(i+1, r);
    printf("%c", in[i]);
}

int main()
{
    while(~scanf("%s%s", pre, in))
    {
        int len = strlen(pre);
        build(0, len-1);
        printf("\n");
        n = 0;
    }
    return 0;
}
