#include "pch.h"
#include "MenuData.h"



MenuData::MenuData(LinkList head, LinkList tail, int order)
{
    this->order = order;//��������
    //����
    {
        //ͷ�ڵ�
        myhead = (LinkList)malloc(sizeof(struct Node));
        if (myhead != NULL)//�ռ�����ɹ�
        {
            myhead->prev = myhead;
            myhead->next = NULL;
            mytail = myhead;            //
            myhead->student.num = 0;
        }
        else//�ռ�����ʧ��
        {
            //printf("����ͷ�ڵ�ʱ����ռ�ʧ�ܣ�\n");
            //todo:������
        }
        //��������
        head = head->next;
        while (head != NULL)//��head��λԭ���Ľڵ�
        {
            //����һ���ڵ�
            PNode node = new(Node);

            //ָ�����޸�
            node->next = NULL;
            node->prev = mytail;    //��巨
            mytail->next = node;
            mytail = node;

            //��ֵ������
            node->student.num = head->student.num;
            node->student.dataStructure = head->student.dataStructure;
            node->student.birthday = head->student.birthday;
            node->student.computerNetwork = head->student.computerNetwork;
            node->student.compilationPrinciple = head->student.compilationPrinciple;
            node->student.id = head->student.id;
            node->student.androidDevelopment = head->student.androidDevelopment;
            node->student.clazz = head->student.clazz;
            node->student.sex = head->student.sex;
            node->student.name = head->student.name;

            head = head->next;
        }
        myOrder = myhead;
    }
    //����
    //quick_sort(myhead, myhead->next, tail, order);
    Commader(order);
}


MenuData::~MenuData()//���������ͷſռ�
{
}


void MenuData::Commader(int order)
{
    //дһ������ͨ��order�õ���Ӧ������
    //�ϰ������������ϰ�����ż����û���ϰٷֱ�ð��
    //todo
    LinkList p = mytail;
    while (p != myhead->next)
    {
        LinkList q = myhead->next;

        while (q->next != NULL)    //���һ��ð�ݽ���������ð���㷨�Ƿ�һ��
        {
            if ((order > 99 && order % 2 == 1) || (order <= 99))//�ϰ�������������û���ϰ�
            {
                if (getGrade(q, order) > getGrade(q->next, order))//�������ð
                {
                    swap(q, q->next);
                    q = q->prev;
                }
            }
            //�ϰ�����ż����С������ð
            if (order > 99 && order % 2 == 0)//�ϰ�������������û���ϰ�
            {
                if (getGrade(q, order) < getGrade(q->next, order))//С������ð
                {
                    swap(q, q->next);
                    q = q->prev;
                }
            }
            q = q->next;
        }
        p = p->prev;
    }

}


//��������
void MenuData::quickSort(LinkList first, LinkList theleft, LinkList theright, int order)
{
    LinkList left = theleft, right = theright;
    if (left->student.num < right->student.num)
    {
        LinkList flag = first;//����һ��������Ϊ����
        while (left != right)
        {
            while (getGrade(flag, order) <= getGrade(right, order) && left != right) // ���������ҵ�һ��С��x����
                right = right->prev;
            if (left != right)
            {
                swap(flag, right);
                flag = right;
                left = left->next;
            } else break;

            while (getGrade(left, order) <= getGrade(flag, order) && left != right) // ���������ҵ�һ�����ڵ���x����
                left = left->next;
            if (left != right)
            {
                swap(left, flag);
                flag = left;
                right = right->prev;
            } else break;
        }
        //?s[i] = x;
        quickSort(first, theleft, left->prev, order); // �ݹ����
        quickSort(first, left->next, theright, order);
    }
}


int MenuData::getGrade(LinkList p, int order)
{
    if (order > 99)
    {
        order /= 10;
    }

    int x;
    switch (order)
    {
        case 11:
            return p->student.dataStructure;
        case 12:
            return p->student.computerNetwork;
        case 13:
            return p->student.compilationPrinciple;
        case 14:
            return p->student.androidDevelopment;
        case 21:
            //�������ѧ�����ܷ�
            return p->student.dataStructure + p->student.computerNetwork + p->student.compilationPrinciple +
                   p->student.androidDevelopment;
        case 22:
            //ƽ����
            return (p->student.dataStructure + p->student.computerNetwork + p->student.compilationPrinciple +
                    p->student.androidDevelopment) / 4;
        case 23:
            //��׼��
            x = (p->student.dataStructure + p->student.computerNetwork + p->student.compilationPrinciple +
                 p->student.androidDevelopment) / 4;
            return (p->student.dataStructure - x) * (p->student.dataStructure - x) +
                   (p->student.computerNetwork) * (p->student.computerNetwork) +
                   (p->student.compilationPrinciple) * (p->student.compilationPrinciple) +
                   (p->student.androidDevelopment) * (p->student.androidDevelopment);
            break;
        default:
            return p->student.num;
            break;
    }
    return 0;
}


void MenuData::swap(LinkList foo, LinkList bar)
{
    LinkList flag = new(Node);
    flag->prev = NULL;
    flag->next = NULL;
    listAdd(flag, bar->prev, bar);
    listDel(bar);
    listAdd(bar, foo->prev, foo);
    listDel(foo);
    listAdd(foo, flag->prev, flag);
    listDel(flag);
}


void MenuData::listAdd(LinkList newData, LinkList prev, LinkList next)
{
    next->prev = newData;
    newData->next = next;
    newData->prev = prev;
    prev->next = newData;
}


void MenuData::listDelete(LinkList prev, LinkList next)
{
    if (next == NULL)
    {
        prev->next = NULL;
    }
    else
    {
        next->prev = prev;
        prev->next = next;
    }
}


void MenuData::listDel(LinkList entry)
{
    listDelete(entry->prev, entry->next);
}
