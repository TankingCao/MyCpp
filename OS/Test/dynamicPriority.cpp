/**
 *  <h1 color="#10ac84">Created by ľɼ on ��2023/4/22/ 022�� ���� 02:49:40</h1>
 */
#include<iostream>
#define getpch(type) (type*)malloc(sizeof(type))
using namespace std;

struct pcb { /* ������̿��ƿ�PCB */
    char name[10]; //������
    char state;    //����״̬��"W"-����̬��"R"-����̬
    int nice;      //�������ȼ�
    int ntime;     //��Ҫ����ʱ��
    int rtime;     //�Ѿ����е�ʱ��
    struct pcb* link;
}*ready=NULL,*p;
typedef struct pcb PCB;

void sort() /* �����Խ��̽������ȼ����к�������������������*/
{
    PCB *first, *second;
    int insert=0;
    if((ready==NULL)||((p->nice)>(ready->nice)))/*���ȼ������,�������*/
    {
        p->link=ready;
        ready=p;
    }
    else /* ���̱Ƚ����ȼ�,�����ʵ���λ����*/
    {
        first=ready;
        second=first->link;
        while(second!=NULL)
        {
            if((p->nice)>(second->nice)) /*��������̱ȵ�ǰ������������,*/
            { /*���뵽��ǰ����ǰ��*/
                p->link=second;
                first->link=p;
                second=NULL;
                insert=1;
            }
            else /* ����������������,����뵽��β*/
            {
                first=first->link;
                second=second->link;
            }
        }
        if(insert==0) first->link=p;
    }
}

void input() /* �������̿��ƿ麯��*/
{
    int i,num;
    cout<<"\n �����뱻���ȵĽ�����Ŀ��";
    cin>>num;
    for(i=0;i<num;i++)
    {
        cout<<"\n ���̺�No."<<i<<":";
        p=getpch(PCB);
        cout<<" ���������:";
        cin>>p->name;
        cout<<" �������������:";
        cin>>p->nice;
        cout<<" �����������ʱ��:";
        cin>>p->ntime;
        cout<<endl;
        p->rtime=0;
        p->state='W';
        p->link=NULL;
        sort(); /* ����sort����*/
    }
}

//ͳ�Ƶ�ǰ���������н��̵�����
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

void disp(PCB * pr) /*����������ʾ����,������ʾ��ǰ����*/
{
    cout<<endl<<"\n qname \t state \t nice \tndtime\truntime "<<endl;
    cout<<pr->name<<"\t";
    cout<<pr->state<<"\t";
    cout<<pr->nice<<"\t";
    cout<<pr->ntime<<"\t";
    cout<<pr->rtime<<"\t"<<endl;
}

void check() /* �������̲鿴���� */
{
    PCB* pr;
    cout<<"\n **** ��ǰ�������еĽ�����:"<<p->name<<endl;; /*��ʾ��ǰ���н���*/
    disp(p);
    pr=ready;
    if (pr!=NULL)
        cout<<"\n ****��ǰ��������״̬Ϊ:"<<endl; /*��ʾ��������״̬*/
    else
        cout<<"\n ****��ǰ��������״̬Ϊ: ��"<<endl; /*��ʾ��������״̬Ϊ��*/
    while(pr!=NULL)
    {
        disp(pr);
        pr=pr->link;
    }
}

void destroy() /*�������̳�������(�������н���,��������)*/
{
    cout<<" ����"<<p->name<<" �����."<<endl;
    free(p);
}

void running() /* �������̾�������(��������ʱ�䵽,�þ���״̬*/
{
    (p->rtime)++;
    if(p->rtime==p->ntime)
        destroy(); /* ����destroy����*/
    else {
        (p->nice)--;
        p->state='W';
        sort(); /*����sort����*/
    }
}

int main() /*������*/ {
    //h��¼ִ�д���
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
        cout<<"\n����һ������......"<<endl;
        getchar();
    }

    cout<<"\n\n���н����Ѿ�������ɣ�"<<endl;
    getchar();
    return 0;
}

