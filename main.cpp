#include "lianbiao.h"
#include "start.h"
#include "goods.h"
#include<iostream>

#include "goods1.h"

#include "yuangong.h"
#include "leishixian.h"
#include "anniu.h"


using namespace std;

int main()
{
	cout<<"*****************************"<<endl;
	cout<<"*    1.�˿����             *"<<endl;
	cout<<"*    2.�ֿ����Ա���       *"<<endl;
	cout<<"*    3.Ա�����             *"<<endl;
	cout<<"*    4.�˳�                 *"<<endl;
	cout<<"*    ��ѡ��...              *"<<endl;
	cout<<"*****************************"<<endl;
	int c;
	cin>>c;
	switch(c)
	{
	case 1:
		login();
		main();
		break;
	case 2:
		goods1();
		main();
		break;
	case 3:
		anniu();
		main();
		break;
	case 4:
		exit(0);
	default:
		cout<<"/(��o��)/~~ number is wrong!"<<endl;
	}
	return 0;	
}

