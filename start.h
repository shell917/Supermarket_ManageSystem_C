# ifndef start_h
# define start_h


char ID[15];
#include "goods.h"
#include<conio.h>




void login();
void logon()
{
	int n;
	struct GK *p1;
	n=0;
	p1=(struct GK *)malloc(L);

	cout<<"�����������������λID���룺";
	cin>>p1->ID;
	cout<<"������������";
	cin>>p1->name;
	cout<<"���������룺";
	cin>>p1->password;
	cout<<"�������Ա�";
	cin>>p1->sex;
	cout<<"�������һ����ϵ��ʽ��";
	cin>>p1->tel[0];
	cout<<"������ڶ�����ϵ��ʽ��";
	cin>>p1->tel[1];
	cout<<"������������䣺";
	cin>>p1->email;
	writefile(p1);
	cout<<"ע��ɹ�"<<endl;
	cout<<"�����������"<<endl;
	getch();
	system("cls");
	login();
}



void login()
{
	char password[11]; 
	char c;
	int l=0;             //�����洢����ĳ���
	cout<<"*****************************"<<endl;
	cout<<"*     ����Zע��ID           *"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"*     ����D��½             *"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"*     ����T������һ��       *"<<endl;
	cout<<"*****************************"<<endl;
	
	char a;
	cin>>a;
	if(a=='T')
		goto end;
	if(a=='Z')
		logon();
	if(a=='D')
	{
		cout<<"*�û���¼                   *"<<endl;
		cout<<"*ID��                       *"<<endl;
		cout<<"           ";
		cin>>ID;
		cout<<"*password��                 *"<<endl;
		cout<<"           ";
		while(l<10&&(c=getch())!='\r')           //��������ַ����ǻس���ʱ��getch()�������Բ���ʾ�������Ϣ
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


		strcat(ID,".txt");
		ifstream is(ID,ios_base::in|ios_base::binary);	
		if(is)
		{
			GK *G=(GK *)malloc(L);
			is.read(reinterpret_cast<char *>(G),L);
			if(strcmp(password,G->password)==0)
			{
				cout<<endl;
				cout<<"         success"<<endl;
				cout<<endl<<"*                           *"<<endl;
				cout<<"*****************************"<<endl;
				cout<<"�����������..."<<endl;
				getch();
				system("cls");
				menu();
			}
			else
			{
				cout<<endl;
				cout<<"        ���벻��ȷ"<<endl;
				cout<<endl<<"*                           *"<<endl;
				cout<<"*****************************"<<endl;
			}
		}
		else
		{
			cout<<endl;
			cout<<"�����ڸ��û�!!"<<endl;
			cout<<endl<<"*                           *"<<endl;
			cout<<"*****************************"<<endl;
			cout<<"��������..."<<endl;
			login();
		}	
	}
end:
	cout<<"�����������..."<<endl;
	getch();
	system("cls");
}






#endif