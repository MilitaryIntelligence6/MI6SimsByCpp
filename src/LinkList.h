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
	// �ɼ�Ӧ����ArrayList֮��Ŀɱ���������, �����Ŀ�����;
	int dataStructure = 0;
	int computerNetwork = 0;
	int compilationPrinciple = 0;
	int androidDevelopment = 0;
}Student;


struct Node
{

	Student student;	//������

	struct Node* before = NULL;
	struct Node* next = NULL;	//ָ����

};


typedef struct Node* PNode;		//�ڵ����Ͷ���
typedef struct Node* LinkList;
