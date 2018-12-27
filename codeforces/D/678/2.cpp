#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

struct Matrix
{
    ll val[3][3];
    void unit(){
        memset(val, 0, sizeof(val));
        val[1][1] = val[2][2] = 1;
    }
}mat;
struct Line
{
    ll val[3];
    void init(){
        memset(val, 0, sizeof(val));
    }
}line;
ll a, b, n, x;

Line operator* (Line a, Matrix b){
    Line ret;
    ret.init();
    for(int i = 1; i <= 2; ++ i)
        for(int j = 1; j <= 2; ++ j){
            ret.val[i] += a.val[j] * b.val[j][i];
            ret.val[i] %= mod;
        }
    return ret;
}

Matrix operator* (Matrix a, Matrix b){
    Matrix ret;
    memset(ret.val, 0, sizeof(ret.val));
    for(int k = 1; k <= 2; ++ k)
        for(int i = 1; i <= 2; ++ i)
            for(int j = 1; j <= 2; ++ j){
                ret.val[i][j] += a.val[i][k] * b.val[k][j];
                ret.val[i][j] %= mod;
            }
    return ret;
}

Matrix fp(Matrix a, ll pow){
    Matrix ret;
    ret.unit();
    while(pow){
        if(pow&1)ret = ret * a;
        a = a * a;
        pow >>= 1;
    }
    return ret;
}

void init(){
    line.val[1] = x;
    line.val[2] = 1;
    mat.val[1][1] = a;
    mat.val[1][2] = 0;
    mat.val[2][1] = b;
    mat.val[2][2] = 1;
}

int main(){
    while(~scanf("%I64d%I64d%I64d%I64d", &a, &b, &n, &x)){
        init();
        printf("%I64d\n", (line*fp(mat, n)).val[1]);
    }
    return 0;
}