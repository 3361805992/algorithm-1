#ifndef SEARCH_H
#define SEARCH_H

#define ARRSIZE 18
#define TRUE  1
#define FALSE 0

// ��������
typedef int ElementType;

typedef struct MyStruct
{
	int iNum;				// �������еĹؼ���
	int iStartIndex;		// ��������ʼ����ֵ
	int iSubTableLength;	// ��������
}SubTable;

/************************************************************************/
/*                              ���Һ���                                */
/************************************************************************/

/*�����㷨���ࣺ
 * 1����̬���ҺͶ�̬���ң�
 * ע����̬���߶�̬������Բ��ұ���Եġ���̬��ָ���ұ�����ɾ���Ͳ�������ı�

 * 2��������Һ��������
 * ������ң����������������������
 * ������ң����������б���Ϊ��������
*/

// ��������
int search_sequence(ElementType* arrData, int iArrLength, ElementType Num);		// ˳�����
int search_binary(ElementType* arrData, int iArrLength, ElementType Num);		// ���ֲ���
int search_insert(ElementType* arrData, int iArrLength, ElementType Num);		// ��ֵ����
int search_fibonacci(ElementType* arrData, int iArrLength, ElementType Num);	// 쳲���������
int search_block(ElementType* arrData, int iArrLength, ElementType Num);		// �ֿ����

int  get_fibonacci_length(int iArrLength);										// ȷ��쳲��������еĳ���

int  create_subtable(ElementType* arrData, int iArrLength,
	SubTable* pTable, int iTableNum);											// ����������
void show_table_info(SubTable * pTable, int iTableNum);							// ��ʾ��������Ϣ

void search_test(void);															// ���Ժ���

// ��������
int search_sequence(ElementType* arrData, int iArrLength, ElementType Num) {
	
	// ˳������ʺ��ڴ洢�ṹΪ˳��洢�����Ӵ洢�����Ա�
	// ����˼�룺˳�����Ҳ��Ϊ���β��ң�������������㷨��
	// �����ݽṹ���α��һ�˿�ʼ��˳��ɨ�裬���ν�ɨ�赽�Ľ��ؼ��������ֵk��Ƚϣ�
	// ��������ʾ���ҳɹ�����ɨ�������û���ҵ��ؼ��ֵ���k�Ľ�㣬��ʾ����ʧ�ܡ�

	int i;
	int iLocate = -1;
	for (i = 0; i < iArrLength; i++) {
		if (arrData[i] == Num) {
			iLocate = i;
			break;
		}
	}
	return iLocate;
}

int search_binary(ElementType* arrData, int iArrLength, ElementType Num) {
	// ��Ҫ���Ҷ���������ģ�ÿһ�ζ���1/2�Ĳ��֣����Ҵ������ļ����ˡ�ʱ�临�Ӷ���O(logN)
	// ���ھ�̬���ұ�һ��������ٱ仯���۰�����ܵõ������Ч�ʡ�
	// ��������ҪƵ��ִ�в����ɾ�����������ݼ���˵��ά�����������������С�Ĺ��������ǾͲ�����ʹ��
	
	int iLeft, iRight, iMid;
	int iLocate = -1;
	iLeft = 0;
	iRight = iArrLength - 1;
	
	if (Num > arrData[iRight] || Num < arrData[iLeft])
		iLeft = iRight + 1;

	while(iLeft <= iRight){
		iMid = (iLeft + iRight) / 2;
		if (Num < arrData[iMid]) {
			iRight = iMid - 1;
		}
		else if (Num > arrData[iMid]) {
			iLeft = iMid + 1;
		}
		else if(Num == arrData[iMid]){
			iLocate = iMid;
			break;
		}
	}
	return iLocate;
}

int search_insert(ElementType* arrData, int iArrLength, ElementType Num) {
	
	// ����˼�룺���ڶ��ֲ����㷨�������ҵ��ѡ��Ľ�Ϊ����Ӧѡ�񣬿�����߲���Ч�ʡ���Ȼ����ֵ����Ҳ����������ҡ�
	// ���ڱ��ϴ󣬶��ؼ��ֲַ��ֱȽϾ��ȵĲ��ұ���˵����ֵ�����㷨��ƽ�����ܱ��۰����Ҫ�õĶࡣ
	// ��֮������������ֲ��ǳ������ȣ���ô��ֵ����δ���Ǻܺ��ʵ�ѡ��
	
	int iLeft, iRight, iMid;
	int iLocate = -1;
	iLeft = 0;
	iRight = iArrLength - 1;

	if (Num > arrData[iRight] || Num < arrData[iLeft])
		iLeft = iRight + 1;

	while (iLeft <= iRight) {
		iMid = iLeft + (Num - arrData[iLeft]) / (arrData[iRight] - arrData[iLeft]) * (iRight - iLeft);
		if (Num < arrData[iMid]) {
			iRight = iMid - 1;
		}
		else if (Num > arrData[iMid]) {
			iLeft = iMid + 1;
		}
		else if (Num == arrData[iMid]) {
			iLocate = iMid;
			break;
		}
	}
	return iLocate;
}

int search_fibonacci(ElementType* arrData, int iArrLength, ElementType Num) {
	
	// Ҳ�Ƕ��ֲ��ҵ�һ�������㷨��ͨ�����ûƽ�����ĸ�����������ѡ����ҵ���в��ң���߲���Ч�ʡ�
	// ͬ���أ�쳲���������Ҳ����һ����������㷨��
	// 쳲������������۰���Һ����ƣ����Ǹ���쳲��������е��ص���������зָ�ġ�
	
	// Ҫ��ʼ���м�¼�ĸ���Ϊĳ��쳲�������С1����iArrLength = Fibonacci(k) - 1;
	// ��ʼ��kֵ���F(k - 1)λ�õļ�¼���бȽ�(��mid = low + Fibonacci(k - 1) - 1), �ȽϽ��Ҳ��Ϊ����
	// ��1����ȣ�midλ�õ�Ԫ�ؼ�Ϊ����
	// ��2�����ڣ�low = mid + 1, k -= 2;
	// ˵����low = mid + 1˵�������ҵ�Ԫ����[mid + 1, high]��Χ�ڣ�
	// k -= 2 ˵����Χ[mid + 1, high]�ڵ�Ԫ�ظ���Ϊn - (F(k - 1)) = Fk - 1 - F(k - 1) = Fk - F(k - 1) - 1 = F(k - 2) - 1�������Կ��Եݹ��Ӧ��쳲��������ҡ�
	// ��3��С�ڣ�high = mid - 1, k -= 1��
	// ˵����low = mid + 1˵�������ҵ�Ԫ����[low, mid - 1]��Χ�ڣ�
	// k -= 1 ˵����Χ[low, mid - 1]�ڵ�Ԫ�ظ���ΪF(k - 1) - 1�������Կ��Եݹ��Ӧ��쳲��������ҡ�
	
	int  iLeft, iMid, iRight;					// ������ֵ����ֵ����ֵ
	int  iLocate = -1;							// ������Ԫ������
	int  i,j;									// ѭ���±�
	int* arrFibonacci;							// ���ɵ�쳲���������
	ElementType* arrTempNum;					// �������ʱ����
	int iFibonacciArrLength, iTempArrLength;	// �Ʊ��������г��ȡ���ʱ���г���
	
	iLeft = 0; iRight = iArrLength - 1;
	
	if (Num > arrData[iRight] || Num < arrData[iLeft])
		return iLocate;

	iFibonacciArrLength = get_fibonacci_length(iArrLength);			// ��ȡ��Ӧ��쳲��������г���
	arrFibonacci = (int*)malloc(sizeof(int) * iFibonacciArrLength);	// ����ռ�
	genFibonacci(arrFibonacci, iFibonacciArrLength);				// ����쳲���������
	iTempArrLength = arrFibonacci[iFibonacciArrLength - 1] - 1;		// ��ʱ���еĳ���Ϊ��ǰ쳲��������е����һ���� - 1

	// ������ʱ����
	arrTempNum = (int*)malloc(sizeof(int)* iTempArrLength);
	for (i = 0; i < iArrLength; i++) {
		arrTempNum[i] = arrData[i];
	}
	for (i = iArrLength; i < iTempArrLength; i++) {
		arrTempNum[i] = arrData[iRight];
	}

	j = iFibonacciArrLength - 1;
	while (iLeft <= iRight) {
		iMid = iLeft + arrFibonacci[j - 1] - 1;
		if (Num > arrTempNum[iMid]) {
			iLeft = iMid + 1;
			j = j - 2;
		}
		else if (Num < arrTempNum[iMid]) {
			iRight = iMid - 1;
			j = j - 1;
		}
		else if (iMid <= iRight) {
			iLocate = iMid;
			break;
		}
		else{
			iLocate = iRight;
			break;
		}
	}
	
	free(arrFibonacci);
	arrFibonacci = NULL;

	free(arrTempNum);
	arrTempNum = NULL;

	return iLocate;
}

int search_block(ElementType* arrData, int iArrLength, ElementType iNum) {
	
	// �ֿ���ң���ÿһ���м�¼�Ĺؼ��ֲ�һ�����򣬵��ǿ����֮���������
	// �������������ǰ��ؼ���ֵ��������ģ���ȡ�����е����ؼ��ּ��ÿ����ʼλ�ù���������
	// �����˳������һ�������У���Ȼ�������������ģ�һ�㰴��������
	// �ӱ�����˵���ֿ���ҶԴ洢��������Ҫ���

	int iFlag;							// ����������ʶ
	int iTableNum;						// ���������
	int iLocate = -1;					// ������Ԫ������
	SubTable* pTable;					// ������
	int iLeft, iRight, iMid;	//
//	int iSubLeft, iSubRight, iSubMid;	// 

	iTableNum = 3;
	pTable = (SubTable*)malloc(sizeof(SubTable) * iTableNum);
	iFlag = create_subtable(arrData, iArrLength, pTable, iTableNum);

	if (iFlag == -1) {
		printf("��������ʧ��");
		return iLocate;
	}
	else {
		show_table_info(pTable, iTableNum);
		iLeft = 0; iRight = iTableNum - 1;
		while (iLeft <= iRight) {
			iMid = (iLeft + iRight) / 2;
			if (iNum <= pTable[iMid].iNum) {
				iRight = iMid - 1;
			}
			else{
				iLeft = iMid + 1;
			}
			printf("iLeft = %d, iMid = %d, iRight = %d\n", iLeft, iMid, iRight);
		}
		
	}

	free(pTable);
	pTable = NULL;

	return 0;
}

int get_fibonacci_length(int iArrLength) {
	int iNumber1 = 1;
	int iNumber2 = 1;
	int iNumber3;
	int iIndex;
	for (iIndex = 3; iIndex < iArrLength; iIndex++) {
		iNumber3 = iNumber1 + iNumber2;
		iNumber1 = iNumber2;
		iNumber2 = iNumber3;
		if (iNumber3 - 1 >= iArrLength)
			break;
	}
	return iIndex;
}

int create_subtable(ElementType * arrData, int iArrLength, SubTable * pTable, int iTableNum) {
	
	int* arrSubTable;			// �ӱ�
	int  iSubTableLength;		// �ӱ���
	MostValue tMax;				// �ӱ��е����Ԫ�ؼ�������ֵ
	int  i;						// ѭ���±�

	// ���ù̶�����ģʽ
	if (iArrLength % iTableNum != 0 || iTableNum > iArrLength) {
		return FALSE;			// ��������ʧ��
	}

	iSubTableLength = iArrLength / iTableNum;
	arrSubTable = (int*)malloc(sizeof(int) * iSubTableLength);
	for (i = 0; i < iTableNum; i++) {
		arr_copy(arrData + (i * iSubTableLength), arrSubTable, iSubTableLength);
		tMax = find_max(arrSubTable, iSubTableLength);
		pTable[i].iStartIndex = i * iSubTableLength;
		pTable[i].iSubTableLength = iSubTableLength;
		pTable[i].iNum = tMax.Value;
	}

	free(arrSubTable);
	arrSubTable = NULL;

	return TRUE;
}

void search_test(void) {
	//ElementType arrData[ARRSIZE] = { 22, 12, 13, 8, 9, 20, 33, 42, 44, 38, 24, 46, 60, 58, 74, 47, 86, 53 };
	ElementType arrData[ARRSIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
	ElementType Num = 12;
	int iLocate;
	int i;

	//iLocate = search_fibonacci(arrData, ARRSIZE, iNum);
	//iLocate = search_insert(arrData, ARRSIZE, iNum);
	iLocate = search_binary(arrData, ARRSIZE, Num);

	printf("����arrData�е�Ԫ�طֱ�Ϊ��");
	for (i = 0; i < ARRSIZE; i++) {
		printf("%d ", arrData[i]);
	}
	printf("\n");

	if (iLocate != -1) {
		printf("����arrData�д���Ԫ��%d���±�Ϊ��%d\n", Num, iLocate);
	}
	else{
		printf("����arrData�в�����Ԫ��%d\n", Num);
	}
}

void show_table_info(SubTable * pTable, int iTableNum) {
	int i;
	printf("��ǰ���д�����������Ϊ��\n");
	for (i = 0; i < iTableNum; i++) {
		printf("{ %d %d %d }\n", pTable[i].iNum, pTable[i].iStartIndex, pTable[i].iSubTableLength);
	}
}

#endif // !SEARCH_H
