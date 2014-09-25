# ifndef goods_h
# define goods_h

#include "start.h"
#include<conio.h>
#include"goods1.h"
//界面函数
void choose()
{
	 cout<<"*****************************"<<endl;
	 cout<<"*                           *"<<endl;
	 cout<<"*   查看个人信息 请按1      *"<<endl;
	 cout<<"*   查看商品信息 请按2      *"<<endl;
	 cout<<"*   返回主界面   请按3      *"<<endl;
	 cout<<"*                           *"<<endl; 
     cout<<"*****************************"<<endl;
}
void exit()
{
	 cout<<"*****************************"<<endl;
	 cout<<"*                           *"<<endl;
	 cout<<"*     谢谢光临**超市        *"<<endl;
	 cout<<"*                           *"<<endl; 
     cout<<"*****************************"<<endl;
}

void goods();     //类似于前向引用声明

void show_gk()          //查看个人信息
{
	readfile(ID);	
	cout<<"按任意键继续"<<endl;
	getch();
	system("cls");
	cout<<"*****************************"<<endl;
	cout<<"*                           *"<<endl;
	cout<<"*   查看商品信息 请按1      *"<<endl;
	cout<<"*       退出     请按2      *"<<endl;
	cout<<"*                           *"<<endl; 
    cout<<"*****************************"<<endl;

	int a;
	cin>>a;
	switch(a)
	{
	case 1:
		goods();
		break;
	case 2:
		exit(0);
		break;
	default:
        cout<<"/(ㄒoㄒ)/~~ number is wrong!"<<endl;
	}
}
void buygoods(int &sx)
{
	//sx是形参西瓜的数量
	int a,b;   //a表示上界面的选择
	cout<<"请输入您要买的西瓜数(不得多于"<<sx<<"颗)："<<endl;
	cin>>b;
	sx-=b;
	cout<<"您总购买了西瓜"<<b<<"颗"<<endl;
	cout<<"共需支付"<<b*0.5<<"元,确认支付请按1"<<endl;//还有积分和账户余额的变化？
	cin>>a;
	if(a=1)	cout<<"购买成功!"<<endl;//做购买清单
}
void tjgoods(){   //显示特价商品，s表示西瓜的数量
    int s=20,a;      //a表示上界面的选择
    cout<<"*************************************"<<endl;
	cout<<"*                                   *"<<endl;
	cout<<"*    快来抢购!!!                    *"<<endl;
	cout<<"*      西瓜特价0.5元/斤,只剩"<<s<<"颗    *"<<endl;
	cout<<"*        购买   请按1               *"<<endl;
	cout<<"*      返回上一级   请按2           *"<<endl;
	cout<<"*                                   *"<<endl;        
    cout<<"*************************************"<<endl;
	cin>>a;
	switch(a){
	case 1:buygoods(s);break;
	case 2:goods();break;
	default:
		 cout<<"/(ㄒoㄒ)/~~ number is wrong!"<<endl;
	}
}
void goods(){
	void display();
	cout<<"*************************************"<<endl;
	cout<<"*                                   *"<<endl;
	cout<<"*    !!!  特价商品 请按1   !!!      *"<<endl;
	cout<<"*        全部商品  请按2            *"<<endl;
	cout<<"*        具体查找  请按3            *"<<endl;
	cout<<"*        返回主界面    请按4        *"<<endl;
	cout<<"*                                   *"<<endl;        
    cout<<"*************************************"<<endl;
	int a;         
	cin>>a;
	switch(a){
	case 1:tjgoods();break;
	case 2:Grade.Display();break;
	case 3:Grade.Find();break;
	case 4:break;
    default:
		 cout<<"/(ㄒoㄒ)/~~ number is wrong!"<<endl;
	}
}

void menu()
{
	choose();
	int a;
	cin>>a;
	switch (a)
	{
	case 1:
		show_gk();break;  //显示个人信息
	case 2:
		goods();break;     //显示商品信息
	case 3:
		break;
	default:
		cout<<"/(ㄒoㄒ)/~~ number is wrong!"<<endl;
	}
}



# endif