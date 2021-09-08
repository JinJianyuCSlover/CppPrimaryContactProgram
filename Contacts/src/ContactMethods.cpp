#include "ContactMethods.h"
#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

void DisplayMenu()
{
    cout<<"************************"<<endl;
    cout<<"*****1�������ϵ��******"<<endl;
    cout<<"*****2����ʾ��ϵ��******"<<endl;
    cout<<"*****3��ɾ����ϵ��******"<<endl;
    cout<<"*****4��������ϵ��******"<<endl;
    cout<<"*****5���޸���ϵ��******"<<endl;
    cout<<"*****6�������ϵ��******"<<endl;
    cout<<"*****0���˳���ϵ¼******"<<endl;
    cout<<"************************"<<endl;
}

void addPerson(struct Addressbook * ab)
{
    if(ab ->m_size == MAX){
        cout<<"���Ѿ�����"<<endl;
        return;
    }else{
        //�����ϵ��
        string name;
        int sex;
        int age;
        string phone;
        string address;
        cout<<"����������";
        cin>>name;
        cout<<"�����Ա�0��Ů1���У�";
        cin>>sex;
        cout<<"�������䣺";
        cin>>age;
        cout<<"����绰��";
        cin>>phone;
        cout<<"�����ַ��";
        cin>>address;

        if(sex==1||sex==0){
            ab -> personArray[ab->m_size] = {name,sex,age,phone,address};
            cout<<"��ӳɹ�"<<endl;
            system("pause");
            system("cls");

        }else{
            cout<<"��������롣"<<endl;
            addPerson(ab);
        }
        //����ͨѶ¼����
        ab->m_size++;
    }
}

void displayContacts(struct Addressbook * ab){
    int len = ab ->m_size;
    if(len==0){
        cout<<"��ǰ��¼Ϊ�գ���ȥ��������ѣ�"<<endl;
    }
    else{
        for(int i=0;i<len;i++){
            cout<<"*****��ϵ�ˣ�"<<i+1<<"��***********"<<endl;
            cout<<"������"<<ab->personArray[i].m_Name<<endl;
            cout<<"�Ա�"<<(ab ->personArray[i].m_Sex==1?"��":"Ů")<<endl;
            cout<<"���䣺"<<ab->personArray[i].m_Age<<"��"<<endl;
            cout<<"�绰���룺"<<ab->personArray[i].m_Phone<<endl;
            cout<<"��ϵ��ַ��"<<ab->personArray[i].m_Address<<endl;
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
        cout<<"û���û�,ɾ������"<<endl;
    }
    else{
        string QueryName;
        cout<<"ɾ����λ��";
        cin>>QueryName;
        int index = checkIfExist(ab,QueryName);
        if(index!=-1){
                for(int i=index;i<ab->m_size;i++){
                    ab->personArray[i] = ab->personArray[i+1];
                }
                ab ->m_size--;
                cout<<"�Ѿ�ɾ��"<<QueryName<<endl;

        }else{
            cout<<"���޴��ˣ����ڷ����ϼ��˵���"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void findContact(struct Addressbook * ab){
    if (ab->m_size!=0){
        string name;
        cout<<"��Ҫ��˭�أ��������֣�";
        cin>>name;
        int index=checkIfExist(ab,name);
        if(index==-1){
            cout<<"���޴��ˣ�������������"<<endl;
        }else{
            cout<<"*****��ϵ�ˣ�"<<index+1<<"��***********"<<endl;
            cout<<"������"<<ab->personArray[index].m_Name<<endl;
            cout<<"�Ա�"<<(ab ->personArray[index].m_Sex==1?"��":"Ů")<<endl;
            cout<<"���䣺"<<ab->personArray[index].m_Age<<"��"<<endl;
            cout<<"�绰���룺"<<ab->personArray[index].m_Phone<<endl;
            cout<<"��ϵ��ַ��"<<ab->personArray[index].m_Address<<endl;
            cout<<"***********************************"<<endl<<endl<<endl;
        }
    }else{
        cout<<"��ǰ��¼Ϊ�գ���ȥ��������ѣ�"<<endl;
    }
    system("pause");
    system("cls");
}

void modifyContact(struct Addressbook * ab){
    if (ab->m_size!=0){
        string name;
        cout<<"��Ҫ�޸�˭�أ��������֣�";
        cin>>name;
        int index=checkIfExist(ab,name);
        if(index==-1){
            cout<<"���޴��ˣ�������������"<<endl;
        }else{
            string name;
            int sex;
            int age;
            string phone;
            string address;
            cout<<"����������";
            cin>>name;
            cout<<"�����Ա�0��Ů1���У�";
            cin>>sex;
            cout<<"�������䣺";
            cin>>age;
            cout<<"����绰��";
            cin>>phone;
            cout<<"�����ַ��";
            cin>>address;

            if(sex==1||sex==0){
                ab -> personArray[index] = {name,sex,age,phone,address};
                cout<<"�޸ĳɹ�"<<endl;
                system("pause");
                system("cls");

            }else{
                cout<<"��������롣"<<endl;
                modifyContact(ab);
            }
        }
    }else{
        cout<<"��ǰ��¼Ϊ�գ���ȥ��������ѣ�"<<endl;
    }
    system("pause");
    system("cls");


}

void clearContact(struct Addressbook * ab){
    ab->m_size = 0;
    cout<<"�Ѿ����"<<endl;
    system("pause");
    system("cls");
}
