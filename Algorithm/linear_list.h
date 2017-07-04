#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#define YES 1
#define NO  0
#define TRUE 1
#define FALSE 0
#define LIST_INIT_SIZE 10			// ���Ա��ʼ������

#include <stdio.h>
#include <stdlib.h>

// ��������
typedef int ElementType;

typedef struct{
	ElementType* arrData;			// ���Ա��׵�ַ
	int iListLength;				// ���Ա���(���ڱ�ʾ���Ա�ǰ�Ĵ洢״̬)
	int iListSize;					// ���Ա�ռ�(���ڱ�ʾ���Ա��ʼ��ʱ����ı����ռ�)
}LinearList;

// ��������
void init_list(LinearList* L);		// ��ʼ�����Ա�
void destroy_list(LinearList* L);	// �������Ա�
void clear_list(LinearList* L);		// ���Ա��ÿ�
int  isEmpty_list(LinearList* L);	// �ж����Ա��Ƿ�Ϊ��
int  isFull_list(LinearList* L);	// �ж����Ա��Ƿ�����


// ��������
void init_list(LinearList* L) {
	L->arrData = (ElementType*)malloc(sizeof(ElementType) * LIST_INIT_SIZE);
	if (L->arrData == NULL) {
		printf("���Ա��ʼ��ʧ��\n");
	}
	L->iListLength = 0;
	L->iListSize = LIST_INIT_SIZE;
}

void destroy_list(LinearList* L) {
	if (L->arrData == NULL) {
		printf("��ǰ���Ա���δ��ʼ��\n");
		return;
	}
	else {
		L->arrData = NULL;
		L->iListLength = 0;
		L->iListSize = 0;
	}
}

void clear_list(LinearList* L) {

}

int  isEmpty_list(LinearList* L) {
	return 0;
}
#endif // !LINEAR_LIST_H
