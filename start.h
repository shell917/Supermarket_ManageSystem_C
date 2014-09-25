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

	cout<<"请输入您想申请的六位ID号码：";
	cin>>p1->ID;
	cout<<"请输入姓名：";
	cin>>p1->name;
	cout<<"请输入密码：";
	cin>>p1->password;
	cout<<"请输入性别：";
	cin>>p1->sex;
	cout<<"请输入第一个联系方式：";
	cin>>p1->tel[0];
	cout<<"请输入第二个联系方式：";
	cin>>p1->tel[1];
	cout<<"请输入电子邮箱：";
	cin>>p1->email;
	writefile(p1);
	cout<<"注册成功"<<endl;
	cout<<"按任意键继续"<<endl;
	getch();
	system("cls");
	login();
}



void login()
{
	char password[11]; 
	char c;
	int l=0;             //用来存储密码的长度
	cout<<"*****************************"<<endl;
	cout<<"*     输入Z注册ID           *"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"*     输入D登陆             *"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"*     输入T返回上一级       *"<<endl;
	cout<<"*****************************"<<endl;
	
	char a;
	cin>>a;
	if(a=='T')
		goto end;
	if(a=='Z')
		logon();
	if(a=='D')
	{
		cout<<"*用户登录                   *"<<endl;
		cout<<"*ID：                       *"<<endl;
		cout<<"           ";
		cin>>ID;
		cout<<"*password：                 *"<<endl;
		cout<<"           ";
		while(l<10&&(c=getch())!='\r')           //当输入的字符不是回车键时，getch()函数可以不显示输入的信息
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
				cout<<"按任意键继续..."<<endl;
				getch();
				system("cls");
				menu();
			}
			else
			{
				cout<<endl;
				cout<<"        密码不正确"<<endl;
				cout<<endl<<"*                           *"<<endl;
				cout<<"*****************************"<<endl;
			}
		}
		else
		{
			cout<<endl;
			cout<<"不存在该用户!!"<<endl;
			cout<<endl<<"*                           *"<<endl;
			cout<<"*****************************"<<endl;
			cout<<"重新输入..."<<endl;
			login();
		}	
	}
end:
	cout<<"按任意键继续..."<<endl;
	getch();
	system("cls");
}






#endif