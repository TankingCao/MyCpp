/**
 *  <h1 color="#10ac84">Created by 木杉 on 「2023/4/22/ 022」 下午 02:49:40</h1>
 */
#include<iostream>
#define getpch(type) (type*)malloc(sizeof(type))
using namespace std;

struct pcb { /* 定义进程控制块PCB */
    char name[10]; //进程名
    char state;    //进程状态："W"-就绪态，"R"-运行态
    int nice;      //进程优先级
    int ntime;     //需要运行时间
    int rtime;     //已经运行的时间
    struct pcb* link;
}*ready=NULL,*p;
typedef struct pcb PCB;

void sort() /* 建立对进程进行优先级排列函数，优先数大者优先*/
{
    PCB *first, *second;
    int insert=0;
    if((ready==NULL)||((p->nice)>(ready->nice)))/*优先级最大者,插入队首*/
    {
        p->link=ready;
        ready=p;
    }
    else /* 进程比较优先级,插入适当的位置中*/
    {
        first=ready;
        second=first->link;
        while(second!=NULL)
        {
            if((p->nice)>(second->nice)) /*若插入进程比当前进程优先数大,*/
            { /*插入到当前进程前面*/
                p->link=second;
                first->link=p;
                second=NULL;
                insert=1;
            }
            else /* 插入进程优先数最低,则插入到队尾*/
            {
                first=first->link;
                second=second->link;
            }
        }
        if(insert==0) first->link=p;
    }
}

void input() /* 建立进程控制块函数*/
{
    int i,num;
    cout<<"\n 请输入被调度的进程数目：";
    cin>>num;
    for(i=0;i<num;i++)
    {
        cout<<"\n 进程号No."<<i<<":";
        p=getpch(PCB);
        cout<<" 输入进程名:";
        cin>>p->name;
        cout<<" 输入进程优先数:";
        cin>>p->nice;
        cout<<" 输入进程运行时间:";
        cin>>p->ntime;
        cout<<endl;
        p->rtime=0;
        p->state='W';
        p->link=NULL;
        sort(); /* 调用sort函数*/
    }
}

//统计当前就绪队列中进程的数量
int space()
{
    int l=0; PCB* pr=ready;
    while(pr!=NULL)
    {
        l++;
        pr=pr->link;
    }
    return l;
}

void disp(PCB * pr) /*建立进程显示函数,用于显示当前进程*/
{
    cout<<endl<<"\n qname \t state \t nice \tndtime\truntime "<<endl;
    cout<<pr->name<<"\t";
    cout<<pr->state<<"\t";
    cout<<pr->nice<<"\t";
    cout<<pr->ntime<<"\t";
    cout<<pr->rtime<<"\t"<<endl;
}

void check() /* 建立进程查看函数 */
{
    PCB* pr;
    cout<<"\n **** 当前正在运行的进程是:"<<p->name<<endl;; /*显示当前运行进程*/
    disp(p);
    pr=ready;
    if (pr!=NULL)
        cout<<"\n ****当前就绪队列状态为:"<<endl; /*显示就绪队列状态*/
    else
        cout<<"\n ****当前就绪队列状态为: 空"<<endl; /*显示就绪队列状态为空*/
    while(pr!=NULL)
    {
        disp(pr);
        pr=pr->link;
    }
}

void destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/
{
    cout<<" 进程"<<p->name<<" 已完成."<<endl;
    free(p);
}

void running() /* 建立进程就绪函数(进程运行时间到,置就绪状态*/
{
    (p->rtime)++;
    if(p->rtime==p->ntime)
        destroy(); /* 调用destroy函数*/
    else {
        (p->nice)--;
        p->state='W';
        sort(); /*调用sort函数*/
    }
}

int main() /*主函数*/ {
    //h记录执行次数
    int len,h=0;
    input();
    len=space();
    while((len!=0)&&(ready!=NULL))
    {
        getchar();
        h++;
        cout<<"\n The excute number:"<<h<<endl;
        p=ready;
        ready=p->link;
        p->link=NULL;
        p->state='R';
        check();
        running();
        cout<<"\n按任一键继续......"<<endl;
        getchar();
    }

    cout<<"\n\n所有进程已经运行完成！"<<endl;
    getchar();
    return 0;
}

