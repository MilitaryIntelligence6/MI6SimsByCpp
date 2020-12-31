#pragma once
#include"LinkList.h"


class MenuDataOrder
{
public:
	MenuDataOrder(LinkList head, LinkList tail,int order)//���캯���Ȱ����ݸ��ƹ���,�ٵ�������������������
	{
		this->order = order;//��������
		//����
		{	
			//ͷ�ڵ�
			myhead = (LinkList)malloc(sizeof(struct Node));
			if (myhead != NULL)//�ռ�����ɹ�
			{
				myhead->before = myhead;
				myhead->next = NULL;
				mytail = myhead;			//
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
				//������һ���ڵ㡿
				PNode node = new(Node);

				//��ָ�����޸ġ�
				node->next = NULL;
				node->before = mytail;	//��巨
				mytail->next = node;
				mytail = node;

				//����ֵ������
				node->student.num = head->student.num;
				node->student.Chinese = head->student.Chinese;
				node->student.Birthday = head->student.Birthday;
				node->student.Math = head->student.Math;
				node->student.Ehglish = head->student.Ehglish;
				node->student.ID = head->student.ID;
				node->student.P_E_ = head->student.P_E_;
				node->student.Class = head->student.Class;
				node->student.Sex = head->student.Sex;
				node->student.Name = head->student.Name;

				head = head->next;
			}
			myOrder = myhead; 
		}
		//����
		//quick_sort(myhead, myhead->next, tail, order);
		Commader(order);
	}
	~MenuDataOrder()//���������ͷſռ�
	{
	}

public:
	LinkList myOrder;
	LinkList myhead, mytail;
	int order = 0;
	
private:
	void Commader(int order);//����Ҫ��������Ϊ�˼�ǿ�����������Ҫ��
	void quick_sort(LinkList myhead, LinkList left, LinkList right, int order);
	int getGrade(LinkList p, int order);
	void  swap(LinkList a, LinkList b)
	{
		LinkList flag = new(Node);
		flag->before = NULL; flag->next = NULL;
		__list_add(flag, b->before, b);
		list_del(b);
		__list_add(b, a->before, a);
		list_del(a);
		__list_add(a, flag->before, flag);
		list_del(flag);
	}
	void __list_add(LinkList thenew,LinkList prev,LinkList next)
	{
		next->before = thenew;
		thenew->next = next;
		thenew->before = prev;
		prev->next = thenew;
	}
	void __list_del(LinkList prev, LinkList next)
	{
		if (next==NULL)
		{
			prev->next = NULL;
		}
		else
		{
		next->before = prev;
		prev->next = next;
		}
	}
	void list_del(LinkList entry)
	{
		__list_del(entry->before, entry->next);
	}
};

