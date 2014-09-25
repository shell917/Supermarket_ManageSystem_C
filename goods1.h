#ifndef goods1_h
#define goods1_h

# include <iostream>
# include <fstream>
# include <string.h>
#include <conio.h>
using namespace std;



//�k�k�k�k�k�k�k�k�k�k��Ʒ��k�k�k�k�k�k�k�k�k�k�k
class commodity      //������Ʒ��
{
public:
	char name[20];
	char Id[20];
	float buy;//�����ۣ�
	float sale;//�����ۣ�
	int amount;//������
	float sum;//����
	commodity * Next;
	void Input()   //¼����Ʒ����Ϣ
	{
		cout<<"\t\t��������Ʒ�����ƣ�";  cin>>name;
		cout<<"\t\t��������Ʒ�ı�ţ�";  cin>>Id;
		cout<<"\t\t����������ۣ�"; cin>>buy;
		cout<<"\t\t�������۳��ۣ�"; cin>>sale;
		cout<<"\t\t��������Ʒ������"; cin>>amount;
		sum=(sale-buy)*amount;       //�������� 
	}


	void ReadFile(istream & in)    //��ȡ�ļ�������
	{
		in>>name>>Id>>sale>>buy>>sum;
	}


	void Show()     //��ʾ��Ʒ����Ϣ
	{
		cout<<"��Ʒ��"<<name<<endl<<"���:"<<Id<<endl<<"������"<<buy<<"�۳���"<<sale<<"��Ʒ����:"<<
		amount<<"Ԥ��������"<<sum<<endl<<endl<<endl;
	}
 
};

//�k�k�k�k�k�k�k�k�k��Ʒ��Ϣ��k�k�k�k�k�k�k�k�k�k�k�k
class Commoditymassage
{
public:
	Commoditymassage();
	~Commoditymassage();
	void ShowMenu();    //��ʾ���˵�
	void Find();         
	void Save();
	void ModifyItem();    //�޸�
	void RemoveItem();   
	void Swap(commodity *,commodity *); //???????
	void Sort();     
	int ListCount();
 
 
	void Display()    //�ոտ�ʼ����
	{
		for(commodity * p=Head->Next;p!=End;p=p->Next)
			p->Show();
		cout<<"���������ַ�����������";
		getch();
	}
 
 
 
 
 //�����Ϣ�ɹ����ж�
	void AddItem()    
	{
		End->Input();
		End->Next=new commodity;
		End=End->Next;
		cout<<"��ӳɹ�!"<<endl;
		cout<<"���������ַ�����������";
		getch();
	}
private:
	commodity * Head,* End;
	ifstream in;
	ofstream out;

//������Ʒ�����Ʋ���
	commodity *FindItem(char * name)    
	{
		for(commodity * p=Head;p->Next!=End;p=p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		if(!strcmp(p->Next->name,name))return p;
		return NULL;
	}




//������Ʒ�ı�Ų���
	commodity *FindID(char * Id)
	{
		for(commodity * p=Head;p->Next!=End;p=p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		if(!strcmp(p->Next->Id,Id))return p;
		return NULL;
	}
};

Commoditymassage Grade;        //����Ϊȫ�ֱ���		



//�k�k�k�k�k�k�k�k���캯����ʵ�֩k�k�k�k�k�k�k�k
Commoditymassage::Commoditymassage()
{
	Head=new commodity;
	Head->Next=new commodity;
	End=Head->Next;
	in.open("sort.txt");
	if(!in)
		cout<<"����Ʒ��Ϣ���������롣"<<endl;
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
		cout<<"\t��ȡ��Ϣ�ɹ�!"<<endl;
	}
}



//�k�k�k�k�k�k�k�k�k�k����������ʵ�֩k�k�k�k�k�k�k�k
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


//�˵���ʾ
void Commoditymassage::ShowMenu()                  
{
	cout<<"**********************  �� �� �� Ʒ �� �� ϵ  ͳ  ***************************"<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"*****************          1.���ӳ�����Ʒ        *******************"<<endl;
	cout<<"*****************          2.��ʾ������Ʒ        *******************"<<endl;
	cout<<"*****************          3.����ͳ����Ʒ        *******************"<<endl;
	cout<<"*****************          4.���ҳ�����Ʒ        *******************"<<endl;
	cout<<"*****************          5.ɾ��������Ʒ        *******************"<<endl;
	cout<<"*****************          6.�޸ĳ�����Ʒ        *******************"<<endl;
	cout<<"*****************          0.��ȫ�˳�ϵͳ        *******************"<<endl;
	cout<<"______________________________________________________________________________"<<endl;
	cout<<"\n\t\t\n\t\t��ѡ��";
}



//���Һ���
void Commoditymassage::Find()
{
	char name[20] ,Id[10];
	int x;
	commodity * p=NULL;
	cout<<"\n\t\t*********************************\n";
	cout<<"\t\t�� 1.����Ʒ�����Ʋ���\n\t\t�� 2.����Ʒ��Ų���";
	cout<<"\n\t\t*********************************\n��ѡ��";
	cin>>x;
	switch(x)
	{
	case 1:
		{
			cout<<"\t\t������Ҫ���ҵ���Ʒ�����ƣ�";
			cin>>name;
			if(p=FindItem(name))
			{
				p->Next->Show();
				cout<<"���������ַ�����������";
				getch();
			}
			else
			{
				cout<<"\t\tû���ҵ������Ƶ���Ʒ��"<<'\n'<<endl;
				cout<<"���������ַ�����������";
				getch();
			}
		}
		break;
	case 2:
	{
		cout<<"\t\t������Ҫ���ҵ���Ʒ�ı�ţ�";cin>>Id;
		if(p=FindID(Id))
		{
			p->Next->Show();
			cout<<"���������ַ�����������";
			getch();
		}
		else
		{
			cout<<"\t\tû���ҵ��ñ�ŵ���Ʒ��"<<'\n'<<endl;
			cout<<"���������ַ�����������";
			getch();
		}
	}
	break;
	
	}
}




//���ຯ����ʵ�֣�

//�޸���Ʒ��Ϣ
void Commoditymassage::ModifyItem()     //�޸���Ʒ��Ϣ
{
	char name[20];
	commodity * p=NULL;
	cout<<"\t\t������Ҫ�޸ĵ���Ʒ������:";cin>>name;
	if(p=FindItem(name))
	{
		cout<<"\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!"<<endl;
		p->Next->Input();
		cout<<"�޸ĳɹ���"<<endl;
		cout<<"���������ַ�����������";
		getch();
	}
	else
	{
		cout<<"\t\tû���ҵ�!"<<endl;
		cout<<"���������ַ�����������";
		getch();
	}
}



//ɾ����Ϣ
void Commoditymassage::RemoveItem()         // ɾ����Ϣ
{
	char name[20];
	commodity * p=NULL,*temp=NULL;
	cout<<"\t\t������Ҫɾ������Ʒ������:"<<endl;cin>>name;
	if(p=FindItem(name))
	{
		temp=p->Next;
		p->Next=p->Next->Next; 
		delete temp;
		cout<<"\t\tɾ���ɹ�!"<<endl;
		cout<<"���������ַ�����������";
		getch();
	}
	else
	{
		cout<<"\t\tû���ҵ�!"<<endl;
		cout<<"���������ַ�����������";
		getch();
	}
}


//����  ������Ų�ͬ����Ʒ
void Commoditymassage::Swap(commodity *p1, commodity *p2)//��������combox������������
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

//�������ͳ��
int Commoditymassage::ListCount()//ͳ�Ƶ�ǰ����ļ�¼����������һ������
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




//����Ʒ��Ŵ�С���������
void Commoditymassage::Sort()//�Ե�ǰ�����������
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
	cout <<"������ɣ�"<<endl;
	getch();
	return;
}

//���溯��
void Commoditymassage::Save()
{
	out.open("sort.txt");
	for(commodity *p=Head->Next;p!=End;p=p->Next)
	out<<p->name<<"\t"<<p->Id<<"\t"<<p->buy<<"\t"<<p->sale<<"\t"<<p->sum<<"\n";
	out.close();
}

//��½
void welcome()
{
	char manage[10],password[10];
	cout<<"\t*****************��½*****************"<<endl;
	cout<<"              (�û���Ϊ��123456������Ϊ123)"<<endl;
	cout<<"\t     �û�����";
	cin>>manage;
	cout<<"\t     ���룺";
	char c;
	int l=0;             //�����洢����ĳ���
	while(l<9&&(c=getch())!='\r')           //��������ַ����ǻس���ʱ��getch()�������Բ���ʾ�������Ϣ
		{
			if(c!='\b')        //��������ַ������˸��ʱ
			{
				password[l++]=c;
				putch('*');         //ͨ����ʾ"*"���˽��û������λ��
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
			cout<<"��½�ɹ���"<<endl;
		}
		else
		{	
			cout<<"���벻��ȷ�������ԣ�"<<endl;
			welcome();
		}
	}
	else
	{
		cout<<"�����ڸ��û��������ԣ�"<<endl;
		welcome();
	}
}


void goods1()
{
	int x,i=0;
	bool quit=false;
	cout<<"\t********************************************"<<endl;
	cout<<"\t  ��                                  ��"<<endl;
	cout<<"\t  ��                                  ��"<<endl;
	cout<<"\t  ��                                  ��"<<endl;
	cout<<"\t  ��      ��ӭ���볬����Ʒ����ϵͳ    �� "<<endl;
	cout<<"\t  ��                                  ��"<<endl;
	cout<<"\t  ��                                  ��"<<endl;
	cout<<"\t  ��                                  ��"<<endl;
	cout<<"\t********************************************"<<endl;
	cout<<"\n\n\n";
	welcome();
	
	cout<<"���������ʼ����";
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