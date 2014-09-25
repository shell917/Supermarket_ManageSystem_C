# ifndef lianbiao_h
# define lianbiao_h

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define L sizeof(struct GK)
struct GK
{
	char ID[7];
	char password[10];
	char name[10];
	char sex;            //F表示男，M表示女
	char tel[2][15];          //可存放两个电话信息
	char email[30];
	char jifen[7];
	char money[7];
	struct GK *next;
};
int n;
struct GK *head;


void writefile(GK *G)             //向文件中输入数据
{
	char s[20];
	strcpy(s,G->ID);
	strcat(s,".txt");
	ofstream os(s,ios_base::out|ios_base::binary);
	os.write(reinterpret_cast<char * >(G),L);
	os.close();
}

void print(struct GK * p)                   //输出链表的函数
{
		cout<<"ID:"<<p->ID<<endl;
		cout<<"姓名："<<p->name<<endl;
		cout<<"性别："<<p->sex<<endl;
   		cout<<"联系方式（1）："<<p->tel[0]<<endl;
		cout<<"联系方式（2）："<<p->tel[1]<<endl;
		cout<<"电子邮箱："<<p->email<<endl;
		cout<<"积分："<<p->jifen<<endl;
		cout<<"剩余资金："<<p->money<<endl;
}


void readfile(char s[])        //读取文件中的数据
{
	ifstream is(s,ios_base::in|ios_base::binary);	
	if(is)
	{
		GK *G=(GK *)malloc(L);
		is.read(reinterpret_cast<char *>(G),L);
		cout<<"******************"<<endl;
		print(G);
		cout<<"******************"<<endl;
		
	}
	else
	{
		cout<<"读取文件失败!!"<<endl;
		exit(1);
	}
}

# endif