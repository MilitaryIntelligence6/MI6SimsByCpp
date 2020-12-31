#include "pch.h"
#include "MenuData.h"

void MenuDataOrder::Commader(int order)
{
	//дһ������ͨ��order�õ���Ӧ������
	//�ϰ������������ϰ�����ż����û���ϰٷֱ�ð��
	//todo
	LinkList p = mytail;
	while (p!=myhead->next)
	{
		LinkList q = myhead->next;
		
		while (q->next != NULL)	//���һ��ð�ݽ���������ð���㷨�Ƿ�һ��
		{
			if ((order > 99 && order % 2 == 1)||(order<=99))//�ϰ�������������û���ϰ�
			{
				if (getGrade(q,order)>getGrade(q->next,order))//�������ð
				{
					swap(q, q->next);
					q = q->before;
				}
			}
			//�ϰ�����ż����С������ð
			if (order > 99 && order % 2 == 0)//�ϰ�������������û���ϰ�
			{
				if (getGrade(q, order) < getGrade(q->next, order))//С������ð
				{
					swap(q, q->next);
					q = q->before;
				}
			}
			q = q->next;
		}
		p = p->before;
	}

}


//��������
void MenuDataOrder::quick_sort(LinkList first, LinkList theleft, LinkList theright,int order)
{
	LinkList left = theleft, right = theright;
	if (left->student.num<right->student.num)
	{
		LinkList flag = first;//����һ��������Ϊ����
		while (left!=right)
		{
			while (getGrade(flag, order) <= getGrade(right, order) && left!=right) // ���������ҵ�һ��С��x����
				right = right->before;
			if (left != right)
			{
				swap(flag, right);
				flag = right;
				left = left->next;
			}
			else break;

			while (getGrade(left, order) <= getGrade(flag, order) && left != right) // ���������ҵ�һ�����ڵ���x����
				left = left->next;
			if (left != right)
			{
				swap(left, flag);
				flag = left;
				right = right->before;
			}
			else break;
		}
		//?s[i] = x;
		quick_sort(first, theleft, left->before,order); // �ݹ���� 
		quick_sort(first, left->next, theright,order);
	}
}

int MenuDataOrder::getGrade(LinkList p,int order)
{
	if (order>99)
	{
		order /= 10;
	}

	int x;
	switch (order)
	{
	case 11:
		return p->student.Chinese;
	case 12:
		return p->student.Math;
	case 13:
		return p->student.Ehglish;
	case 14:
		return p->student.P_E_;
	case 21:
		//�������ѧ�����ܷ�
		return p->student.Chinese + p->student.Math + p->student.Ehglish + p->student.P_E_;
	case 22:
		//ƽ����
		return (p->student.Chinese + p->student.Math + p->student.Ehglish + p->student.P_E_) / 4;
	case 23:
		//��׼��
		x = (p->student.Chinese + p->student.Math + p->student.Ehglish + p->student.P_E_) / 4;
		return (p->student.Chinese - x) * (p->student.Chinese - x) + (p->student.Math) * (p->student.Math) + (p->student.Ehglish) * (p->student.Ehglish) + (p->student.P_E_) * (p->student.P_E_);
		break;
	default:return p->student.num;
		break;
	}
	return 0;
}
