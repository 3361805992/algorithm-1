#ifndef HASH_H
#define HASH_H

void create_hash_table(int * arrHash);							// ����Hash��
int search_hash(int * arrData, int iArrLength, int iNum);		// ��ϣ����
int  hash_function(int iNum, int iHashLength, int iHashType);	// ɢ�к���
int  hash_function_address(int iNum, int iHashLength,
	int iWeight, int iBias);									// ֱ�Ӷ�ַ��Hash
int  hash_function_mod(int iNum, int iHashLength);				// ����������Hash

int  generate_prime(int iArrLength);							// ����ԭʼ���еĳ��Ȳ������Ӧ��������С


int search_hash(int * arrData, int iArrLength, int iNum) {

}

int  hash_function(int iNum, int iHashLength, int iHashType) {
	// ��ϣ��������
	// ͨ��ĳ��ת����ϵ��ʹ�ؼ����ʶȵķ�ɢ��ָ����С�ĵ�˳��ṹ�У�Խ��ɢ�����Ժ���ҵ�ʱ�临�Ӷ�ԽС���ռ临�Ӷ�Խ�ߡ�
	// �㷨���̣�
	// 1���ø����Ĺ�ϣ���������ϣ��
	// 2������ѡ��ĳ�ͻ�����������ַ��ͻ��
	//�����Ľ����ͻ�ķ�����������������̽�ⷨ��

	int iHash;
	int iWeight, iBias;
	if (iHashType == 0) {
		// ֱ�Ӷ�ַ�����ؼ��ַ��䲻�������洢�ռ��˷�
		// �򵥡����ȣ����������ͻ��������Ҫ����֪���ؼ��ֵķֲ�������ʺϲ��ұ��С�������������
		iHash = iWeight * iNum + iBias;
	}

	else if (iHashType == 1) {
		// �������������ùؼ���K����ɢ�б���m����������Ϊɢ�е�ַ�ķ���
		// ����򵥣����÷�Χ��
		iHash = iNum % iHashLength;
	}

	else if (iHashType == 2) {

	}

	return iHash;

}

#endif // !HASH_H
