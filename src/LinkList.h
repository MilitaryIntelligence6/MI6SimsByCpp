//LinkList.h

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <afxstr.h>


// ѧ����Ϣ����struct�ڵ㶨��
typedef struct StudentInfo
{
	int num = 0;	//���
	CString name = _T("foobar");		//����
	bool sex = 1;			//�Ա�
	unsigned long long int id = 41800000;	//ѧ��
	CString clazz = NULL;		//�༶
	CString birthday = NULL;	//����
	// �ɼ�Ӧ����ArrayList֮��Ŀɱ���������, �����Ŀ�����;
	int dataStructure = 0;
	int computerNetwork = 0;
	int compilationPrinciple = 0;
	int androidDevelopment = 0;
} Student;


struct Node
{
	Student student;	//������

	struct Node* prev = NULL;
	struct Node* next = NULL;	//ָ����

};


typedef struct Node* PNode;		//�ڵ����Ͷ���
typedef struct Node* LinkList;
