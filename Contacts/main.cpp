#include <iostream>
#include<string>
#include <cstdlib>
#include "ContactMethods.h"
using namespace std;


int main()
{
    //����ͨѶ¼�ṹ�����
    struct Addressbook abs;
    //��ʼ����
    abs.m_size = 0;





    //���ѡ��
    int select = 0;
    while(true){
        DisplayMenu();
        cin>>select;
        switch(select)
        {
            case 1 :
                addPerson(&abs);//�����ַ��������ļ���
                break;
            case 2 :
                displayContacts(&abs);//2����ʾ��ϵ��
                break;
            case 3 :
                deleteContact(&abs);
                break;//3��ɾ����ϵ��
            case 4 :
                findContact(&abs);
                break;//4��������ϵ��
            case 5 :
                modifyContact(&abs);
                break;//5���޸���ϵ��
            case 6 :
                clearContact(&abs);
                break;//6�������ϵ��
            case 0 ://0���˳���ϵ¼
                cout<<"�Ѿ��˳�ϵͳ��"<<endl;
                system("pause");
                return 0;
                break;

            default :
                break;
        }
    }







    return 0;
}
