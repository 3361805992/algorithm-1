#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int iData;
	struct Node* next;
}List;

/*
 * ����Ļ���������
 * ������ɾ�����޸ġ����롢����
 * �ж������Ƿ�Ϊ��
 */

// ���������������������ϣ�(��)��ͷ��㣬ͷ(β)�巨
List* init_list_no_head_front();
List* init_list_no_head_back();

List * init_list_no_head_back() {
	List* previous, *current, *head;
	int iData;

	// �жϵ�ǰ����ֵ���룬��û����ֱ�ӷ��ؽ��
	if (scanf("%d", &iData) != EOF) {
		previous = (List*)malloc(sizeof(List));
		head = previous;
		previous->iData = iData;
	}

	else
		return head;

	// �����Ѿ�ȷ���˵�һ���ڵ������룬���ڶ�����㲻���������������ѭ��
	current = (List*)malloc(sizeof(List));
	while (scanf("%d", &current->iData) != EOF) {
		previous->next = current;
		previous = current;
		current = (List*)malloc(sizeof(List));
	}
	previous->next = NULL;//ѡ��prev������current��Ϊ�˱���û������ڶ����������
	return head;
}

#endif /* LIST_H */
