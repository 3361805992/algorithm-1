#ifndef STACK_H
#define STACK_H

#define YES 1
#define NO  0
#define INIT_STACK_LENGTH 10
#define STACK_INCREMENT 1

#include <stdio.h>
#include <stdlib.h>

// ��������
typedef int ElementType;

// ��̬����
typedef struct Stack{
	ElementType stack[INIT_STACK_LENGTH];
	int iTopPoint;
}Stack_Static;

// ��̬����
typedef struct Stack {
	ElementType* pBase;		// ջ��ָ��
	ElementType* pTop;		// ջ��ָ��
	int  iStackLength;		// ��ջ��С
}Stack_Dynamic;

// ������ʵ��
typedef struct STACK_NODE
{
	ElementType iNum;
	struct STACK_NODE *next;
} StackNode;

/*
 ջ��stack���������ص��Ǻ���ȳ���Last - In First - Out, LIFO����
 ��ʵ�ֵķ��������ֿ�ѡ��������̬���顢��̬��������顢��̬�������ʽ�ṹ��
 1.��̬���飺�ص���Ҫ��ṹ�ĳ��ȹ̶������ҳ����ڱ���ʱ��͵�ȷ�������ŵ��ǽṹ�򵥣�ʵ����������������׳�����ȱ����ǲ�������Լ��̶����Ȳ����׿��ƣ�������֪����ȷ���ȵĳ��ϡ�
 2.��̬���飺�ص��ǳ��ȿ���������ʱ���ȷ���Լ����Ը���ԭ������ĳ��ȡ��ŵ�����ȱ�����ɴ˻����ӳ���ĸ����ԡ�
 3.��ʽ�ṹ���ص����޳������ߣ���Ҫ��ʱ������������ڴ�ռ䣬�����̶���ʵ������ԡ�ȱ������ʽ�ṹ�������ֶ���Ҫ����һ�����ڴ棬����ʽ�ṹ�з���һ���ض�Ԫ�ص�Ч�ʲ������顣
*/

/************************************************************************/
/*                             ��̬����ʵ��                             */
/************************************************************************/

// ��������
void init_stack(Stack_Static* pStack);								// ��ʼ��ջ�ռ�
void push(int iNumber);												// ������ջ
void pop(void);														// ���ݳ�ջ
int  isEmpty_stack(void);											// �жϵ�ǰջ�Ƿ��
int  isFull_stack(void);											// �жϵ�ǰջ�Ƿ���
void clear_stack(void);												// ���ջ
int  get_stack_length(void);										// ��ȡջ��С
void printf_stack_info(void);										// ��ʾջ��Ԫ��
ElementType get_top(void);											// ��ȡջ��Ԫ��
void test_stack_static(void);										// ���Ժ���

// ��������
void init_stack(Stack_Static* pStack) {
	Stack_Static stack;
	pStack = &stack;
	pStack->iTopPoint = -1;
}

void push(int iNumber) {
	if (isFull_stack() == YES) {
		printf("��ǰջ����\n");
	}
	else {
		stack[iTopPoint++] = iNumber;
		//printf("iTopPoint = %d\n", iTopPoint);
	}
}

void pop(void) {
	if (isEmpty_stack() == YES) {
		printf("��ǰջΪ��\n");
	}
	else{
		printf("Ԫ��%d��ջ\n", stack[iTopPoint-1]);
		iTopPoint--;
		//printf("iTopPoint = %d\n", iTopPoint);
	}
}

int isEmpty_stack(void) {
	int iFlag;
	if (iTopPoint == -1) {
		iFlag = YES;
	}
	else {
		iFlag = NO;
	}
	return iFlag;
}

int isFull_stack(void) {
	int iFlag;
	if (iTopPoint == INIT_STACK_LENGTH - 1) {
		iFlag = YES;
	}
	else {
		iFlag = NO;
	}
	return iFlag;
}

void clear_stack(void) {
	iTopPoint = -1;
}

int get_stack_length(void) {
	return INIT_STACK_LENGTH;
}

void printf_stack_info(void) {
	int iTempPoint;
	if (isEmpty_stack() == YES) {
		printf("��ǰջΪ��\n");
		return;
	}
	else {
		iTempPoint = -1;
		printf("��ǰջ��Ԫ��Ϊ��");
		while(iTempPoint != iTopPoint){
			printf("%d ", stack[iTempPoint++]);
		}
		printf("\n");
	}
}

ElementType get_top(void) {
	return stack[iTopPoint];
}

void test_stack_static(void) {
	pop();
	push(10); push(9); push(7); push(6); push(5);
	printf_stack_info();
	printf("��ǰջ��СΪ��%d\n", get_stack_length());
	pop(); pop();
	printf_stack_info();
	printf("%d", iTopPoint);

}

/************************************************************************/
/*                             ��̬����ʵ��                             */
/************************************************************************/
 
// ��������
void create_stack(Stack_Dynamic* pStack);										// ������ջ
void destory_stack(Stack_Dynamic* pStack);										// ���ٶ�ջ
void fill_stack(Stack_Dynamic* pStack, ElementType* arrData, int iArrLength);	// ��ջ��ֵ
void push(Stack_Dynamic* pStack, int iNumber);									// ������ջ
void pop(Stack_Dynamic* pStack);												// ���ݳ�ջ
int  isEmpty_stack(Stack_Dynamic* pStack);										// �жϵ�ǰջ�Ƿ��
int  isFull_stack(Stack_Dynamic* pStack);										// �жϵ�ǰջ�Ƿ���
void clear_stack(Stack_Dynamic* pStack);										// ���ջ
int  get_stack_length(Stack_Dynamic* pStack);									// ��ȡջ��С
void printf_stack_info(Stack_Dynamic* pStack);									// ��ʾջ��Ԫ��
ElementType get_top(Stack_Dynamic* pStack);										// ��ȡջ��Ԫ��

void test_stack_dynamic(void);													// ���Դ���

// ��������
void create_stack(Stack_Dynamic* pStack) {
	pStack->pBase = (ElementType*)malloc(sizeof(ElementType) * INIT_STACK_LENGTH);
	if (!pStack->pBase) {
		printf("ջ��ʼ��ʧ��\n");
	}
	else {
		pStack->pTop = pStack->pBase;
		pStack->iStackLength = INIT_STACK_LENGTH;
		printf("ջ��ʼ���ɹ�\n");
	}
}

void fill_stack(Stack_Dynamic* pStack, ElementType* arrData, int iArrLength) {
	int iFlag;
	int i;
	iFlag = isEmpty_stack(pStack);
	if (iFlag == YES) {
		printf("��ǰջΪ��\n");
		return;
	}
	else {
		i = 0;
		pStack->pTop = pStack->pBase;
		if (iArrLength > INIT_STACK_LENGTH) {
			pStack->pBase = (ElementType*)realloc(pStack->pBase, sizeof(ElementType) * iArrLength);
			pStack->iStackLength = iArrLength;
			while (pStack->pTop - pStack->pBase < iArrLength) {
				*(pStack->pTop) = arrData[i];
				pStack->pTop++;
				i++;
			}
		}
		else {
			while (pStack->pTop - pStack->pBase < iArrLength) {
				*(pStack->pTop) = arrData[i];
				pStack->pTop++;
				i++;
			}
			while(pStack->pTop - pStack->pBase >= iArrLength && pStack->pTop - pStack->pBase < INIT_STACK_LENGTH){
					*(pStack->pTop) = 0;
					pStack->pTop++;
			}
		}
	}
}

void printf_stack_info(Stack_Dynamic* pStack) {
	ElementType* pTemp;
	int iFlag;
	iFlag = isEmpty_stack(pStack);
	if (iFlag == YES) {
		printf("��ǰջΪ��\n");
		printf("��ǰջ��СΪ��%d\n", pStack->iStackLength);
		return;
	}
	else{
		pTemp = pStack->pBase;

		printf("��ջ��ǰ��Ԫ�طֱ�Ϊ��\n");
		while (pTemp != pStack->pTop) {
			printf("%d ", *pTemp);
			pTemp++;
		}
		printf("\n��ǰջ��СΪ��%d\n", pStack->iStackLength);
	}
}

void destory_stack(Stack_Dynamic* pStack) {
	if(pStack == NULL){
		printf("��ǰջ��δ��ʼ��\n");
		return;
	}
	else {
		free(pStack->pBase);
		pStack = NULL;
	}
}

int isEmpty_stack(Stack_Dynamic* pStack) {
	int iFlag;
	if (pStack->pBase == pStack->pTop) {
		iFlag = YES;
	}
	else {
		iFlag = NO;
	}

	return iFlag;
}

ElementType get_top(Stack_Dynamic* pStack) {
	int iFlag;
	ElementType TopNumber;

	iFlag = isEmpty_stack(pStack);
	if (iFlag == YES) {
		printf("��ǰջΪ��\n");
		return 0;
	}
	else {
		TopNumber = *(pStack->pTop - 1);
	}
	return TopNumber;
}

int isFull_stack(Stack_Dynamic* pStack) {
	int iFlag;
	if (pStack->pTop - pStack->pBase == pStack->iStackLength) {
		iFlag = YES;
	}
	else {
		iFlag = NO;
	}
	return iFlag;
}

void push(Stack_Dynamic* pStack, int iNumber) {
	int iFlag;
	iFlag = isFull_stack(pStack);
	if (iFlag == YES) {
		pStack->pBase = (ElementType*)realloc(pStack->pBase, 
			sizeof(ElementType) * (pStack->iStackLength + STACK_INCREMENT));
		pStack->iStackLength++;
		*(pStack->pTop) = iNumber;
		pStack->pTop++;
		printf("Ԫ��%d��ջ\n", iNumber);
	}
	else {
		*(pStack->pTop) = iNumber;
		pStack->pTop++;
		printf("Ԫ��%d��ջ\n", iNumber);
	}
}

void pop(Stack_Dynamic* pStack) {
	int iFlag;
	iFlag = isEmpty_stack(pStack);
	if (iFlag == YES) {
		printf("��ǰջΪ��\n");
		return;
	}
	else{
		printf("Ԫ��%d��ջ\n", *(pStack->pTop - 1));
		pStack->pTop--;
	}
}

void clear_stack(Stack_Dynamic* pStack) {
	int iFlag;
	iFlag = isEmpty_stack(pStack);
	if (iFlag == YES) {
		printf("��ǰջΪ��\n");
	}
	else {
		pStack->pTop = pStack->pBase;
		pStack->iStackLength = 0;
		printf("��ǰջ�����\n");
	}
}

int get_stack_length(Stack_Dynamic* pStack) {
	int iStackLength;
	iStackLength = pStack->iStackLength;
	return iStackLength;
}

void test_stack_dynamic(void) {
	Stack_Dynamic stack, *pStack;
	ElementType* arrData;
	int iArrLength = 6;
	ElementType Min = 10, Max = 100;

	pStack = &stack;
	arrData = (ElementType*)malloc(sizeof(ElementType) * iArrLength);
	genRand(arrData, Min, Max, iArrLength);
	
	create_stack(pStack);
	fill_stack(pStack, arrData, iArrLength);
	printf_stack_info(pStack);
	clear_stack(pStack);
	pop(pStack); pop(pStack); pop(pStack);
	push(pStack, 1); push(pStack, 2); push(pStack, 3); push(pStack, 4); push(pStack, 5);
	printf_stack_info(pStack);
	destory_stack(pStack);

	free(arrData);
	arrData = NULL;
}

/************************************************************************/
/*                               ����ʵ��                               */
/************************************************************************/

// ��������
void push(StackNode* pStack);									// ��ջ
void pop(StackNode* pStack);
int  isEmpty(StackNode* pStack);								// �жϵ�ǰջ�Ƿ�Ϊ��

void test_stack_link(void);										// ���Գ���

// ��������
int isEmpty(StackNode* pStack) {
	int iFlag;
	if (pStack == NULL) {
		iFlag = YES;
	}
	else {
		iFlag = NO;
	}
	return iFlag;
}

void push(StackNode* pStack, int iNumber) {

}

void test_stack_link(void) {
	StackNode stack, *pStack;
	pStack = &stack;
	if (isEmpty(pStack) == YES) {
		printf("��ǰջΪ��\n");
	}
}

#endif // !STACK_H
