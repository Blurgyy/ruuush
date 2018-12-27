#include<cstdio>
#include<string.h>
#include<algorithm>
#define maxn 100010
using namespace std;

char board[6][6];
struct cord///����������λ�õ�����Ľṹ��
{
    int row;
    int col;
}ori[16];///�������������깲16��
bool as[16] = {false};///�������飬�������������Ӽ�

void board_init()///��������״̬
{
    char c;
    int i, j;
    int p = 0;
    for(i = 1; i < 5; i++)
        scanf("%s", board[i] + 1);
    for(i = 1; i < 5; i++)
        for(j = 1; j < 5; j++)
        {
            ori[p].row = i;
            ori[p++].col = j;
        }
}

void print_board()///�������״̬(just for debugging)
{
    int i, j;
    for(i = 1; i < 5; i++)
    {
        for(j = 1; j < 5; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

void flip(int row, int col, char ch[][6])///��ת����
{                                           /**row�У�col�У�ch����*/
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    int i;
    for(i = 0; i < 4; i++)
    {
        int nr = row + dx[i];
        int nc = col + dy[i];
        if(ch[nr][nc] == 'b')ch[nr][nc] = 'w';
        else ch[nr][nc] = 'b';
    }
    if(ch[row][col] == 'b')ch[row][col] = 'w';
    else ch[row][col] = 'b';
}

bool check(char ch[][6])///��������Ƿ��ѴﵽȫΪһɫ��״̬
{                       /**chΪҪ����������*/
    int i, j;
    char tmp = ch[1][1];
    for(i = 1; i <= 4; i++)
        for(j = 1; j <= 4; j++)
            if(ch[i][j] != tmp)return false;
    return true;
}

void init(char ch[][6])///����ԭʼ���̣����Ƴ���һ���������ں���ı�
{                       /**chΪ�����Ƴ�������*/
    int i, j;
    for(i = 1; i < 5; i++)
        for(j = 1; j < 5; j++)
        ch[i][j] = board[i][j];
}

bool Find(int num, char ch[][6])///���������Ӽ�������Ƿ��ܴﵽҪ��
{                               /**numΪҪ���ɵ��Ӽ��ĳ��ȣ� chΪ���ڼ�������*/
    int i;
    for(i = 0; i < num; i++)
        as[i] = true;
    do
    {
        init(ch);           ///ÿ�ζ�Ҫ��ʼ������
        for(i = 0; i < 16; i++)
            if(as[i]) flip(ori[i].row, ori[i].col, ch);
        if(check(ch))return true;///���κ�һ�εõ���ȫΪһɫֱ��return true
    }
    while(prev_permutation(as, as + 16));///prev_permutation��������ֵ����Ϊbool�������������ı�ʱ����false
    return false;///��δreturn true ��false
}

int main()
{
    int ans = 1000;///ans��ʼ��Ϊ1000
    int i, j;
    board_init();///��������
    char ch[6][6];
    for(i = 0; i < 16; i++)///0����15��ȫ�ж�
        if(Find(i, ch))ans = min(ans, i);///ÿ�ν�������С�Ĳ���
    if(ans == 1000)printf("Impossible\n");///ansֵδ�ı����Impossible
    else printf("%d\n", ans);
    return 0;
}
