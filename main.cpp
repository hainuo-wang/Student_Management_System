#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
typedef struct Node
{
    char name[8];
    char tele[12];
    char ID[11];
    struct Node* next;
}Node, * CLLinkList;
#define len sizeof(Node)
void InitCLLinkList(CLLinkList* head)//初始化循环链表
{
    *head = (CLLinkList)malloc(len);
    if (*head)//解决内存泄漏警告问题
    {
        (*head)->next = *head;
    }
}
int SearchCLLinkList1(CLLinkList head, char tele[])//查找手机号
{
    int j = 0; //置初值
    Node* p;
    p = head->next;//置初值
    while (p != head)
    {
        j++;
        if (strcmp(p->tele, tele) == 0)
            return(j);
        p = p->next;
    }
    return(0);
}
int SearchCLLinkList2(CLLinkList head, char name[])//查找姓名
{
    int j = 0; //置初值
    Node* p;
    p = head->next;//置初值
    while (p != head)
    {
        j++;
        if (strcmp(p->name, name) == 0)
            return(j);
        p = p->next;
    }
    return(0);
}
void CreatCLLinkList(CLLinkList head)//循环链表的创建
{
    Node* rear, * s;
    char n1[8];
    char t1[12];
    char u1[11];
    int flag = 1;
    int a, b, n;
    rear = head;//rear指针动态指向当前表尾，其初始值指向头结点
    cout << "请输入需要录入的学生的数量:";
    cin >> n;
    while (flag)
    {
        for (b = 0; b < n; b++)
        {
            cout << "请输入需要添加的学生的姓名:" << "\n";
            cin >> n1;
            s = (Node*)malloc(len);
            A:
            while (1)
            {
                cout << "请输入需要添加的学生的10位学号:" << "\n";
                cin >> u1;
                if (strlen(u1) == 10)
                {
                    for (a = 0; a < 11; a++)
                    {
                        if ((u1[a] >= '0') && (u1[a] <= '9'))
                        {
                            if (s)//解决内存泄漏警告问题
                            {
                                strcpy_s(s->ID, u1);
                                goto B;
                            }

                        }
                        else
                        {
                            cout << "输入错误，";
                            strcpy_s(u1, "");//清空数组，解决内存溢出问题
                            goto A;
                        }
                    }
                }
                else
                {
                    cout << "输入错误，";
                    strcpy_s(u1, "");//清空数组，解决内存溢出问题
                    goto A;
                }
            }
            B:
            while (1)
            {
                cout << "请输入需要添加的学生的11位电话号码:" << "\n";
                cin >> t1;
                if (strlen(t1) == 11)
                {
                    for (a = 0; a < 11; a++)
                    {
                        if ((t1[a] >= '0') && (t1[a] <= '9'))
                        {
                            strcpy_s(s->tele, t1);
                            goto C;
                        }
                        else
                        {
                            cout << "输入错误，";
                            strcpy_s(t1, "");//清空数组，解决内存溢出问题
                            goto B;
                        }
                    }
                }
                else
                {
                    cout << "输入错误，";
                    strcpy_s(t1, "");//清空数组，解决内存溢出问题
                    goto B;
                }
            }
            C:
            strcpy_s(s->name, n1);
            strcpy_s(s->ID, u1);
            rear->next = s;
            rear = s;
        }
        flag = 0;
        rear->next = head;//最后一个节点的next域指向头结点
    }
}
void InCLLinkList(CLLinkList head, int i)//添加
{
    Node* p, * s;
    int a, k = 0;
    int flag = 1;
    char n1[8], u1[11], t1[12];
    p = head;
    if (i <= 0)
    {
        cout << "插入的位置不合法:" << "\n";
        return;
    }
    while (p->next != head && k < i - 1)
    {
        k++;
        p = p->next;
    }
    s = (Node*)malloc(len);
    cout << "请输入需要添加的学生的姓名" << "\n";
    cin >> n1;
    A:
    while (1)
    {
        cout << "请输入需要添加的学生的10位学号:" << "\n";
        cin >> u1;
        if (strlen(u1) == 10)
        {
            for (a = 0; a < 11; a++)
            {
                if ((u1[a] >= '0') && (u1[a] <= '9'))
                {
                    if (s)//解决内存泄漏警告问题
                    {
                        strcpy_s(s->ID, u1);
                        goto B;
                    }

                }
                else
                {
                    cout << "输入错误，";
                    strcpy_s(u1, "");//清空数组，解决内存溢出问题
                    goto A;
                }
            }
        }
        else
        {
            cout << "输入错误，";
            strcpy_s(u1, "");//清空数组，解决内存溢出问题
            goto A;
        }
    }
    B:
    while (1)
    {
        cout << "请输入需要添加的学生的11位电话号码:" << "\n";
        cin >> t1;
        if (strlen(t1) == 11)
        {
            for (a = 0; a < 11; a++)
            {
                if ((t1[a] >= '0') && (t1[a] <= '9'))
                {
                    strcpy_s(s->tele, t1);
                    goto C;
                }
                else
                {
                    cout << "输入错误，";
                    strcpy_s(t1, "");//清空数组，解决内存溢出问题
                    goto B;
                }
            }
        }
        else
        {
            cout << "输入错误，";
            strcpy_s(t1, "");//清空数组，解决内存溢出问题
            goto B;
        }
    }
    C:
    strcpy_s(s->name, n1);
    strcpy_s(s->ID, u1);
    s->next = p->next;
    p->next = s;
    cout << "插入成功，";
}
void Print_CLLinkList(CLLinkList head)//输出
{
    Node* p;
    p = head->next;
    cout << "姓名         学号             电话\n";
    for (; p != head; p = p->next)
    {
        if (strlen(p->name) == 6)
        {
            printf("%s       %s       %s \n", p->name, p->ID, p->tele);
        }
        else if (strlen(p->name) == 4)
        {
            printf("%s         %s       %s \n", p->name, p->ID, p->tele);
        }
        else
        {
            printf("%s         %s       %s \n", p->name, p->ID, p->tele);
        }
    }

}
void DeleCLLinkList(CLLinkList head, char u1[])//删除
{
    Node* p, * r;
    p = head;
    while (p->next != head && strcmp((p->next)->ID, u1) != 0)
    {
        p = p->next;
    }
    if (p->next == head)
    {
        cout << "需要删除的学号不存在!";
        return;
    }
    r = p->next;
    p->next = r->next;
    free(r);
}
int LengthCLLinkList(CLLinkList head)//求循环链表的长度
{
    int i = 0;
    Node* p;
    p = head->next;
    while (p != head)
    {
        i++;
        p = p->next;
    }
    return i;
}
int main()
{
    int i, y;
    char n1[8];
    char t1[12];
    char u1[11];
    int select = 1;
    CLLinkList head;
    InitCLLinkList(&head);
    while (select != 0)
    {
        cout << "**学生名册管理系统**\n"
                "  #请输入操作选择#\n"
                "   1-初始录入信息\n"
                "   2-查找学生信息\n"
                "   3-任意位置插入\n"
                "   4-删除学生信息\n"
                "   5-显示全部信息\n"
                "   0-结束本次服务\n";
        cin >> select;
        switch (select)
        {
            case 1:
                CreatCLLinkList(head);
                cout << "\n学生名册的初始数据为:\n";
                Print_CLLinkList(head);
                break;
            case 2:
                cout << "\n请输入需要查找的手机号:\n";
                cin >> t1;
                y = SearchCLLinkList1(head, t1);
                if (y == 0)
                {
                    printf("\n\n%s这个电话号不在学生名册中\n\n", t1);
                }
                else
                {
                    printf("\n手机号为%s的这个人在学生名册中的位置为%d\n", t1, y);
                }
                break;
            case 3:
                cout << "\n请输入需要插入哪位同学（姓名）的前面:\n";
                cin >> n1;
                i = SearchCLLinkList2(head, n1);
                if (i == 0)
                {
                    cout << "\n这位同学不在学生名册中！\n\n";
                }
                else
                {
                    InCLLinkList(head, i);
                }
                cout << "插入后的学生名册为:\n";
                Print_CLLinkList(head);
                break;
            case 4:
                cout << "\n请输入需要删除学生的学号:\n";
                cin >> u1;
                DeleCLLinkList(head, u1);
                cout << "\n删除后的学生名册为:\n";
                Print_CLLinkList(head);
                printf("\n学生名册的长度为%d:\n", LengthCLLinkList(head));
                break;
            case 5:
                cout << "\n***学生名册***\n";
                Print_CLLinkList(head);
                break;
            case 0:
                break;
            default:
                cout << "\n输入错误！\n\n";
        }
    }
    cout << "\n";
    return 0;
}
