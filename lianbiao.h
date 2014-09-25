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
	char sex;            //F��ʾ�У�M��ʾŮ
	char tel[2][15];          //�ɴ�������绰��Ϣ
	char email[30];
	char jifen[7];
	char money[7];
	struct GK *next;
};
int n;
struct GK *head;


void writefile(GK *G)             //���ļ�����������
{
	char s[20];
	strcpy(s,G->ID);
	strcat(s,".txt");
	ofstream os(s,ios_base::out|ios_base::binary);
	os.write(reinterpret_cast<char * >(G),L);
	os.close();
}

void print(struct GK * p)                   //�������ĺ���
{
		cout<<"ID:"<<p->ID<<endl;
		cout<<"������"<<p->name<<endl;
		cout<<"�Ա�"<<p->sex<<endl;
   		cout<<"��ϵ��ʽ��1����"<<p->tel[0]<<endl;
		cout<<"��ϵ��ʽ��2����"<<p->tel[1]<<endl;
		cout<<"�������䣺"<<p->email<<endl;
		cout<<"���֣�"<<p->jifen<<endl;
		cout<<"ʣ���ʽ�"<<p->money<<endl;
}


void readfile(char s[])        //��ȡ�ļ��е�����
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
		cout<<"��ȡ�ļ�ʧ��!!"<<endl;
		exit(1);
	}
}

# endif