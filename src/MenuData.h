#pragma once

#include"LinkList.h"


class MenuData
{

public:

    LinkList myOrder;

    LinkList myhead, mytail;

    int order = 0;


public:

    MenuData(LinkList head, LinkList tail, int order); //���캯���Ȱ����ݸ��ƹ���,�ٵ�������������������
    

    ~MenuData(); //���������ͷſռ�


private:

    void Commader(int order); //����Ҫ��������Ϊ�˼�ǿ�����������Ҫ�ԣ�
    
    void quickSort(LinkList myhead, LinkList left, LinkList right, int order);

    int getGrade(LinkList p, int order);

    void swap(LinkList foo, LinkList bar);

    void listAdd(LinkList newData, LinkList prev, LinkList next);

    void listDelete(LinkList prev, LinkList next);

    void listDel(LinkList entry);
};

