//��ʾ
//һ��Ҫ����һ�������ƽ���ոմ���Ϸʧ�ܵ�����
#include<cstdio>
#include<algorithm>
#define ll long long

int main()
{
    ll n, m;
    while(~scanf("%d%d", &n, &m))
    {
        int l, r;
        int mid;
        while(l < r)
        {
            mid = (l + r) / 2;
            if((1 + mid) * mid / 2 < n)l = mid;
            else r = mid;
        }

    }
    return 0;
}
