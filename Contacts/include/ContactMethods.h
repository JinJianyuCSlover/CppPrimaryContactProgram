#ifndef CONTACTMETHODS_H
#define CONTACTMETHODS_H
#include <string>
#define MAX 100
void DisplayMenu();

//�����ϵ�˽ṹ��
typedef struct Person
{
    std::string m_Name;//����
    int m_Sex;//�Ա�1Ϊ��0ΪŮ
    int m_Age;//����
    std::string m_Phone;//�ֻ���
    std::string m_Address;//סַ
};

//���ͨѶ¼�ṹ��
typedef struct Addressbook
{
    struct Person personArray[MAX];//�����¼��ϵ��
    int m_size;//ʵ���˸���
};
void addPerson(struct Addressbook * ab);
void displayContacts(struct Addressbook * ab);
int checkIfExist(struct Addressbook * ab,std::string QueryName);
void deleteContact(struct Addressbook * ab);
void findContact(struct Addressbook * ab);
void modifyContact(struct Addressbook * ab);
void clearContact(struct Addressbook * ab);

#endif // CONTACTMETHODS_H
