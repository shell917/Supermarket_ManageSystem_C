#include <iostream>
#include <string> 
#include "anniu.h"
#include "yuangong.h"
using namespace std;
int Basic_level_employee::j=1;
void Basic_level_employee::showname()//ֻ��ʾԱ������
{
//	for(int n=1;n<=N;n++)
	cout<<name<<endl;
}  
//�жϡ����������ǡ��˳�ϵͳ���ĺ���ʵ��
void Basic_level_employee::judge()
{
	int b;
    cout<<"------------------------------------------"<<endl;
		   cout<<"����1****************�˳�ϵͳ......"<<endl;
		   cout<<"����2****************����......"<<endl;
		   cout<<"------------------------------------------"<<endl;
		   cout<<"������1��2:"<<endl;
		   cin>>b;
		   switch(b)
		   {
		   case 1:cout<<"�����˳�ϵͳ......"<<endl;
			   exit(0);
		   case 2:anniu();break;
		   }
}
//��ʾԱ��ȫ����Ϣ�ĺ���ʵ��
void Basic_level_employee::showinfor()
{
	
	cout<<"����\t";cout<<name<<"\t    "<<endl;
	cout<<"�Ա�\t";cout<<sex<<"\t    "<<endl;
	cout<<"����\t";cout<<age<<"\t    "<<endl;
	cout<<"����\t";cout<<Length_of_service<<"\t    "<<endl;
	cout<<"����\t";cout<<Wage<<"\t"<<endl;
	cout<<"��ϵ��ʽ\t";cout<<Way_of_contact<<"\t"<<endl;
	cout<<"סַ\t";cout<<address<<"\t"<<endl;
    cout<<"����\t";cout<<Bonus<<"\t"<<endl;
	cout<<"�Ļ��̶�\t";cout<<Cultural_level<<"\t"<<endl;
	cout<<"����״��\t";cout<<Physical_condition<<"\t"<<endl;
	cout<<"ְλ\t";cout<<position<<"\t"<<endl;
	cout<<"ҵ��\t";cout<<Performance<<"\t"<<endl;
	cout<<"���֤��\t";	cout<<ID_number<<"\t"<<endl;
	cout<<"����\t";cout<<Job_number<<"\t"<<endl;
    cout<<"����\t";cout<<Department<<"\t"<<endl;
	cout<<"��ְ����\t";cout<<Entry_date<<"\t"<<endl;
	cout<<"------------******************------------"<<endl;
}
//���������ҵĺ���ʵ��	
void Basic_level_employee::condition(Basic_level_employee c[N])
{
	int a,d,j,i;
	string s;
	bool flag=0;
	cout<<"--------------------------------------"<<endl;
	cout<<"|����0*********************��������ȷ����|"<<endl;
	cout<<"|����1*********************���Ա����|"<<endl;
	cout<<"|����2*********************���������|"<<endl;
	cout<<"|����3*********************�����ʲ���|"<<endl;
	cout<<"|����4*********************��ҵ������|"<<endl;
	cout<<"|����5*********************��ְλ����|"<<endl;
	cout<<"|����6*********************���������|"<<endl;
	cout<<"|����7*********************�����Ų���|"<<endl;
	cout<<"|....................................|"<<endl;
//	cout<<"|    8 ����   9 ɾ��   10 �˳�       |"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"������һ������:"<<endl;
	cin>>a;
	switch(a)
	{
		//��������ȷ����
	case 0:cout<<"------------------------------------------"<<endl;
		   cout<<"������Ա������:"<<endl;
		   cin>>s;	   
		   cout<<"------------------------------------------"<<endl;
	   for( i=0;i<N;i++)
			   if(c[i].name==s)
			   {
				   c[i].showinfor();
				   flag=1;
			   }
			   if(flag==0)
	       cout<<"�Բ��𣬹�˾û�д���......"<<endl;
		   c[0].judge();
		   break;
		//���Ա���� 
	case 1:cout<<"------------------------------------------"<<endl;
		   cout<<"|����1*********************�鿴��Ա����Ϣ|"<<endl;
	       cout<<"|����2*********************�鿴ŮԱ����Ϣ|"<<endl;
		   cout<<"------------------------------------------"<<endl;
		   cout<<"����������1��2:"<<endl;
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
				   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
				   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //���������
	case 2:cout<<"---------------------------------------------------------"<<endl;
		   cout<<"|����1*********************�鿴����Ϊ0~5���Ա����Ϣ   |"<<endl;
	       cout<<"|����2*********************�鿴����Ϊ6~15���Ա����Ϣ  |"<<endl;
           cout<<"|����3*********************�鿴����Ϊ15�����ϵ�Ա����Ϣ|"<<endl;
		   cout<<"---------------------------------------------------------"<<endl;
		   cout<<"����������1��2��3:"<<endl;
		   cin>>d;	   
		   if(d==1)
		   {
			   for(i=0;i<N;i++)
			   {
				   if(c[i].Length_of_service>0&&c[i].Length_of_service<=5)
					   cout<<i<<"\t";
					   c[i].showname();
			   }
		     cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			    cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			    cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //�����ʲ���
	case 3:cout<<"-----------------------------------------------------------"<<endl;
		   cout<<"|����1*********************�鿴����Ϊ500~1200Ԫ��Ա����Ϣ |"<<endl;
	       cout<<"|����2*********************�鿴����Ϊ1200~5000Ԫ��Ա����Ϣ|"<<endl;
           cout<<"|����3*********************�鿴����Ϊ5000Ԫ���ϵ�Ա����Ϣ |"<<endl;
		   cout<<"-----------------------------------------------------------"<<endl;
		   cout<<"����������1��2��3:"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //��ҵ������ 
	case 4:cout<<"---------------------------------------------------------"<<endl;
		   cout<<"|����1*********************�鿴ҵ��Ϊ��(you)��Ա����Ϣ  |"<<endl;
	       cout<<"|����2*********************�鿴ҵ��Ϊ��(liang)��Ա����Ϣ|"<<endl;
           cout<<"|����3*********************�鿴ҵ��Ϊ��(zhong)��Ա����Ϣ|"<<endl;
		   cout<<"|����4*********************�鿴ҵ��Ϊ��(cha)��Ա����Ϣ  |"<<endl;
		   cout<<"---------------------------------------------------------"<<endl;
		   cout<<"����������1��2��3��4:"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //��ְλ���� 
	case 5:cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"|����1*********************�鿴ְλΪ����Ա��(staff)��Ա����Ϣ|"<<endl;
	       cout<<"|����2*********************�鿴ְλΪ����(manager)��Ա����Ϣ  |"<<endl;
		   cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"����������1��2:"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //���������
	case 6:cout<<"--------------------------------------------------------"<<endl;
		   cout<<"|����1*********************�鿴����Ϊ18~25���Ա����Ϣ |"<<endl;
	       cout<<"|����2*********************�鿴����Ϊ26~35���Ա����Ϣ |"<<endl;
           cout<<"|����3*********************�鿴����Ϊ36�����ϵ�Ա����Ϣ|"<<endl;
		   cout<<"--------------------------------------------------------"<<endl;
		   cout<<"����������1��2��3:"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
		   //�����Ų���
	case 7:cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"|����1*********************�鿴����Ϊ����(xiaoshou)��Ա����Ϣ|"<<endl;
	       cout<<"|����2*********************�鿴����Ϊ����(renshi)��Ա����Ϣ  |"<<endl;
		   cout<<"--------------------------------------------------------------"<<endl;
		   cout<<"����������1��2:"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
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
			   cout<<"��ѡ����Ҫ��ѯ��Ա��"<<endl;
				   cin>>j;
				   c[j].showinfor();
		   }
		   c[0].judge();
		   break;
	default:
		cout<<"�����˳���ѯϵͳ"<<endl;
		exit(0);
	}
	}


