#include<stdio.h>
#define maxn 100010

struct friends
{
    int b[3] = {0};
    int g[3] = {0};
}sheep[maxn];

int cnt[maxn];//cnt[i] ��ʾ�����ѹ�ϵ�г�ȡ���ĵ�i����ϵ�ߵĳ���
int f[maxn];//f[i] ��ʾ��i����ϵ���Ƿ���һ������ϵ������1������һ������0������

int calc_len_b(int b)
{
    int sum = 0;
    if()
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {

        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int i, tag = 1;
        for(i = 0; i < k; i++)
        {
            int b, g;
            scanf("%d%d", &b, &g);
            if(!sheep[b].b[1])
            {
                sheep[b].b[1] = g;
            }
            else sheep[b].b[2] = g;
            if(!sheep[g].g[1])sheep[g].g[1] = b;
            else sheep[g].g[2] = b;
        }
        for(i = 0; i < k; i++)
        {
            if(sheep[i].b[1] && !sheep[i].b[2])
            {
                cnt[tag] =
            }
        }
    }
}
