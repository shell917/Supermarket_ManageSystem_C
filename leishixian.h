#include <iostream>
#include <string> 
#include "anniu.h"
#include "yuangong.h"
using namespace std;
int Basic_level_employee::j=1;
void Basic_level_employee::showname()//只显示员工姓名
{
//	for(int n=1;n<=N;n++)
	cout<<name<<endl;
}  
//判断“继续”还是“退出系统”的函数实现
void Basic_level_employee::judge()
{
	int b;
    cout<<"------------------------------------------"<<endl;
		   cout<<"输入1****************退出系统......"<<endl;
		   cout<<"输入2****************继续......"<<endl;
		   cout<<"------------------------------------------"<<endl;
		   cout<<"请输入1或2:"<<endl;
		   cin>>b;
		   switch(b)
		   {
		   case 1:cout<<"正在退出系统......"<<endl;
			   exit(0);
		   case 2:anniu();break;
		   }
}
//显示员工全部信息的函数实现
void Basic_level_employee::showinfor()
{
	
	cout<<"姓名\t";cout<<name<<"\t    "<<endl;
	cout<<"性别\t";cout<<sex<<"\t    "<<endl;
	cout<<"年龄\t";cout<<age<<"\t    "<<endl;
	cout<<"工龄\t";cout<<Length_of_service<<"\t    "<<endl;
	cout<<"工资\t";cout<<Wage<<"\t"<<endl;
	cout<<"联系方式\t";cout<<Way_of_contact<<"\t"<<endl;
	cout<<"住址\t";cout<<address<<"\t"<<endl;
    cout<<"奖金\t";cout<<Bonus<<"\t"<<endl;
	cout<<"文化程度\t";cout<<Cultural_level<<"\t"<<endl;
	cout<<"身体状况\t";cout<<Physical_condition<<"\t"<<endl;
	cout<<"职位\t";cout<<position<<"\t"<<endl;
	cout<<"业绩\t";cout<<Performance<<"\t"<<endl;
	cout<<"身份证号\t";	cout<<ID_number<<"\t"<<endl;
	cout<<"工号\t";cout<<Job_number<<"\t"<<endl;
    cout<<"部门\t";cout<<Department<<"\t"<<endl;
	cout<<"入职日期\t";cout<<Entry_date<<"\t"<<endl;
	cout<<"------------******************------------"<<endl;
}
//按条件查找的函数实现	
void Basic_level_employee::condition(Basic_level_employee c[N])
{
	int a,d,j,i;
	string s;
	bool flag=0;
	cout<<"--------------------------------------"<<endl;
	cout<<"|输入0*********************按姓名精确查找|"<<endl;
	cout<<"|输入1*********************按性别查找|"<<endl;
	cout<<"|输入2*********************按工龄查找|"<<endl;
	cout<<"|输入3*********************按工资查找|"<<endl;
	cout<<"|输入4*********************按业绩查找|"<<endl;
	cout<<"|输入5*********************按职位查找|"<<endl;
	cout<<"|输入6*********************按年龄查找|"<<endl;
	cout<<"|输入7*********************按部门查找|"<<endl;
	cout<<"|....................................|"<<endl;
//	cout<<"|    8 增加   9 删除   10 退出       |"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"请输入一个整数:"<<endl;
	cin>>a;
	switch(a)
	{
		//按姓名精确查找
	case 0:cout<<"------------------------------------------"<<endl;
		   cout<<"请输入员工姓名:"<<endl;
		   cin>>s;	   
		   cout<<"------------------------------------------"<<endl;
	   for( i=0;i<N;i++)
			   if(c[i].name==s)
			   {
				   c[i].showinfor();
				   flag=1;
			   }
			   if(flag==0)
	       cout<<"对不起，公司没有此人......"<<endl;
		   c[0].judge();
		   break;
		//按性别查找 
	case 1:cout<<"------------------------------------------"<<endl;
		   cout<<"|输入1*********************查看男员工信息|"<<endl;
	       cout<<"|输入2*********************查看女员工信息|"<<endl;
		   cout<<"------------------------------------------"<<endl;
		   cout<<"请输入整数1或2:"<<endl;
		   cin>>d;	   
		   cout<<"------------------------------------------"<<endl;
		   if(d==1)
		   {
			   
			   for( i=0;i<N;i++)
				   if(c[i].sex=="male")
				   {   
					   cout<<i<<"\t";
					   c[i].showname();
				   }
				   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==2) 
		   {
			 
			   for( i=0;i<N;i++)
				   if(c[i].sex=="female")
				   {
				
					   cout<<i<<"\t";
					   c[i].showname();
				   }
				   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //按工龄查找
	case 2:cout<<"---------------------------------------------------------"<<endl;
		   cout<<"|输入1*********************查看工龄为0~5年的员工信息   |"<<endl;
	       cout<<"|输入2*********************查看工龄为6~15年的员工信息  |"<<endl;
           cout<<"|输入3*********************查看工龄为15年以上的员工信息|"<<endl;
		   cout<<"---------------------------------------------------------"<<endl;
		   cout<<"请输入整数1、2或3:"<<endl;
		   cin>>d;	   
		   if(d==1)
		   {
			   for(i=0;i<N;i++)
			   {
				   if(c[i].Length_of_service>0&&c[i].Length_of_service<=5)
					   cout<<i<<"\t";
					   c[i].showname();
			   }
		     cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==2) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Length_of_service>6&&c[i].Length_of_service<=15)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			    cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==3) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Length_of_service>15)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			    cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //按工资查找
	case 3:cout<<"-----------------------------------------------------------"<<endl;
		   cout<<"|输入1*********************查看工资为500~1200元的员工信息 |"<<endl;
	       cout<<"|输入2*********************查看工资为1200~5000元的员工信息|"<<endl;
           cout<<"|输入3*********************查看工龄为5000元以上的员工信息 |"<<endl;
		   cout<<"-----------------------------------------------------------"<<endl;
		   cout<<"请输入整数1、2或3:"<<endl;
		   cin>>d;	   
		   if(d==1)
		   {
			   for(i=0;i<N;i++)
			   {
				   if(c[i].Wage>500&&c[i].Wage<=1200)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==2) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Wage>1200&&c[i].Wage<=5000)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==3) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Wage>5000)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //按业绩查找 
	case 4:cout<<"---------------------------------------------------------"<<endl;
		   cout<<"|输入1*********************查看业绩为优(you)的员工信息  |"<<endl;
	       cout<<"|输入2*********************查看业绩为良(liang)的员工信息|"<<endl;
           cout<<"|输入3*********************查看业绩为中(zhong)的员工信息|"<<endl;
		   cout<<"|输入4*********************查看业绩为差(cha)的员工信息  |"<<endl;
		   cout<<"---------------------------------------------------------"<<endl;
		   cout<<"请输入整数1、2、3或4:"<<endl;
		   cin>>d;	   
		   if(d==1)
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Performance=="you")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==2) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Performance=="liang")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==3) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Performance=="zhong")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==4) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Performance=="cha")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //按职位查找 
	case 5:cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"|输入1*********************查看职位为基层员工(staff)的员工信息|"<<endl;
	       cout<<"|输入2*********************查看职位为经理(manager)的员工信息  |"<<endl;
		   cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"请输入整数1或2:"<<endl;
		   cin>>d;	   
		   if(d==1)
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].position=="staff")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==2) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].position=="manager")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //按年龄查找
	case 6:cout<<"--------------------------------------------------------"<<endl;
		   cout<<"|输入1*********************查看年龄为18~25岁的员工信息 |"<<endl;
	       cout<<"|输入2*********************查看工资为26~35岁的员工信息 |"<<endl;
           cout<<"|输入3*********************查看工龄为36岁以上的员工信息|"<<endl;
		   cout<<"--------------------------------------------------------"<<endl;
		   cout<<"请输入整数1、2或3:"<<endl;
		   cin>>d;	   
		   if(d==1)
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].age>18&&c[i].age<=25)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==2) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].age>26&&c[i].age<=35)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   else if(d==3) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].age>36)
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //按部门查找
	case 7:cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"|输入1*********************查看部门为销售(xiaoshou)的员工信息|"<<endl;
	       cout<<"|输入2*********************查看部门为人事(renshi)的员工信息  |"<<endl;
		   cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"请输入整数1或2:"<<endl;
		   cin>>d;	   
		   if(d==1)
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Department=="xiaoshou")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
				   break;
		   }
		   else if(d==2) 
		   {
			   for( i=0;i<N;i++)
			   {
				   if(c[i].Department=="renshi")
				   {
					   cout<<i<<"\t";
					   c[i].showname();
				   }
			   }
			   cout<<"请选择您要查询的员工"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
	default:
		cout<<"正在退出查询系统"<<endl;
		exit(0);
	}
	}


