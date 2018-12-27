#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define maxn 1005
#define INF 1e9
using namespace std;

int n, m;
int d[maxn];
vector<pair<int,int> > E[maxn];

void init()
{
    for(int i = 0; i <= n; i++)E[i].clear();
    for(int i = 0; i <= n; i++)d[i] = INF;
    d[1] = 0;
}

int main()
{
    scanf("%d%d", &n, &m);
        init();
        int x, y, z;
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &z);
            E[x].push_back(make_pair(y, z));
            E[y].push_back(make_pair(x, z));
        }
        priority_queue<pair<int, int> > Q;
        Q.push(make_pair(-d[1], 1));
        while(!Q.empty())
        {
            int now = Q.top().second;
            Q.pop();
            int total = E[now].size();
            for(int i = 0; i < total; i++)
            {
                int v = E[now][i].first;
                if(d[v] > d[now] + E[now][i].second)
                {
                    d[v] = d[now] + E[now][i].second;
                    Q.push(make_pair(-d[v], v));
                }
            }
        }
        if(d[n] == INF)printf("-1\n");
        else printf("%d\n", d[n]);
    return 0;
}