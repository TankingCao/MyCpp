#include<iostream>
using namespace std;
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
void Init()
{                                                                                                                                                 //初始化算法
      int i,j;
      cout<<"请输入进程的数目:";
      cin>>m;
      cout<<"请输入资源种类的数目:";
      cin>>n;
      cout<<"请输入每个进程最大需求资源数矩阵:"<<endl;
      for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>Max[i][j];
			}
		}
      cout<<"请输入每个进程已分配的各资源数矩阵:"<<endl;
      for(i=0;i<m;i++)            //判断输入的资源数是否合理
      { 
	  	for(j=0;j<n;j++)
	  	{
			cin>>Allocation[i][j];
			Need[i][j]=Max[i][j]-Allocation[i][j];//各进程尚需要的资源数
 			if(Need[i][j]<0)
	 		{
				cout<<"您输入的第"<<i+1<<"个进程的第"<<j+1<<"个资源数有错误,请重新输入:"<<endl;
				j--;
  				continue;
 			}
		}
      }
      cout<<"请输入可利用资源向量矩阵:"<<endl;
      for(i=0;i<n;i++)
		cin>>Available[i];
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
		 else  continue;  
	  }
		if(l==m)  //如果系统是安全的，将资源分配给进程
        {   
			cout<<"此时系统是安全的"<<endl;
			cout<<"安全序列为:"<<endl;
		 	for(i=0;i<l;i++)
			{
				cout<<p[i];
				if(i!=l-1)
					cout<<"-->";
			}
			cout<<""<<endl;
			return true; 
		}  
	}
	cout<<"此时系统是不安全的"<<endl;
 	return false;
}
void Bank()                  /*银行家算法*/
{
      int i,cusneed;
      char again;
      while(1)
      {
          cout<<"请输入要申请资源的进程号(第1个进程号为0,依次类推)"<<endl;
          cin>>cusneed;
          cout<<"请输入进程的各资源需求矩阵"<<endl;
          for(i=0;i<n;i++)
          {
              cin>>Request[cusneed][i];
          }
          for(i=0;i<n;i++)
          {
             if(Request[cusneed][i]>Need[cusneed][i])
              {
                  cout<<"您输入的请求数超过进程的需求量!请重新输入!"<<endl;
                  continue;
              }
             if(Request[cusneed][i]>Available[i])
              {
                  cout<<"您输入的请求数超过系统拥有的资源数!请重新输入!"<<endl;
   				  continue;
              }
          }
          for(i=0;i<n;i++)    //假如系统将资源分配给p[i]
          {
             Available[i]-=Request[cusneed][i];                     
             Allocation[cusneed][i]+=Request[cusneed][i];
             Need[cusneed][i]-=Request[cusneed][i];
          }
          if(Safe())               //执行判断是否安全函数
          {
              cout<<"同意分配请求!"<<endl;
          }
          else
          {
              cout<<"您的请求被拒绝!"<<endl;
              for(i=0;i<n;i++)                  //不安全的，回复资源分配表
              {
                 Available[i]+=Request[cusneed][i];
                 Allocation[cusneed][i]-=Request[cusneed][i];
                 Need[cusneed][i]+=Request[cusneed][i];
              }
          }
          for(i=0;i<m;i++)
          {
              Finish[i]=false;
          }
          cout<<"您还想再次请求分配吗?是请按y/Y,否请按其它键"<<endl;
          cin>>again;
          if(again=='y'||again=='Y')
          {
              continue;
          }
          break;
          }
}
void main()
{
      Init();
      Safe();
      Bank();
}
