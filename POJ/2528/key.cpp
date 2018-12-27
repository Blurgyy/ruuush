#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
int T, N, x, y;
map < int, int > mp;
set <int> st;
map<int,int>::iterator beg, end;
struct segtree {
       int left, right,cov;
       int mid () { return (left+right)>>1; }
}seg[80010];
struct P {  //�ڵ�����
       int left, right;
}pp[10010];
void creat ( int x, int y, int rt = 1 ) {
     seg[rt].left = x;
     seg[rt].right = y;
     seg[rt].cov = 0;
     if ( x == y ) return ;
     int mid = seg[rt].mid();
     creat ( x, mid, rt << 1 );
     creat ( mid + 1, y, rt << 1 | 1 );
}
void insert ( int x, int y, int flag, int rt = 1 ) {
     //����߶α�����, ֱ�ӱ��, ����
    if ( seg[rt].left == x && seg[rt].right == y ) {
        seg[rt].cov = flag;
        return;
    }
    int LL = rt << 1, RR = rt << 1 | 1, mid = seg[rt].mid();
    if ( seg[rt].cov != -1 ) {
       //����߶��Ǳ����ǵ� , ����´�, ͬʱ������-1����ʾ�ж�����
        seg[LL].cov = seg[RR].cov = seg[rt].cov;
        seg[rt].cov = -1;
    }
    //�ݹ� ����
    if ( y <= mid ) insert ( x, y, flag, LL );
    else if ( x > mid ) insert ( x, y, flag, RR );
    else {
          insert ( x, mid, flag, LL );
          insert ( mid + 1, y, flag, RR );
    }
}
void query ( int x, int y, int rt = 1 ) {
    // �߶α����� , �����Ǳ�� ���� set
    if ( seg[rt].cov != -1 && seg[rt].left == x && seg[rt].right == y ) {
        st.insert ( seg[rt].cov );
        return ;
    }else {//�ݹ��ѯ
          int LL = rt << 1, RR = rt << 1 | 1, mid = seg[rt].mid();
          if ( y <= mid ) query ( x, y, rt << 1 );
          else if ( x > mid ) query ( x, y, rt << 1 | 1 );
          else {
                query ( x, mid, LL );
                query ( mid + 1, y, RR );
          }
    }
}
void print () {
     for ( set<int>::iterator it = st.begin(); it != st.end(); ++ it )
           cout << *it << endl;
}
int main ()
{
    scanf ( "%d", &T );
    creat ( 1, 20010 );
    while ( T -- ) {
           mp.clear();
           st.clear ();
           scanf ( "%d", &N );
           for ( int i = 1; i <= N; ++ i ) {
                scanf ( "%d%d", &pp[i].left, &pp[i].right );
                 //map ȥ��
                mp[pp[i].left] = 88; mp[pp[i].right] = 88;
           }
           beg = mp.begin(), end = mp.end();
           //��Ϊmap �Ѿ��Զ�������,����ֱ�Ӵ� 1 --> N ��ʼ���, ��ɢ��
           for ( int i = 1;beg != end; ++ beg, ++ i ) {
                beg->second = i;
           }
           //��Ϊ�߶����Ѿ���������, ����û��Ҫÿ�ζ��ؽ�һ��, ֻҪ����һ��
           //������������� �װ� ������
           insert ( 1, N * 2, 0 );
           for ( int i = 1; i <= N; ++ i ) {
                //����ɢ��ı�� ���� �߶�
                insert ( mp[pp[i].left], mp[pp[i].right], i );
           }
           query ( 1, N * 2 );
           //print();
           int cnt = st.size();
           if ( *st.begin() == 0 ) -- cnt;
           printf ( "%d\n", cnt );
    }

    return 0;
}
