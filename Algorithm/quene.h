#ifndef QUENE_H
#define QUENE_H

#define INIT_QUENE_LENGTH 10
#define QUENE_INCREMENT   1

// ��������
typedef int ElementType;


typedef struct Quene {
	ElementType* pBase;		// ջ��ָ��
	ElementType* pTop;		// ջ��ָ��
	int  iStackLength;		// ��ջ��С
}Stack;



#endif // !QUENE_H
