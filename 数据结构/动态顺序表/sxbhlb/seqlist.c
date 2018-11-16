#include"seqlist.h"

void SeqListPushBack(PSeqList ps, DataType data)//尾插
{
	assert(ps);
	CheckCapacity(ps);
	ps->_pData[ps->_size] = data;//在size的位置插
	ps->_size++;
}
void SeqListPopBack(PSeqList ps)//尾删
{
	assert(ps);
	ps->_size--;
}

void SeqListPushFront(PSeqList ps, DataType data)//头插
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size; i > 0; i--)//先把第二个往后都后挪一位
	{
		ps->_pData[i - 1] = ps->_pData[i];
	}
	ps->_pData[0] = data;//给第一个赋值
	ps->_size++;
	return;
}

void SeqListPopFront(PSeqList ps)//头删
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType data)//任意位置插
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
void SeqListErase(PSeqList ps, int pos)//任意位置删
{
	assert(ps);
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_pData[i] = ps->_pData[i + 1];
	}
	ps->_size--;
	return;
}
int SeqListFind(PSeqList ps, DataType data)//查找data元素第一次出现的位置
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_pData[i] == data)
			return i;
	}
	return -1;
}
void CheckCapacity(PSeqList ps)//检测容量，不够了开辟
{
	if (ps->_capacity = ps->_size)//判断是否需要增容
	{
		int newcapacity = ps->_capacity* 2;
		DataType*pnew = (DataType*)malloc(sizeof(DataType)*newcapacity);
		if (pnew == NULL)
		{
			printf("内存空间不足\n");
			exit(1);//退出程序
		}
		memcpy(pnew, ps->_pData, sizeof(DataType)*newcapacity);//这里的ps->_pData还是首地址
		free(ps->_pData);//释放旧空间
		ps->_pData = pnew;
		ps->_capacity = newcapacity;
		return;
	}
}

void SeqListRemoveAll(PSeqList ps, DataType data)//删除所有值为data的元素
{
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_pData[i] == data)//有data就删除i位置的值一次
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
void BubbleSort(PSeqList ps)//冒泡排序顺序表中元素,加入从小到大排
{
	assert(ps);
	for (int j = ps->_size; j > 1; j--)//冒泡外部
	{
		int i = 0;
		for (i = 0; i < j; i++)//冒泡内部
		{
			if (ps->_pData[i]>ps->_pData[i + 1])//从小到大排序
			{
				ps->_pData[i] = (ps->_pData[i]) ^ (ps->_pData[i + 1]);
				ps->_pData[i + 1] = (ps->_pData[i]) ^ (ps->_pData[i + 1]);
				ps->_pData[i] = (ps->_pData[i]) ^ (ps->_pData[i + 1]);
			}
		}
	}
	return;
}
void SeqListInit(PSeqList ps, int capacity)//创建并初始化线性表
{
	assert(ps);
	ps->_pData = (DataType *)calloc(sizeof(DataType)*capacity,0);//创建空间用整形指针指着
	if (ps->_pData != NULL)
	{
		ps->_size = 0;
		ps->_capacity = capacity;
	}
	else
	{
		printf("创建失败\n");
		exit(-1);
	}
	return;
}
void seqlist()
{
	meau();
	int pos = 3;
	SeqList s;//结构体变量有了 结构体成员中sz和capacity都在栈上开辟空间 整形指针_pDate 所指向的空间在堆上 
	SeqListInit(&s, 10);//即相当于在这个存数据的线性表在堆上 但是通过栈上的变量sz和capacity来控制它
	SeqListPushBack(&s, 1);//尾插
	SeqListPopBack(&s);//尾删
	SeqListPushFront(&s, 1);//头插
	SeqListPopFront(&s);//头删
	SeqListInsert(&s, pos, 3);//任意位置插
	SeqListErase(&s, pos);//任意位置删
	int num= SeqListFind(&s, 3);//找data返回的位置
	SeqListRemoveAll(&s, 3);//将值为3的都删除了
	BubbleSort(&s);//冒泡排序顺序表
}