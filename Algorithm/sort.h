#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

/************************************************************************/
/*                    ��������Ĭ�ϰ���������                          */
/************************************************************************/

// ��������
typedef int ElementType;

typedef struct MostValue {
	ElementType Value;
	int iLocation;
}MostValue;	// ����ȷ�����������ֵ����Сֵ����ֵ��λ��

// ��������
void swap(ElementType* iNumA, ElementType* iNumB);							// ����������
void sort_quick_recursion(ElementType * arrData, int iLeft, int iRight);	// ��������ݹ麯��
void merge(ElementType* arrData, int iLeft, int iMid, int iRight);			// ���кϲ�
void sort_merge_recursion(ElementType* arrData, int iLeft, int iRight);		// �鲢����ݹ麯��

// ���������㷨������ͬ�Ľӿڣ�arrData��ʾ���������飬iArrLength��ʾ�����С
void sort_bubble(ElementType * arrData, int iArrLength);					// ð������
void sort_insert(ElementType * arrData, int iArrLength);					// ��������
void sort_quick(ElementType* arrData, int iArrLength);						// ��������
void sort_selection(ElementType* arrData, int iArrLength);					// ѡ������
void sort_shell(ElementType* arrData, int iArrLength);						// ϣ������
void sort_merge(ElementType* arrData, int iArrLength);						// �鲢����
void sort_bucket(ElementType* arrData, int iArrLength);						// Ͱ����
void sort_radix(int* arrData, int iArrLength);								// ��������
void sort_heap(int* arrData, int iArrLength);								// ������

MostValue find_max(ElementType* arrData, int iArrLength);					// �ҵ����������ֵ����ֵ��λ��
MostValue find_min(ElementType* arrData, int iArrLength);					// �ҵ���������Сֵ����ֵ��λ��
int find_max_length(int* arrData, int iNumber);								// �ҵ�������������ĳ��ȣ����ҵ����λ����
int get_number(int iNumber, int iPos);										// �õ������и�λ�ε���ֵ
void heap_adjust(int* arrData, int i, int iArrLength);						// �������鹹���󶥶� 

void sort_test(void);														// ���Ժ���

// ��������
void swap(ElementType* NumA, ElementType* NumB)
{
	// ������������ֵ
	ElementType NumTemp;

	NumTemp = *NumA;
	*NumA = *NumB;
	*NumB = NumTemp;
}

void sort_bubble(ElementType* arrData, int iArrLength) {
	// ð������
	int i, j;		// ѭ���±�

	for (i = 0; i < iArrLength - 1; i++){
		for (j = i + 1; j < iArrLength; j++){
			if (arrData[i] > arrData[j]){
				swap(&arrData[i], &arrData[j]);
		
			}
		}
	}
}

void sort_insert(ElementType* arrData, int iArrLength){
	// ��������
	/* �㷨���裺
	* 1.�ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
	* 2.ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ��
	* 3.�����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ��
	* 4.�ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ��
	* 5.����Ԫ�ز��뵽��λ����
	* 6.�ظ�����2
	*/

	int i, j;				// ѭ���±�
	ElementType Temp;		// ���ڽ������м����

	for (i = 1; i < iArrLength; i++) {
		Temp = arrData[i];
		for (j = i; j > 0 && arrData[j - 1] > Temp; j--) {
			arrData[j] = arrData[j - 1];
		}
		arrData[j] = Temp;
	}
}

void sort_quick_recursion(ElementType* arrData, int iLeft, int iRight) {
	// ��������
	/* �㷨ԭ��
	* 1.������������һ��Ԫ����Ϊ����׼��
	* 2.���¶����н������򣬱Ȼ�׼С�ķ���ǰ�棬�Ȼ�׼��ķ��ں���
	* 3.�ݹ�ذ�С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������
	**/
	int i, j;
	ElementType Pivot;
	if (iLeft < iRight) {
		i = iLeft; j = iRight;
		Pivot = arrData[iLeft];
		while (i < j) {
			while (i < j && arrData[j] >= Pivot)
				j--;
			if (i < j)
				arrData[i++] = arrData[j];
			while (i < j && arrData[i] < Pivot)
				i++;
			if (i < j)
				arrData[j--] = arrData[i];
		}
		arrData[i] = Pivot;
		sort_quick_recursion(arrData, iLeft, i - 1);
		sort_quick_recursion(arrData, i + 1, iRight);
	}
}

void sort_quick(ElementType* arrData, int iArrLength) {
	int iLeft, iRight;
	iLeft = 0; iRight = iArrLength - 1;
	sort_quick_recursion(arrData, iLeft, iRight);
}

void heap_adjust(int* arrData, int i, int iArrLength) {
	// arrDataΪ�������Ķ����飬i�Ǵ�����������Ԫ�ص�λ�ã�iArrLength������ĳ���
	int iChild;
	for (; 2 * i + 1 < iArrLength; i = iChild) {
		iChild = 2 * i + 1;		// �ֽڵ��λ�� = 2 * ���ڵ�λ�� + 1
		if (iChild < iArrLength - 1 && arrData[iChild + 1] > arrData[iChild])
			iChild++;
		// ����ϴ���ӽڵ���ڸ��ڵ㣬��ô�ø��ӽڵ��滻���ڵ�
		if (arrData[i] < arrData[iChild]) {
			swap(&arrData[i], &arrData[iChild]);
		}
		else
			break;
	}
}

void sort_selection(ElementType* arrData, int iArrLength)
{
	// ѡ������
	int i, j;			// ѭ������
	int iMinIndex;		// ��Сֵ�±�

	for (i = 0; i < iArrLength - 1; i++) {
		iMinIndex = i;
		for (j = i + 1; j < iArrLength; j++) {
			if (arrData[iMinIndex] > arrData[j]) {
				iMinIndex = j;
			}
		}
		swap(&arrData[i], &arrData[iMinIndex]);
	}
}

void sort_shell(ElementType* arrData, int iArrLength) {
	// ϣ������Ҳ�Ƶݼ����������㷨���ǲ��������һ�ָ��ٶ��ȶ��ĸĽ��汾
	int i, j;			// ѭ���±�
	int iGap;			// ����
	for (iGap = iArrLength / 2; iGap >= 1; iGap /= 2) {
		for (i = iGap; i < iArrLength; i++) {
			for (j = i - iGap; j >= 0 && arrData[j] > arrData[j + iGap]; j -= iGap) {
				swap(&arrData[j], &arrData[j + iGap]);
			}

		}
	}
}

void sort_merge_recursion(ElementType* arrData, int iLeft, int iRight) {
	// �鲢��Merge�������ǽ����������������ϣ������ϲ���һ���µ������
	// ���Ѵ��������з�Ϊ���ɸ������У�ÿ��������������ġ�Ȼ���ٰ����������кϲ�Ϊ�����������С�
	int iMid;
	if (iLeft < iRight) {
		iMid = (iLeft + iRight) / 2; /* ע���ֹ��� */
		sort_merge_recursion(arrData, iLeft, iMid);
		sort_merge_recursion(arrData, iMid + 1, iRight);
		merge(arrData, iLeft, iMid, iRight);
	}
}

void sort_merge(ElementType* arrData, int iArrLength) {
	int iLeft, iRight;
	iLeft = 0; iRight = iArrLength - 1;
	sort_merge_recursion(arrData, iLeft, iRight);
}

void sort_heap(int* arrData, int iArrLength)
{
	// ������
	/*
	* 1.������ȫ������
	* 2.�󶥶ѣ�ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ����Ϊ�󶥶ѡ�
	* 3.С���ѣ�ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ����ΪС���ѡ�
	* ���i > 1����˫���ǽ��[i/2]��Ҳ����˵�±�i��2i��2i+1��˫����Ů��ϵ��
	* ���������Ϊ����ʱ���±��0��ʼ�������±� i ���±� 2i+1��2i+2��˫����Ů��ϵ��
	*/

	/* �㷨���裺
	* 1.�Ƚ����鹹����һ���󶥶�
	* 2.����ȫ������������һ�����ұߵķ��ն˽ڵ㿪ʼ����
	*/
	int i;
	for (i = iArrLength / 2 - 1; i >= 0; i--)
		heap_adjust(arrData, i, iArrLength);
	for (i = iArrLength - 1; i > 0; i--) {
		swap(&arrData[i], &arrData[0]);
		heap_adjust(arrData, 0, i);
	}
}

void sort_bucket(ElementType* arrData, int iArrLength) {
	int i, j;
	ElementType BucketNum;
	ElementType* arrBucket;
	MostValue tMax;

	tMax = find_max(arrData, iArrLength);	// �ҵ������е����ֵ������ȷ��Ͱ�ĸ���
	BucketNum = tMax.Value + 1;				// ��������ֵ��0��ʼ�����Ͱ�ĸ��������ֵ��1
	arrBucket = (ElementType*)malloc(sizeof(int) * (BucketNum));
	
	for (i = 0; i < BucketNum; i++)
		arrBucket[i] = 0;					// ��ʼ��Ͱ���������ݾ�Ϊ0

	for (i = 0; i < iArrLength; i++)		// �������е�ֵ���뵽��Ӧ��Ͱ�ڣ�������1�ͷ���1��Ͱ������10�ͷ���10��Ͱ
		arrBucket[arrData[i]]++;			// ���ǵ��������ظ�Ԫ�س��֣����Ͱ�ڴ�ŵ���ÿ��Ԫ�س��ֵĴ���

	j = 0;
	for (i = 0; i < BucketNum; i++) {	// ����С�����˳��Ͱ��Ԫ���������
		while (arrBucket[i]--){
			arrData[j++] = i;
		}
	}
	free(arrBucket);
	arrBucket = NULL;
}

void sort_radix(int* arrData, int iArrLength) {
	/*	��������
		������10���ư�ÿλ��֣�Ȼ��ӵ�λ����λ���αȽϸ���λ��ÿ�αȽ����������ֱ��������������
		��Ҫ��Ϊ�������̣�
		(1)���䣬�ȴӸ�λ��ʼ������λֵ(0 - 9)�ֱ�ŵ�0 - 9��Ͱ�У�����53, ��λΪ3�������3��Ͱ�У�
		(2)�ռ����ٽ�������0 - 9��Ͱ�е����ݰ�˳��ŵ�������
		�ظ�(1)(2)���̣��Ӹ�λ�����λ��ֱ���ź���Ϊֹ������32λ�޷������������4294967296�����λ10λ��
	*/
	int i, j, k;				// ѭ������
	int iPos;					// λ������
	int iTempNum;				// ��ǰλ
	int iIndex;					// Ͱ��Ԫ������
	int iMaxDigit;				// ���λ��
	int iCounts[10];			// ���ڼ�¼ÿ��Ͱ�е�Ԫ�ظ���
	int * arrRadix[10];

	for (i = 0; i < 10; i++) {	// ��ʼ����iCounts[i]�洢Ͱ��Ԫ�صĸ�������ֵ��Ϊ0
		arrRadix[i] = (int*)malloc(sizeof(int)*(iArrLength + 1));
		iCounts[i] = 0;
	}

	iMaxDigit = find_max_length(arrData, iArrLength);	// ȷ�����������Ԫ�ص�λ��
	
	for (iPos = 1; iPos <= iMaxDigit; iPos++) {
		for (i = 0; i < iArrLength; i++) {
			iTempNum = get_number(arrData[i], iPos);	// ��ȡiPosλ��1Ϊ��λ��2Ϊʮλ����������
			iIndex = iCounts[iTempNum]++;
			arrRadix[iTempNum][iIndex] = arrData[i];
		}

		j = 0;
		for (i = 0; i < 10; i++) {
			for (k = 0; k < iCounts[i]; k++) {
				arrData[j++] = arrRadix[i][k];
			}
			iCounts[i] = 0;
		}
	}

	// ָ������Ŀռ��ͷ�
	for (i = 0; i < 10; i++) {
		free(arrRadix[i]);
		arrRadix[i] = NULL;
	}
}

void merge(ElementType* arrData, int iLeft, int iMid, int iRight) {
	
	// ��r[i��n]�����������ӱ� r[i��m] �� r[m + 1��n] ��ɣ������ӱ��ȷֱ�Ϊn - i + 1��n - m��
	// 1.j = m + 1��k = i��i = i; �������ӱ����ʼ�±꼰�����������ʼ�±�
	// 2.��i > m ��j > n��ת�� //����һ���ӱ��Ѻϲ��꣬�Ƚ�ѡȡ����
	// 3.ѡȡr[i]��r[j]��С�Ĵ��븨������rf
	//	 ���r[i] < r[j]��rf[k] = r[i]�� i++�� k++�� ת��
	//	 ����rf[k] = r[j]�� j++�� k++�� ת��
	// 4.����δ��������ӱ���Ԫ�ش���rf
	//	 ���i <= m����r[i��m]����rf[k��n] //ǰһ�ӱ�ǿ�
	//   ���j <= n, ��r[j��n] ����rf[k��n] //��һ�ӱ�ǿ�
	// 5.�ϲ�����

	int  i, j;
	ElementType* arrTemp = (ElementType*)malloc(sizeof(int) * (iRight - iLeft + 1));
	//����ռ䣬ʹ���СΪ����
	int iLeftLow = iLeft;
	int iLeftHigh = iMid;
	int iRightLow = iMid + 1;
	int iRightHigh = iRight;

	// �Ƚ�����ָ����ָ���Ԫ��
	for (i = 0; iLeftLow <= iLeftHigh && iRightLow <= iRightHigh; i++) {
		if (arrData[iLeftLow] <= arrData[iRightLow]) {
			arrTemp[i] = arrData[iLeftLow++];
		}
		else {
			arrTemp[i] = arrData[iRightLow++];
		}
	}

	//����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
	if (iLeftLow <= iLeftHigh) {
		for (j = iLeftLow; j <= iLeftHigh; j++)
			arrTemp[i++] = arrData[j];
	}

	//���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
	if (iRightLow <= iRightHigh) {
		for (j = iRightLow; j <= iRightHigh; j++)
			arrTemp[i++] = arrData[j];
	}

	for (i = 0; i < iRight - iLeft + 1; i++)
		arrData[iLeft + i] = arrTemp[i];

	free(arrTemp);
	arrTemp = NULL;
}

MostValue find_max(ElementType* arrData, int iArrLength) {
	int i;
	MostValue tMax;
	tMax.Value = arrData[0];
	tMax.iLocation = 0;

	for (i = 1; i < iArrLength; i++) {
		if (arrData[i] > tMax.Value) {
			tMax.Value = arrData[i];
			tMax.iLocation = i;
		}
	}
	return tMax;
}

MostValue find_min(ElementType* arrData, int iArrLength) {
	int i;
	MostValue tMin;
	tMin.Value = arrData[0];
	tMin.iLocation = 0;

	for (i = 1; i < iArrLength; i++) {
		if (arrData[i] < tMin.Value) {
			tMin.Value = arrData[i];
			tMin.iLocation = i;
		}
	}
	return tMin;
}

int find_max_length(int* arrData, int iNumber) {
	int iDigit = 0;
	MostValue tMax;
	tMax = find_max(arrData, iNumber);
	while (tMax.Value){
		tMax.Value /= 10;
		iDigit++;
	}
	return iDigit;
}

int get_number(int iNumber, int iPos) {
	int iTemp = 1;
	int i;
	for (i = 0; i < iPos - 1; i++) {
		iTemp *= 10;
	}
	iTemp = (iNumber / iTemp) % 10;
	return iTemp;
}

void sort_test(void) {

	ElementType iArrNumber = 10;
	int iMin = 0, iMax = 1000;

	int * arrData = (int*)malloc(sizeof(int) * iArrNumber);
	int i;

	genRand(arrData, iMin, iMax, iArrNumber);

	printf("����ǰ��");
	for (i = 0; i < iArrNumber; i++) {
		printf("%d ", arrData[i]);
	}

	printf("\n\n");

	sort_bucket(arrData, iArrNumber);

	printf("\n�����");
	for (i = 0; i < iArrNumber; i++) {
		printf("%d ", arrData[i]);
	}
	printf("\n");

	free(arrData);
	arrData = NULL;
}

#endif // !SORT_H
