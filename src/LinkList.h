//LinkList.h

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <afxstr.h>


//���������Ͷ���
typedef struct StuMessage
{
	int num = 0;	//���
	CString Name = _T("foobar");		//����
	bool Sex = 1;			//�Ա�
	unsigned long long int ID = 41800000;	//ѧ��
	CString Class = NULL;		//�༶
	CString Birthday = NULL;	//����
	int Chinese = 0;
	int Math = 0;
	int Ehglish = 0;
	int P_E_ = 0;
}Student;


struct Node
{

	Student student;	//������

	struct Node* before = NULL;
	struct Node* next = NULL;	//ָ����

};


typedef struct Node* PNode;		//�ڵ����Ͷ���
typedef struct Node* LinkList;
