#include<stdio.h>
#include<string.h>
#include<malloc.h>

char handle[4][4];  //�洢�ַ�
int record[4][4];   //��¼ÿһλ��������

bool set_handle()
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        scanf("%s", handle[i]);
    }
    memset(record, 0, sizeof(record));
    return true;
}

char change_state(char state)
{
    if(state == '+')
        return '-';
    return '+';
}

//��m��n�еĿ��ذ���
void flip(int m, int n)
{
    int i, j;
    for(j = 0; j < 4; j++)  //�в���
    {
        handle[m][j] = change_state(handle[m][j]);
    }
    for(i = 0; i < 4; i++)  //�в���
    {
        if(i != m)
          handle[i][n] = change_state(handle[i][n]);
    }
    record[m][n]++; //ִ��һ�β���
}

//������������+λ�õ��к������еĿ���ִ��һ��flip����
void full_flip()
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(handle[i][j] == '+')
            {
                int t;
                for(t = 0; t < 4; t++)
                {
                    flip(i, t);
                }

                for(t = 0; t < 4; t++)
                {
                    if(t != i)
                    {
                       flip(t,j);
                    }

                }
            }
        }
    }
}


//����record���飬ͳ�Ʋ�������
void solute()
{
    int count = 0;
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(record[i][j] & 1  != 0)
            {
                count ++;
            }
        }
    }
    printf("%d\n", count);
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(record[i][j] & 1  != 0)
            {
                printf("%d %d\n", i+1, j+1);
            }
        }
    }

}

int main(void)
{
    while(set_handle())
    {
        full_flip();
        solute();
    }
    return 0;
}
