#ifndef CONTACTMETHODS_H
#define CONTACTMETHODS_H
#include <string>
#define MAX 100
void DisplayMenu();

//设计联系人结构体
typedef struct Person
{
    std::string m_Name;//姓名
    int m_Sex;//性别，1为男0为女
    int m_Age;//年龄
    std::string m_Phone;//手机号
    std::string m_Address;//住址
};

//设计通讯录结构体
typedef struct Addressbook
{
    struct Person personArray[MAX];//数组记录联系人
    int m_size;//实际人个数
};
void addPerson(struct Addressbook * ab);
void displayContacts(struct Addressbook * ab);
int checkIfExist(struct Addressbook * ab,std::string QueryName);
void deleteContact(struct Addressbook * ab);
void findContact(struct Addressbook * ab);
void modifyContact(struct Addressbook * ab);
void clearContact(struct Addressbook * ab);

#endif // CONTACTMETHODS_H
