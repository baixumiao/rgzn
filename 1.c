//广度优先 
#include<stdio.h>

struct node
{
    int xy[3][3];
    int dir;
};
struct node sh[102],end;
int count=1; 
void input()
{
    printf("输入起始节点的位置:\n");
    int i,j;
    for (i=0; i<3;i++)
        for (j=0; j<3;j++)
            scanf("%d",&sh[0].xy[i][j]);
    sh[0].dir=-1;
    printf("输入目标节点的位置:\n");
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
            scanf("%d",&sh[101].xy[i][j]);
    sh[101].dir=-1;
}
int loction(int num)
{
    int i;
    for(i=0;i<9;i++)
        if(sh[num].xy[i/3][i%3]==0) 
			return i;
}
int sign(int num)
{
    int sum;
    sum=sh[num].xy[0][0]*100000000+sh[num].xy[0][1]*10000000 
		+sh[num].xy[0][2]*1000000+sh[num].xy[1][0]*100000 
		+sh[num].xy[1][1]*10000+sh[num].xy[1][2]*1000 
		+sh[num].xy[2][0]*100+sh[num].xy[2][1]*10 
		+sh[num].xy[2][2];
    return sum;
}
void move(int num)
{
    int t;
    int loc;
    int up=1,down=1,left=1,right=1;
    loc=loction(num);
    int stand=sh[num].dir;
    if(loc/3!=0&&stand!=1)
    {
        sh[count]=sh[num];
        t=sh[count].xy[loc/3][loc%3];
        sh[count].xy[loc/3][loc%3]=sh[count].xy[loc/3-1][loc%3];
        sh[count].xy[loc/3-1][loc%3]=t;
        sh[count].dir=3;
        count++;
    };
    if(loc/3!=2&&stand!=3)
    {
        sh[count]=sh[num];
        t=sh[count].xy[loc/3][loc%3];
        sh[count].xy[loc/3][loc%3]=sh[count].xy[loc/3+1][loc%3];
        sh[count].xy[loc/3+1][loc%3]=t;
        sh[count].dir=1;
        count++;
    }
    if(loc%3!=0&&stand!=0)
    {
        sh[count]=sh[num];
        t=sh[count].xy[loc/3][loc%3];
        sh[count].xy[loc/3][loc%3]=sh[count].xy[loc/3][loc%3-1];
        sh[count].xy[loc/3][loc%3-1]=t;
        sh[count].dir = 2;
        count++;
    }
    if(loc%3!=2&&stand!=2)
    {
        sh[count]=sh[num];
        t=sh[count].xy[loc/3][loc%3];
        sh[count].xy[loc/3][loc%3]=sh[count].xy[loc/3][loc%3+1];
        sh[count].xy[loc/3][loc%3+1]=t;
        sh[count].dir=0;
        count++;
    }
 
}
int search()
{
    int i=0;
    while(1)
    {
        if(i==100)
        {
            printf("超出了上限次数n");
            return 0;
        }
        if(sign(i)==sign(101))
        {
            printf("在第%d次找到了\n",i);
            return i;
        }
        move(i);
        i++;
    }
}
int main()
{
    input();
    search();
    return 0;
}