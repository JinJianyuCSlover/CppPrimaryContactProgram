#include <iostream>
#include<string>
#include <cstdlib>
#include "ContactMethods.h"
using namespace std;


int main()
{
    //创建通讯录结构体变量
    struct Addressbook abs;
    //初始人数
    abs.m_size = 0;





    //你的选择
    int select = 0;
    while(true){
        DisplayMenu();
        cin>>select;
        switch(select)
        {
            case 1 :
                addPerson(&abs);//传入地址，才能真的加人
                break;
            case 2 :
                displayContacts(&abs);//2、显示联系人
                break;
            case 3 :
                deleteContact(&abs);
                break;//3、删除联系人
            case 4 :
                findContact(&abs);
                break;//4、查找联系人
            case 5 :
                modifyContact(&abs);
                break;//5、修改联系人
            case 6 :
                clearContact(&abs);
                break;//6、清空联系人
            case 0 ://0、退出联系录
                cout<<"已经退出系统。"<<endl;
                system("pause");
                return 0;
                break;

            default :
                break;
        }
    }







    return 0;
}
