#ifndef goods1_h
#define goods1_h

# include <iostream>
# include <fstream>
# include <string.h>
#include <conio.h>
using namespace std;



//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌商品类﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
class commodity      //定义商品类
{
public:
	char name[20];
	char Id[20];
	float buy;//进货价；
	float sale;//卖出价；
	int amount;//数量；
	float sum;//利润；
	commodity * Next;
	void Input()   //录入商品的信息
	{
		cout<<"\t\t请输入商品的名称：";  cin>>name;
		cout<<"\t\t请输入商品的编号：";  cin>>Id;
		cout<<"\t\t请输入进货价："; cin>>buy;
		cout<<"\t\t请输入售出价："; cin>>sale;
		cout<<"\t\t请输入商品数量："; cin>>amount;
		sum=(sale-buy)*amount;       //计算利润 
	}


	void ReadFile(istream & in)    //读取文件的数据
	{
		in>>name>>Id>>sale>>buy>>sum;
	}


	void Show()     //显示商品的信息
	{
		cout<<"商品名"<<name<<endl<<"编号:"<<Id<<endl<<"进货价"<<buy<<"售出价"<<sale<<"商品数量:"<<
		amount<<"预计总利润："<<sum<<endl<<endl<<endl;
	}
 
};

//﹌﹌﹌﹌﹌﹌﹌﹌﹌商品信息类﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
class Commoditymassage
{
public:
	Commoditymassage();
	~Commoditymassage();
	void ShowMenu();    //显示主菜单
	void Find();         
	void Save();
	void ModifyItem();    //修改
	void RemoveItem();   
	void Swap(commodity *,commodity *); //???????
	void Sort();     
	int ListCount();
 
 
	void Display()    //刚刚开始界面
	{
		for(commodity * p=Head->Next;p!=End;p=p->Next)
			p->Show();
		cout<<"输入任意字符！继续……";
		getch();
	}
 
 
 
 
 //添加信息成功的判断
	void AddItem()    
	{
		End->Input();
		End->Next=new commodity;
		End=End->Next;
		cout<<"添加成功!"<<endl;
		cout<<"输入任意字符！继续……";
		getch();
	}
private:
	commodity * Head,* End;
	ifstream in;
	ofstream out;

//按照商品的名称查找
	commodity *FindItem(char * name)    
	{
		for(commodity * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上一个指针，不成功就返回空
		if(!strcmp(p->Next->name,name))return p;
		return NULL;
	}




//按照商品的编号查找
	commodity *FindID(char * Id)
	{
		for(commodity * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上一个指针，不成功就返回空
		if(!strcmp(p->Next->Id,Id))return p;
		return NULL;
	}
};

Commoditymassage Grade;        //声明为全局变量		



//﹌﹌﹌﹌﹌﹌﹌﹌构造函数的实现﹌﹌﹌﹌﹌﹌﹌﹌
Commoditymassage::Commoditymassage()
{
	Head=new commodity;
	Head->Next=new commodity;
	End=Head->Next;
	in.open("sort.txt");
	if(!in)
		cout<<"无商品信息。请先输入。"<<endl;
	else
	{
		while(!in.eof())
		{
			End->ReadFile(in);
			if(End->name[0]=='\0')
				break;
			End->Next=new commodity;
			End=End->Next;
		}
		in.close();
		cout<<"\t读取信息成功!"<<endl;
	}
}



//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌析构函数的实现﹌﹌﹌﹌﹌﹌﹌﹌
Commoditymassage::~Commoditymassage()
{
	Save();
	for(commodity * temp;Head->Next!=End;)
	{
		temp=Head->Next;
		Head->Next=Head->Next->Next;
		delete temp;
	}
	delete Head,End;
}


//菜单显示
void Commoditymassage::ShowMenu()                  
{
	cout<<"**********************  超 市 商 品 管 理 系  统  ***************************"<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"*****************          1.增加超市商品        *******************"<<endl;
	cout<<"*****************          2.显示超市商品        *******************"<<endl;
	cout<<"*****************          3.排序统计商品        *******************"<<endl;
	cout<<"*****************          4.查找超市商品        *******************"<<endl;
	cout<<"*****************          5.删除超市商品        *******************"<<endl;
	cout<<"*****************          6.修改超市商品        *******************"<<endl;
	cout<<"*****************          0.安全退出系统        *******************"<<endl;
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"\n\t\t\n\t\t请选择：";
}



//查找函数
void Commoditymassage::Find()
{
	char name[20] ,Id[10];
	int x;
	commodity * p=NULL;
	cout<<"\n\t\t*********************************\n";
	cout<<"\t\t※ 1.按商品的名称查找\n\t\t※ 2.按商品编号查找";
	cout<<"\n\t\t*********************************\n请选择：";
	cin>>x;
	switch(x)
	{
	case 1:
		{
			cout<<"\t\t请输入要查找的商品的名称：";
			cin>>name;
			if(p=FindItem(name))
			{
				p->Next->Show();
				cout<<"输入任意字符！继续……";
				getch();
			}
			else
			{
				cout<<"\t\t没有找到该名称的商品！"<<'\n'<<endl;
				cout<<"输入任意字符！继续……";
				getch();
			}
		}
		break;
	case 2:
	{
		cout<<"\t\t请输入要查找的商品的编号：";cin>>Id;
		if(p=FindID(Id))
		{
			p->Next->Show();
			cout<<"输入任意字符！继续……";
			getch();
		}
		else
		{
			cout<<"\t\t没有找到该编号的商品！"<<'\n'<<endl;
			cout<<"输入任意字符！继续……";
			getch();
		}
	}
	break;
	
	}
}




//（类函数的实现）

//修改商品信息
void Commoditymassage::ModifyItem()     //修改商品信息
{
	char name[20];
	commodity * p=NULL;
	cout<<"\t\t请输入要修改的商品的名称:";cin>>name;
	if(p=FindItem(name))
	{
		cout<<"\t\t已找到商品的信息，请输入新的信息!"<<endl;
		p->Next->Input();
		cout<<"修改成功！"<<endl;
		cout<<"输入任意字符！继续……";
		getch();
	}
	else
	{
		cout<<"\t\t没有找到!"<<endl;
		cout<<"输入任意字符！继续……";
		getch();
	}
}



//删除信息
void Commoditymassage::RemoveItem()         // 删除信息
{
	char name[20];
	commodity * p=NULL,*temp=NULL;
	cout<<"\t\t请输入要删除的商品的名称:"<<endl;cin>>name;
	if(p=FindItem(name))
	{
		temp=p->Next;
		p->Next=p->Next->Next; 
		delete temp;
		cout<<"\t\t删除成功!"<<endl;
		cout<<"输入任意字符！继续……";
		getch();
	}
	else
	{
		cout<<"\t\t没有找到!"<<endl;
		cout<<"输入任意字符！继续……";
		getch();
	}
}


//排序  交换编号不同的商品
void Commoditymassage::Swap(commodity *p1, commodity *p2)//交换两个combox变量的数据域
{
	commodity *temp=new commodity; 
 
	strcpy(temp->name,p1->name);
	strcpy(temp->Id,p1->Id);
	temp->sale=p1->sale;
	temp->buy=p1->buy;
	temp->sum=p1->sum;
 
	strcpy(p1->name,p2->name);
	strcpy(p1->Id,p2->Id);
	p1->sale=p2->sale;
	p1->buy=p2->buy;
	p1->sum=p2->sum;
 
	strcpy(p2->name,temp->name);
	strcpy(p2->Id,temp->Id);
	p2->sale=temp->sale;
	p2->buy=temp->buy;
	p2->sum=temp->sum;
}

//链表节数统计
int Commoditymassage::ListCount()//统计当前链表的记录总数，返回一个整数
{
	if(! Head)
		return 0;
	int n=0;
	for(commodity * p=Head->Next;p!=End;p=p->Next)
	{
		n++;
	}
	return n;
}




//对商品编号从小到大的排序
void Commoditymassage::Sort()//对当前链表进行排序
{ 
	cout <<"Sorting..."<<endl;
	system("pause");
	commodity *p=NULL,*p1=NULL,*k=NULL;
	int n=Commoditymassage::ListCount();
	if(n<2) 
		return;
	for(p=Head->Next;p!=End;p=p->Next)
		for(k=p->Next;k!=End;k=k->Next)
		{
			if(p->sum>k->sum)
			{
				Commoditymassage::Swap(p,k);
			}
		}
	cout <<"排序完成！"<<endl;
	getch();
	return;
}

//保存函数
void Commoditymassage::Save()
{
	out.open("sort.txt");
	for(commodity *p=Head->Next;p!=End;p=p->Next)
	out<<p->name<<"\t"<<p->Id<<"\t"<<p->buy<<"\t"<<p->sale<<"\t"<<p->sum<<"\n";
	out.close();
}

//登陆
void welcome()
{
	char manage[10],password[10];
	cout<<"\t*****************登陆*****************"<<endl;
	cout<<"              (用户名为：123456，密码为123)"<<endl;
	cout<<"\t     用户名：";
	cin>>manage;
	cout<<"\t     密码：";
	char c;
	int l=0;             //用来存储密码的长度
	while(l<9&&(c=getch())!='\r')           //当输入的字符不是回车键时，getch()函数可以不显示输入的信息
		{
			if(c!='\b')        //当输入的字符不是退格键时
			{
				password[l++]=c;
				putch('*');         //通过显示"*"，了解用户输入的位数
			}
			else if(l>0)
			{
				--l;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
		}
		password[l]='\0';
	if(strcmp(manage,"123456")==0)
	{
		if(strcmp(password,"123")==0)
		{
			cout<<"登陆成功！"<<endl;
		}
		else
		{	
			cout<<"密码不正确，请重试！"<<endl;
			welcome();
		}
	}
	else
	{
		cout<<"不存在该用户，请重试！"<<endl;
		welcome();
	}
}


void goods1()
{
	int x,i=0;
	bool quit=false;
	cout<<"\t********************************************"<<endl;
	cout<<"\t  ◎                                  ◎"<<endl;
	cout<<"\t  ◎                                  ◎"<<endl;
	cout<<"\t  ◎                                  ◎"<<endl;
	cout<<"\t  ◎      欢迎进入超市商品管理系统    ◎ "<<endl;
	cout<<"\t  ◎                                  ◎"<<endl;
	cout<<"\t  ◎                                  ◎"<<endl;
	cout<<"\t  ◎                                  ◎"<<endl;
	cout<<"\t********************************************"<<endl;
	cout<<"\n\n\n";
	welcome();
	
	cout<<"按任意键开始……";
	getch();
	while(!quit)
	{
		system("cls");
		Grade.ShowMenu();
		cin>>x;
		switch(x)
		{
		case 0:quit=true;break;
		case 1:Grade.AddItem();break;
		case 2:Grade.Display();break;
		case 3:Grade.Sort();break;
		case 4:Grade.Find();break;
		case 5:Grade.RemoveItem();break;
		case 6:Grade.ModifyItem();break;
		}
	}
}


#endif