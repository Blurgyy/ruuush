#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int maxm = 100010;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll n, m, k, p;
pii a[maxm];

int main(){
    while(~scanf("%lld%lld%lld", &n, &m, &k)){
        for(int i = 0; i < m; ++ i){
            scanf("%lld", &p);
            a[i] = make_pair((p-1) / k, (p-1) % k);
        }
        sort(a, a + m);
        a[m] = make_pair(inf, k-1);
        ll curfact = a[0].first;
        ll acc = 0, delcnt = 0, opcnt = 0;
        ll cur = 0;
        while(cur <= m){
            // printf("cur = %d\n", cur);
            if(a[cur].first == curfact){
                // printf("cur = %d\n", cur);
                acc ++;
                cur ++;
            }
            else if(a[cur].first != curfact){
                // printf("!cur = %d\n", cur);
                // for(int i = cur; i < m; ++ i){
                //     printf("(%d,%d)", a[i].first, a[i].second);
                // }
                // printf("\n");
                delcnt += acc;
                acc = 0;
                opcnt ++;
                a[cur].second -= delcnt;
                ll dist = (a[cur].second % k + k) % k;
                a[cur].first -= (dist - a[cur].second) / k;
                curfact = a[cur].first;
                for(int i = 1; cur + i <= m; ++ i){
                    ll nsecond = a[cur+i].second - delcnt;
                    ll dist = (nsecond % k + k) % k;
                    ll nfirst = a[cur+i].first - (dist - nsecond) / k;
                    // printf("[%d] delcnt = %d, opcnt = %d, nfirst = %d, curfact = %d\n", cur+i, delcnt, opcnt, nfirst, curfact);
                    if(nfirst != curfact){
                        // printf("[%d] not changed\n", cur+i);
                        break;
                    }
                    // a[cur+i].first -= (dist - a[cur+i].second) / 5;
                    a[cur+i].first = nfirst;
                    a[cur+i].second = dist;
                }
            }
        }
        printf("%lld\n", opcnt);
    }
    return 0;
}
