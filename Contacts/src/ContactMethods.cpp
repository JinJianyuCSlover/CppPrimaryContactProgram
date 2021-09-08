#include "ContactMethods.h"
#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

void DisplayMenu()
{
    cout<<"************************"<<endl;
    cout<<"*****1、添加联系人******"<<endl;
    cout<<"*****2、显示联系人******"<<endl;
    cout<<"*****3、删除联系人******"<<endl;
    cout<<"*****4、查找联系人******"<<endl;
    cout<<"*****5、修改联系人******"<<endl;
    cout<<"*****6、清空联系人******"<<endl;
    cout<<"*****0、退出联系录******"<<endl;
    cout<<"************************"<<endl;
}

void addPerson(struct Addressbook * ab)
{
    if(ab ->m_size == MAX){
        cout<<"人已经满了"<<endl;
        return;
    }else{
        //添加联系人
        string name;
        int sex;
        int age;
        string phone;
        string address;
        cout<<"输入姓名：";
        cin>>name;
        cout<<"输入性别，0是女1是男：";
        cin>>sex;
        cout<<"输入年龄：";
        cin>>age;
        cout<<"输入电话：";
        cin>>phone;
        cout<<"输入地址：";
        cin>>address;

        if(sex==1||sex==0){
            ab -> personArray[ab->m_size] = {name,sex,age,phone,address};
            cout<<"添加成功"<<endl;
            system("pause");
            system("cls");

        }else{
            cout<<"错误的输入。"<<endl;
            addPerson(ab);
        }
        //更新通讯录人数
        ab->m_size++;
    }
}

void displayContacts(struct Addressbook * ab){
    int len = ab ->m_size;
    if(len==0){
        cout<<"当前记录为空！快去添加新朋友！"<<endl;
    }
    else{
        for(int i=0;i<len;i++){
            cout<<"*****联系人："<<i+1<<"号***********"<<endl;
            cout<<"姓名："<<ab->personArray[i].m_Name<<endl;
            cout<<"性别："<<(ab ->personArray[i].m_Sex==1?"男":"女")<<endl;
            cout<<"年龄："<<ab->personArray[i].m_Age<<"岁"<<endl;
            cout<<"电话号码："<<ab->personArray[i].m_Phone<<endl;
            cout<<"联系地址："<<ab->personArray[i].m_Address<<endl;
            cout<<"***********************************"<<endl<<endl<<endl;
        }
    }
    system("pause");
    system("cls");

}

int checkIfExist(struct Addressbook * ab,string QueryName){
    int res = -1;
    for(int i=0;i<ab ->m_size;i++){
        if(QueryName.compare(ab->personArray[i].m_Name)==0){
            res = i;
            break;
        }
    }
    return res;

}

void deleteContact(struct Addressbook * ab)
{
    if(ab->m_size==0){
        cout<<"没有用户,删除不了"<<endl;
    }
    else{
        string QueryName;
        cout<<"删除哪位？";
        cin>>QueryName;
        int index = checkIfExist(ab,QueryName);
        if(index!=-1){
                for(int i=index;i<ab->m_size;i++){
                    ab->personArray[i] = ab->personArray[i+1];
                }
                ab ->m_size--;
                cout<<"已经删除"<<QueryName<<endl;

        }else{
            cout<<"查无此人，正在返回上级菜单。"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void findContact(struct Addressbook * ab){
    if (ab->m_size!=0){
        string name;
        cout<<"你要找谁呢？输入名字：";
        cin>>name;
        int index=checkIfExist(ab,name);
        if(index==-1){
            cout<<"查无此人，你可以试着添加"<<endl;
        }else{
            cout<<"*****联系人："<<index+1<<"号***********"<<endl;
            cout<<"姓名："<<ab->personArray[index].m_Name<<endl;
            cout<<"性别："<<(ab ->personArray[index].m_Sex==1?"男":"女")<<endl;
            cout<<"年龄："<<ab->personArray[index].m_Age<<"岁"<<endl;
            cout<<"电话号码："<<ab->personArray[index].m_Phone<<endl;
            cout<<"联系地址："<<ab->personArray[index].m_Address<<endl;
            cout<<"***********************************"<<endl<<endl<<endl;
        }
    }else{
        cout<<"当前记录为空！快去添加新朋友！"<<endl;
    }
    system("pause");
    system("cls");
}

void modifyContact(struct Addressbook * ab){
    if (ab->m_size!=0){
        string name;
        cout<<"你要修改谁呢？输入名字：";
        cin>>name;
        int index=checkIfExist(ab,name);
        if(index==-1){
            cout<<"查无此人，你可以试着添加"<<endl;
        }else{
            string name;
            int sex;
            int age;
            string phone;
            string address;
            cout<<"输入姓名：";
            cin>>name;
            cout<<"输入性别，0是女1是男：";
            cin>>sex;
            cout<<"输入年龄：";
            cin>>age;
            cout<<"输入电话：";
            cin>>phone;
            cout<<"输入地址：";
            cin>>address;

            if(sex==1||sex==0){
                ab -> personArray[index] = {name,sex,age,phone,address};
                cout<<"修改成功"<<endl;
                system("pause");
                system("cls");

            }else{
                cout<<"错误的输入。"<<endl;
                modifyContact(ab);
            }
        }
    }else{
        cout<<"当前记录为空！快去添加新朋友！"<<endl;
    }
    system("pause");
    system("cls");


}

void clearContact(struct Addressbook * ab){
    ab->m_size = 0;
    cout<<"已经清空"<<endl;
    system("pause");
    system("cls");
}
