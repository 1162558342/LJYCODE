#include"slist.h"
#include<assert.h>
void my_printf(SListNode*head)//打印
{
	SListNode *pur = head;
	while (pur)
	{
		printf("%d->", pur->_data);
		pur = pur->_pNext;
	}
	printf("NULL");
}
SListNode* buyslistnode(SLDataType data)//开辟一个新节点
{
	SListNode* pnewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pnewNode == NULL)
		exit(1);
	pnewNode->_data = data;
	pnewNode->_pNext = NULL;
	return pnewNode;

}
void SListInit(SListNode** pHead)//初始化
{
	*pHead = NULL;
}

void SListPushBack(SListNode** pHead, SLDataType data)//尾插
{
	assert(pHead);
	SListNode *ptur = *pHead;
	SListNode *pNewNode = buyslistnode(data);
	//里面一个元素都没有
	if (*pHead == NULL)
	{
		*pHead = pNewNode;
		return;
	}
	//里面有其他元素
	while (ptur->_pNext)
	{
		ptur = ptur->_pNext;
	}
	ptur->_pNext = pNewNode;			
}
void SListPopBack(SListNode** pHead)//尾删
{
	SListNode *ptur = *pHead;
	if (*pHead == NULL)//没元素
	{
		return;
	}
		
	else if(ptur->_pNext==NULL)//有一个元素
	{
		free(ptur);
		*pHead = NULL;
	}
	else//有两个以上元素
	{
		while (ptur->_pNext->_pNext)
			ptur = ptur->_pNext;
		free(ptur->_pNext);
		ptur->_pNext = NULL;
	}	  
}
void SListPushFront(SListNode** pHead, SLDataType data)//头插
{
	assert(pHead);
	SListNode *pur = *pHead;
	SListNode *pNewNode = buyslistnode(data);
	if (*pHead == NULL)//里面一个都没有
		*pHead = pNewNode;
	else//里面至少有一个
	{
		pNewNode->_pNext = pur;
		*pHead = pNewNode;
	}
}
void SListPopFront(SListNode** pHead)//头删
{
	SListNode* pur = *pHead;
	assert(pHead);
	if (*pHead == NULL)//里面没元素
		return;
	else//里面有元素
	{
		pur = pur->_pNext;
		free(*pHead);
		*pHead = pur;
	}
}
void SListInsert(SListNode* pos, SLDataType data)//任意位置插
{
	if (pos == NULL)
	{
		return;
	}
	SListNode *pNewNode =buyslistnode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
void SListErase(SListNode** pHead, SListNode* pos)//任意位置删
{
	SListNode*pur = *pHead;
	SListNode*ppos = pos;
	assert(pHead);
	if (*pHead == NULL)
		return;
	if (pos==*pHead)//如果删的是第一个位置
	{
		SListPopFront(pHead);
	}
	else if(pos->_pNext == NULL)//如果删的是最后一个位置
	{
		SListPopBack(pHead);
	}
	else//删其他位置
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

SListNode* SListFind(SListNode* Head, SLDataType data)//某数值在哪个位置
{
	if (Head == NULL)
	{
		return NULL;
	}
	SListNode *pur = Head;
	while (pur->_data !=data||pur==NULL)//找到或者找完都往出走
	{
		pur = pur->_pNext;
	}
	if (pur == NULL)
	{
		printf("没有这个位置\n");
		exit(1);
	}
	else
		return pur;		
}

void SListDestroy(SListNode** pHead)//销毁这个链表
{
	SListNode*pur = *pHead;
	while (pur != NULL)
	{
		pur = pur->_pNext;
		free(*pHead);
		*pHead = pur;//最后pHead已经是NULL了
	}
}
SLDataType Front(SListNode* pHead)//输出首元素
{
	return pHead->_data;//这也太....
}
SLDataType Back(SListNode* pHead)//输出最后一个元素
{
	SListNode *pur = pHead;
	while (pur->_pNext!= NULL)
	{
		pur = pur->_pNext;
	}
	return pur->_data;
}
void SListRemoveAll(SListNode** pHead, SLDataType data)//删除所有值为data的结点 1.里面没有data 2.没这个链表
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
				*pHead = pur->_pNext;//头删
				free(pur);
				pur = *pHead;
			}
			else//删其他位置
			{
				qpur->_pNext = pur->_pNext;
				free(pur);
				pur = qpur->_pNext;
			}		
		}
		else//这里才是关键 这个题目关键在于每次进去qpur 要保持在pur前面
		{
			qpur = pur;//pur更新前保存至qpur 这个很关键
			pur = qpur->_pNext;
		}
		
	}
}
void SlistBubbleSort(SListNode* pHead)//冒泡排序链表
{
	assert(pHead);
	if (pHead == NULL)
	{
		return;
	}
	SListNode *pur = pHead;//开始冒泡排序这个链表
	SListNode *cur = pHead;
	int count = 0;
	while (pur->_pNext!= NULL)//看最后一次进来 的是哪个结点（倒数第二个）
	{
		cur = pur;
		while (cur->_pNext != NULL)
		{
			if ((cur->_data )>(cur->_pNext->_data))//从小到大排序
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

//void SListRemoveAll(SListNode* pHead, SLDataType data)//删除所有值为data的结点
//{
	//assert(pHead);
	//SListNode *pur = pHead;
	
	
//}

void TestList3()//测试任意位置插和删
{
	SListNode *Head;
	SListInit(&Head);//初始化
	SListPushBack(&Head, 2);//尾插
	SListPushBack(&Head, 2);//尾插
	SListPushBack(&Head, 8);//尾插
	SListPushBack(&Head, 2);//尾插
	SListPushBack(&Head, 5);//尾插
	SListPushBack(&Head, 2);//尾插
	//SListInsert(SListFind(Head, 3), 10);//在3后面插10
	//my_printf(Head);
	//printf("\n");
	//SListErase(&Head, SListFind(Head, 3));//删除3位置的数
	//my_printf(Head);
	//printf("\n");
	//SListRemove(&Head, 6);
	//SlistBubbleSort(Head);
	//SListDestroy(&Head);
	SListRemoveAll(&Head, 2);
	my_printf(Head);
}

void TestList2()//测试头插头删
{
	SListNode *Head;
	SListInit(&Head);//初始化
	SListPushFront(&Head, 1);
	SListPushFront(&Head, 2);
	SListPopFront(&Head);

	my_printf(Head);
}
void TestList1()//测试尾插尾删
{
	SListNode *Head;
	SListInit(&Head);//初始化
	SListPushBack(&Head, 1);//尾插
	SListPushBack(&Head, 2);//尾插
	SListPushBack(&Head, 3);//尾插
	SListPushBack(&Head, 4);//尾插
	SListPushBack(&Head, 5);//尾插
	SListPushBack(&Head, 6);//尾插
	
	SListPopBack(&Head);//尾删
	my_printf(Head);
}