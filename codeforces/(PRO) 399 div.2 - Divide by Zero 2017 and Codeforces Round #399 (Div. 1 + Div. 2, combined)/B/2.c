//��˵���ҵ�ret_len����д��һ��ʼ���ԡ�һ��ʼ������

#include<stdio.h>
#define ll long long

/*

ll ret_len(ll n)
{
    ll len = 1;
    while(n /= 2)
    {
        len *= 2;
    }
    return len - 1;
}
������ԭ��д�ķ���������������list���ȵĺ���

*/

ll ret_len(ll n)
{
    ll len = 1;
    while(n > 1)
    {
        n /= 2;
        len *= 2;
    }
    return len * 2 - 1;
}

int counter(ll len, ll targ, ll n)
{
    if(n < 2) return n;
    if(targ * 2 == len + 1)return n % 2;
    n /= 2;
    len /= 2;
    if(targ > len + 1)targ -= (len + 1);
    return counter(len, targ, n);
}

int main()
{
    printf("��˵���ҵ�ret_len����д��һ��ʼ���ԡ�һ��ʼ������\n");
    ll n, l, r;
    while(~scanf("%I64d%I64d%I64d", &n, &l, &r))
    {
        ll len = ret_len(n), i;
        int count = 0;
        for(i = l; i <= r; i++) count += counter(len, i, n);
        printf("%d\n", count);
    }
    return 0;
}
// OH SHIT
