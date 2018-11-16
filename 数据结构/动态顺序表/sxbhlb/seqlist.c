#include"seqlist.h"

void SeqListPushBack(PSeqList ps, DataType data)//β��
{
	assert(ps);
	CheckCapacity(ps);
	ps->_pData[ps->_size] = data;//��size��λ�ò�
	ps->_size++;
}
void SeqListPopBack(PSeqList ps)//βɾ
{
	assert(ps);
	ps->_size--;
}

void SeqListPushFront(PSeqList ps, DataType data)//ͷ��
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i > 0; i--)//�Ȱѵڶ������󶼺�Ųһλ
	{
		ps->_pData[i - 1] = ps->_pData[i];
	}
	ps->_pData[0] = data;//����һ����ֵ
	ps->_size++;
	return;
}

void SeqListPopFront(PSeqList ps)//ͷɾ
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType data)//����λ�ò�
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i > pos; i--)
	{
		ps->_pData[i] = ps->_pData[i - 1];
	}
	ps->_pData[pos] = data;
	ps->_size++;
	return;
}
void SeqListErase(PSeqList ps, int pos)//����λ��ɾ
{
	assert(ps);
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
	return;
}
int SeqListFind(PSeqList ps, DataType data)//����dataԪ�ص�һ�γ��ֵ�λ��
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_pData[i] == data)
			return i;
	}
	return -1;
}
void CheckCapacity(PSeqList ps)//��������������˿���
{
	if (ps->_capacity = ps->_size)//�ж��Ƿ���Ҫ����
	{
		int newcapacity = ps->_capacity* 2;
		DataType*pnew = (DataType*)malloc(sizeof(DataType)*newcapacity);
		if (pnew == NULL)
		{
			printf("�ڴ�ռ䲻��\n");
			exit(1);//�˳�����
		}
		memcpy(pnew, ps->_pData, sizeof(DataType)*newcapacity);//�����ps->_pData�����׵�ַ
		free(ps->_pData);//�ͷžɿռ�
		ps->_pData = pnew;
		ps->_capacity = newcapacity;
		return;
	}
}

void SeqListRemoveAll(PSeqList ps, DataType data)//ɾ������ֵΪdata��Ԫ��
{
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_pData[i] == data)//��data��ɾ��iλ�õ�ֵһ��
		{
			int pos = i;
			int j = 0;
			for (j = pos; j > ps->_size; j++)
			{
				ps->_pData[j] = ps->_pData[j + 1];
			}
			count++;
		}
	}
	ps->_size = ps->_size - count;
	return;
}
void BubbleSort(PSeqList ps)//ð������˳�����Ԫ��,�����С������
{
	assert(ps);
	for (int j = ps->_size; j > 1; j--)//ð���ⲿ
	{
		int i = 0;
		for (i = 0; i < j; i++)//ð���ڲ�
		{
			if (ps->_pData[i]>ps->_pData[i + 1])//��С��������
			{
				ps->_pData[i] = (ps->_pData[i]) ^ (ps->_pData[i + 1]);
				ps->_pData[i + 1] = (ps->_pData[i]) ^ (ps->_pData[i + 1]);
				ps->_pData[i] = (ps->_pData[i]) ^ (ps->_pData[i + 1]);
			}
		}
	}
	return;
}
void SeqListInit(PSeqList ps, int capacity)//��������ʼ�����Ա�
{
	assert(ps);
	ps->_pData = (DataType *)calloc(sizeof(DataType)*capacity,0);//�����ռ�������ָ��ָ��
	if (ps->_pData != NULL)
	{
		ps->_size = 0;
		ps->_capacity = capacity;
	}
	else
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	return;
}
void seqlist()
{
	meau();
	int pos = 3;
	SeqList s;//�ṹ��������� �ṹ���Ա��sz��capacity����ջ�Ͽ��ٿռ� ����ָ��_pDate ��ָ��Ŀռ��ڶ��� 
	SeqListInit(&s, 10);//���൱������������ݵ����Ա��ڶ��� ����ͨ��ջ�ϵı���sz��capacity��������
	SeqListPushBack(&s, 1);//β��
	SeqListPopBack(&s);//βɾ
	SeqListPushFront(&s, 1);//ͷ��
	SeqListPopFront(&s);//ͷɾ
	SeqListInsert(&s, pos, 3);//����λ�ò�
	SeqListErase(&s, pos);//����λ��ɾ
	int num= SeqListFind(&s, 3);//��data���ص�λ��
	SeqListRemoveAll(&s, 3);//��ֵΪ3�Ķ�ɾ����
	BubbleSort(&s);//ð������˳���
}