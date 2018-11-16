#include"slist.h"
#include<assert.h>
void my_printf(SListNode*head)//��ӡ
{
	SListNode *pur = head;
	while (pur)
	{
		printf("%d->", pur->_data);
		pur = pur->_pNext;
	}
	printf("NULL");
}
SListNode* buyslistnode(SLDataType data)//����һ���½ڵ�
{
	SListNode* pnewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pnewNode == NULL)
		exit(1);
	pnewNode->_data = data;
	pnewNode->_pNext = NULL;
	return pnewNode;

}
void SListInit(SListNode** pHead)//��ʼ��
{
	*pHead = NULL;
}

void SListPushBack(SListNode** pHead, SLDataType data)//β��
{
	assert(pHead);
	SListNode *ptur = *pHead;
	SListNode *pNewNode = buyslistnode(data);
	//����һ��Ԫ�ض�û��
	if (*pHead == NULL)
	{
		*pHead = pNewNode;
		return;
	}
	//����������Ԫ��
	while (ptur->_pNext)
	{
		ptur = ptur->_pNext;
	}
	ptur->_pNext = pNewNode;			
}
void SListPopBack(SListNode** pHead)//βɾ
{
	SListNode *ptur = *pHead;
	if (*pHead == NULL)//ûԪ��
	{
		return;
	}
		
	else if(ptur->_pNext==NULL)//��һ��Ԫ��
	{
		free(ptur);
		*pHead = NULL;
	}
	else//����������Ԫ��
	{
		while (ptur->_pNext->_pNext)
			ptur = ptur->_pNext;
		free(ptur->_pNext);
		ptur->_pNext = NULL;
	}	  
}
void SListPushFront(SListNode** pHead, SLDataType data)//ͷ��
{
	assert(pHead);
	SListNode *pur = *pHead;
	SListNode *pNewNode = buyslistnode(data);
	if (*pHead == NULL)//����һ����û��
		*pHead = pNewNode;
	else//����������һ��
	{
		pNewNode->_pNext = pur;
		*pHead = pNewNode;
	}
}
void SListPopFront(SListNode** pHead)//ͷɾ
{
	SListNode* pur = *pHead;
	assert(pHead);
	if (*pHead == NULL)//����ûԪ��
		return;
	else//������Ԫ��
	{
		pur = pur->_pNext;
		free(*pHead);
		*pHead = pur;
	}
}
void SListInsert(SListNode* pos, SLDataType data)//����λ�ò�
{
	if (pos == NULL)
	{
		return;
	}
	SListNode *pNewNode =buyslistnode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
void SListErase(SListNode** pHead, SListNode* pos)//����λ��ɾ
{
	SListNode*pur = *pHead;
	SListNode*ppos = pos;
	assert(pHead);
	if (*pHead == NULL)
		return;
	if (pos==*pHead)//���ɾ���ǵ�һ��λ��
	{
		SListPopFront(pHead);
	}
	else if(pos->_pNext == NULL)//���ɾ�������һ��λ��
	{
		SListPopBack(pHead);
	}
	else//ɾ����λ��
	{
		while (pur->_pNext != pos)
		{
			pur = pur->_pNext;
		}
		pur->_pNext = pur->_pNext->_pNext;
		free(ppos);
		ppos = NULL;
	}
}

SListNode* SListFind(SListNode* Head, SLDataType data)//ĳ��ֵ���ĸ�λ��
{
	if (Head == NULL)
	{
		return NULL;
	}
	SListNode *pur = Head;
	while (pur->_data !=data||pur==NULL)//�ҵ��������궼������
	{
		pur = pur->_pNext;
	}
	if (pur == NULL)
	{
		printf("û�����λ��\n");
		exit(1);
	}
	else
		return pur;		
}

void SListDestroy(SListNode** pHead)//�����������
{
	SListNode*pur = *pHead;
	while (pur != NULL)
	{
		pur = pur->_pNext;
		free(*pHead);
		*pHead = pur;//���pHead�Ѿ���NULL��
	}
}
SLDataType Front(SListNode* pHead)//�����Ԫ��
{
	return pHead->_data;//��Ҳ̫....
}
SLDataType Back(SListNode* pHead)//������һ��Ԫ��
{
	SListNode *pur = pHead;
	while (pur->_pNext!= NULL)
	{
		pur = pur->_pNext;
	}
	return pur->_data;
}
void SListRemoveAll(SListNode** pHead, SLDataType data)//ɾ������ֵΪdata�Ľ�� 1.����û��data 2.û�������
{
	assert(pHead);
	assert(*pHead);
	SListNode * pur = *pHead;
	SListNode * qpur = *pHead;
	
	while (pur)
	{
		
		if (pur->_data == data)
		{
			if (pur == *pHead)
			{
				*pHead = pur->_pNext;//ͷɾ
				free(pur);
				pur = *pHead;
			}
			else//ɾ����λ��
			{
				qpur->_pNext = pur->_pNext;
				free(pur);
				pur = qpur->_pNext;
			}		
		}
		else//������ǹؼ� �����Ŀ�ؼ�����ÿ�ν�ȥqpur Ҫ������purǰ��
		{
			qpur = pur;//pur����ǰ������qpur ����ܹؼ�
			pur = qpur->_pNext;
		}
		
	}
}
void SlistBubbleSort(SListNode* pHead)//ð����������
{
	assert(pHead);
	if (pHead == NULL)
	{
		return;
	}
	SListNode *pur = pHead;//��ʼð�������������
	SListNode *cur = pHead;
	int count = 0;
	while (pur->_pNext!= NULL)//�����һ�ν��� �����ĸ���㣨�����ڶ�����
	{
		cur = pur;
		while (cur->_pNext != NULL)
		{
			if ((cur->_data )>(cur->_pNext->_data))//��С��������
			{
				cur->_data = (cur->_data)^(cur->_pNext->_data);
				cur->_pNext->_data = (cur->_data) ^ (cur->_pNext->_data);
				cur->_data = (cur->_data) ^ (cur->_pNext->_data);
				count++;
			}
			cur = cur->_pNext;
		}
		if (count == 0)
		{
			return;
		}
		pur = pur->_pNext;
	}
	return;
}

//void SListRemoveAll(SListNode* pHead, SLDataType data)//ɾ������ֵΪdata�Ľ��
//{
	//assert(pHead);
	//SListNode *pur = pHead;
	
	
//}

void TestList3()//��������λ�ò��ɾ
{
	SListNode *Head;
	SListInit(&Head);//��ʼ��
	SListPushBack(&Head, 2);//β��
	SListPushBack(&Head, 2);//β��
	SListPushBack(&Head, 8);//β��
	SListPushBack(&Head, 2);//β��
	SListPushBack(&Head, 5);//β��
	SListPushBack(&Head, 2);//β��
	//SListInsert(SListFind(Head, 3), 10);//��3�����10
	//my_printf(Head);
	//printf("\n");
	//SListErase(&Head, SListFind(Head, 3));//ɾ��3λ�õ���
	//my_printf(Head);
	//printf("\n");
	//SListRemove(&Head, 6);
	//SlistBubbleSort(Head);
	//SListDestroy(&Head);
	SListRemoveAll(&Head, 2);
	my_printf(Head);
}

void TestList2()//����ͷ��ͷɾ
{
	SListNode *Head;
	SListInit(&Head);//��ʼ��
	SListPushFront(&Head, 1);
	SListPushFront(&Head, 2);
	SListPopFront(&Head);

	my_printf(Head);
}
void TestList1()//����β��βɾ
{
	SListNode *Head;
	SListInit(&Head);//��ʼ��
	SListPushBack(&Head, 1);//β��
	SListPushBack(&Head, 2);//β��
	SListPushBack(&Head, 3);//β��
	SListPushBack(&Head, 4);//β��
	SListPushBack(&Head, 5);//β��
	SListPushBack(&Head, 6);//β��
	
	SListPopBack(&Head);//βɾ
	my_printf(Head);
}