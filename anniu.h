#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#ifndef ANNIU
#define ANNIU
void anniu()
{
	void zengjiayuangong();
	void chakanyuangong();
	void xiugaixinxi();
	int n;
	cout<<"**********************************"<<endl;
	cout<<"|         人力资源管理系统       |"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"|     1---增加员工信息           |"<<endl;
	cout<<"|     2---查看员工信息           |"<<endl;
	cout<<"|     3---修改员工信息           |"<<endl;
	cout<<"**********************************"<<endl;
	cout<<"   请选择菜单序号：";
	cin>>n;
	switch(n)
	{
	case 1:zengjiayuangong();break;
	case 2:chakanyuangong();break;
	case 3:xiugaixinxi();break;
	}
}
void chakanyuangong()
{
	Basic_level_employee  a[N]={Basic_level_employee("Mary","female",20,3,10000,"4069892",
		"Beijing",1000,"university","liang","manager","you","142327199304122365",1,
		"xiaoshou","2009.8.9"),Basic_level_employee("Bob","male",19,1,1000,"4069878",
		"changsha",100,"zhuanke","so-so","staff","zhong","141125199401230062",2,"renshi",
		"2011.9.6"),Basic_level_employee("Lily","female",34,10,10000,"4305679","Amarica",
		2000,"university","you","staff","you","142327199701240096",3,"xiaoshou","1991.5.6"),
		Basic_level_employee("Jam","female",53,23,5000,"4356214","wuhan",2500,"zhuanke","liang",
		"staff","you","145236197011234236",4,"xiaoshou","1980.1.6"),Basic_level_employee(
		"Jerry","female",40,11,2500,"4025263","shanxi",1000,"postgraduate","liang","staff",
		"liang","152345188005260062",5,"renshi","1999.3.6"),Basic_level_employee("lisi","female",
		25,3,3000,"1234567","yinchuan",500,"university","cha","staff","liang",
		"156245188302300025",6,"xiaoshou","1999.1.2"),Basic_level_employee("Jim","male",40,12,6000,"5045060",
		"New York",1500,"postgraduate","zhong","staff","zhong","141125197802150042",7,"renshi",
		"1998.2.5"),Basic_level_employee("Jack","male",23,1,2000,"4023506","Tokyo",1000,"zhuanke",
		"you","staff","liang","142327199002300052",8,"xiaoshou","2010.2.12"),Basic_level_employee(
        "J.J","male",26,5,1500,"5045024","Beijing",100,"university","zhong","staff","cha",
		"142125199204190032",9,"xiaoshou","2011.2.6"),Basic_level_employee("lichao","male",
		19,1,2600,"5055000","fuzhou",1000,"postgraduate","you","staff","liang",
		"141124199409160025",10,"xiaoshou","2011.9.6")};


	int i=1;
	a[i].condition(a);
}
void zengjiayuangong()
{
	FILE *fp;
	char ch;
//	char name[10];
	if((fp=fopen("filel.dat","r+"))==NULL)
	{
		printf("cannot open filel\n");
		exit(0);
	}

	printf("姓名：\t");
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("性别\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("年龄\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("工资\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("联系方式\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("住址\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("奖金\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("文化程度\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("身体状况\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("职位\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("身份证号\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("工号\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("入职日期\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	putchar('\n');
	fclose(fp);
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
void xiugaixinxi()
{
	void xiugai();
	void xuanzexiugai();
	FILE *fp;
	char ch;
	if((fp=fopen("filel.dat","r+"))==NULL)
	{
		printf("cannot open filel");
		exit(0);
	}
	xuanzexiugai();
	printf("输入您要查看的员工编号：\n");
	int n;
	scanf("%d",&n);
	fseek(fp,n,SEEK_CUR);
	while(ch!='#')
	{
		ch=fgetc(fp);
		putchar(ch);
	}
	printf("\n");
	rewind(fp);
	ch=getchar();
	printf("姓名：\t");
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("性别\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("年龄\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("工资\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("联系方式\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("住址\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("奖金\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("文化程度\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("身体状况\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("职位\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("身份证号\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("工号\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	printf("入职日期\t");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		ch=getchar();
	}
	fclose(fp);
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
void xuanzexiugai()
{
	printf("0    Mary ");
	printf("\n");
	printf("359 Bob ");printf("\n");
	printf("718  Lily");printf("\n");
	printf("1077  Jam");printf("\n");
	printf("1436  Jerry");printf("\n");
	printf("1795 lisi");printf("\n");
	printf(" 2154 Jim");printf("\n");
	printf("2513  Jack ");printf("\n");
	printf("2872  J.J ");printf("\n");
	printf("3231  lichao");printf("\n");
}


#endif
