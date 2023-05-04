#include<stdio.h>
#include<stdlib.h>
#define MAXPROCESS 50                          //最大进程数
#define MAXRESOURCE 100                          //最大资源数
int Available[MAXRESOURCE];                     //可用资源数组
int Max[MAXPROCESS][MAXRESOURCE];             //最大需求矩阵
int Allocation[MAXPROCESS][MAXRESOURCE];     //分配矩阵
int Need[MAXPROCESS][MAXRESOURCE];             //需求矩阵
int Request[MAXPROCESS][MAXRESOURCE];          //进程需要资源数
bool Finish[MAXPROCESS];                         //系统是否有足够的资源分配
int p[MAXPROCESS];                              //记录序列
int m,n;                                     //m个进程,n个资源
void Init()//初始化算法
{    
    int i,j;
    printf("请输入进程的数目:");
    scanf("%d", &m);
    printf("请输入资源种类的数目:");
    scanf("%d", &n);
    printf("请输入每个进程最大需求资源数矩阵:\\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &Max[i][j]);
        }
    }
    printf("请输入每个进程已分配的各资源数矩阵:\\n");
    for(i=0;i<m;i++)            //判断输入的资源数是否合理
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &Allocation[i][j]);
            Need[i][j]=Max[i][j]-Allocation[i][j];//各进程尚需要的资源数
            if(Need[i][j]<0)
            {
                printf("您输入的第%d个进程的第%d个资源数有错误,请重新输入:\\n", i+1, j+1);
                j--;
                continue;
            }
        }
    }
    printf("请输入可利用资源向量矩阵:\\n");
    for(i=0;i<n;i++)
        scanf("%d", &Available[i]);
}
bool Safe()                                     //判断安全函数
{ 	int i,j,k,l=0;
    int Work[MAXRESOURCE];    //系统可提供给进程继续运行所需要的各类资源数目
    for(i=0;i<n;i++)
        Work[i]=Available[i];
    for(i=0;i<m;i++)
        Finish[i]=false;
    for(i=0;i<m;i++)
    { if(Finish[i]==true)
            continue;
        else
        {
            for(j=0;j<n;j++)
                if(Need[i][j]>Work[j])
                    break;
            if(j==n)
            {
                Finish[i]=true;
                for(k=0;k<n;k++)
                    Work[k]+=Allocation[i][k];
                p[l++]=i;
                i=-1;
            }
            else
                continue;
        }
    }
    for(i=0;i<m;i++)
        if(!Finish[i])
        {
            printf("当前系统处于不安全状态,不存在安全序列\\n");
            return false;
        }
    printf("当前系统处于安全状态\\n");
    printf("存在一个安全序列:");
    for(i=0;i<l;i++)
        printf("p%d ",p[i]);
    printf("\\n");
    return true;
}
void Bank()
{
    int i,j,k,l=0;
    char again='y';
    while(again=='y'||again=='Y')
    {
        printf("请输入要申请资源的进程号(注:第1个进程号为0):");
        scanf("%d",&k);
        printf("请输入进程所请求的各资源的数量:\\n");
        for(i=0;i<n;i++)
            scanf("%d",&Request[k][i]);
        for(i=0;i<n;i++)
            if(Request[k][i]>Available[i])
            {
                printf("您输入的请求数超过系统有的资源数!请重新输入!\\n");
                goto loop;
            }
        for(i=0;i<n;i++)
        {
            Available[i]-=Request[k][i];
            Allocation[k][i]+=Request[k][i];
            Need[k][i]-=Request[k][i];
        }
        printf("当前系统可用资源向量为:\\n");
        for(i=0;i<n;i++)
            printf("%d ",Available[i]);
        printf("\\n");
        printf("当前系统分配矩阵为:\\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%d ",Allocation[i][j]);
            printf("\\n");
        }
        printf("当前系统需求矩阵为:\\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%d ",Need[i][j]);
            printf("\\n");
        }
        if(Safe())
        {
            printf("同意分配请求!\\n");
        }
        else
        {
            printf("您的请求被拒绝!\\n");
            for(i=0;i<n;i++)
            {
                Available[i]+=Request[k][i];
                Allocation[k][i]-=Request[k][i];
                Need[k][i]+=Request[k][i];
            }
        }
        loop:printf("您还想再次请求分配吗?是请按y/Y,否请按其它键\\n");
        scanf("%c",&again);
    }
}

int main()
{
    Init();
    Safe();
    Bank();
}
