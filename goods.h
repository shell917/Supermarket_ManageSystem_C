# ifndef goods_h
# define goods_h

#include "start.h"
#include<conio.h>
#include"goods1.h"
//���溯��
void choose()
{
	 cout<<"*****************************"<<endl;
	 cout<<"*                           *"<<endl;
	 cout<<"*   �鿴������Ϣ �밴1      *"<<endl;
	 cout<<"*   �鿴��Ʒ��Ϣ �밴2      *"<<endl;
	 cout<<"*   ����������   �밴3      *"<<endl;
	 cout<<"*                           *"<<endl; 
     cout<<"*****************************"<<endl;
}
void exit()
{
	 cout<<"*****************************"<<endl;
	 cout<<"*                           *"<<endl;
	 cout<<"*     лл����**����        *"<<endl;
	 cout<<"*                           *"<<endl; 
     cout<<"*****************************"<<endl;
}

void goods();     //������ǰ����������

void show_gk()          //�鿴������Ϣ
{
	readfile(ID);	
	cout<<"�����������"<<endl;
	getch();
	system("cls");
	cout<<"*****************************"<<endl;
	cout<<"*                           *"<<endl;
	cout<<"*   �鿴��Ʒ��Ϣ �밴1      *"<<endl;
	cout<<"*       �˳�     �밴2      *"<<endl;
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
        cout<<"/(��o��)/~~ number is wrong!"<<endl;
	}
}
void buygoods(int &sx)
{
	//sx���β����ϵ�����
	int a,b;   //a��ʾ�Ͻ����ѡ��
	cout<<"��������Ҫ���������(���ö���"<<sx<<"��)��"<<endl;
	cin>>b;
	sx-=b;
	cout<<"���ܹ���������"<<b<<"��"<<endl;
	cout<<"����֧��"<<b*0.5<<"Ԫ,ȷ��֧���밴1"<<endl;//���л��ֺ��˻����ı仯��
	cin>>a;
	if(a=1)	cout<<"����ɹ�!"<<endl;//�������嵥
}
void tjgoods(){   //��ʾ�ؼ���Ʒ��s��ʾ���ϵ�����
    int s=20,a;      //a��ʾ�Ͻ����ѡ��
    cout<<"*************************************"<<endl;
	cout<<"*                                   *"<<endl;
	cout<<"*    ��������!!!                    *"<<endl;
	cout<<"*      �����ؼ�0.5Ԫ/��,ֻʣ"<<s<<"��    *"<<endl;
	cout<<"*        ����   �밴1               *"<<endl;
	cout<<"*      ������һ��   �밴2           *"<<endl;
	cout<<"*                                   *"<<endl;        
    cout<<"*************************************"<<endl;
	cin>>a;
	switch(a){
	case 1:buygoods(s);break;
	case 2:goods();break;
	default:
		 cout<<"/(��o��)/~~ number is wrong!"<<endl;
	}
}
void goods(){
	void display();
	cout<<"*************************************"<<endl;
	cout<<"*                                   *"<<endl;
	cout<<"*    !!!  �ؼ���Ʒ �밴1   !!!      *"<<endl;
	cout<<"*        ȫ����Ʒ  �밴2            *"<<endl;
	cout<<"*        �������  �밴3            *"<<endl;
	cout<<"*        ����������    �밴4        *"<<endl;
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
		 cout<<"/(��o��)/~~ number is wrong!"<<endl;
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
		show_gk();break;  //��ʾ������Ϣ
	case 2:
		goods();break;     //��ʾ��Ʒ��Ϣ
	case 3:
		break;
	default:
		cout<<"/(��o��)/~~ number is wrong!"<<endl;
	}
}



# endif