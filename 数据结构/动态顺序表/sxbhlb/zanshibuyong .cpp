void seqlistinit(pseqlist ps, int capacity)//创建顺序表
{
	assert(ps);
	ps->pdata = (datatype*)malloc(sizeof(datatype));
	if (ps->pdata != NULL)
	{

	}
	ps->capacity = capacity;
	ps->size = 0;

}
void seqlistpushback(pseqlist ps, datatype data)//尾插
{
	//检测容量checkcapacity()
	ps->pdata[ps->size++] = data;
}
void seqlistpopback(pseqlist ps)//尾删
{
	assert(ps);
	if (ps->size)
		ps->size--;
}
/////////////////////////////////
void printseqlist(pseqlist ps)//输出顺序表
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->pdata[i]);
	}
	printf("\n");
}

void seqlistpushfront(pseqlist ps, datatype data)//头插
{
	assert(ps);
	//checkcapacity(ps);
	//统一向后搬移一个位置:从后往前搬 看画图
	for (int i = ps->size; i > 0i--)
		ps->pdata[i] = ps->pdata[i - 1];
	ps->pdata[0] = data;//charuyuansu
	ps->size++;
}
void seqlistpopbfront(pseqlist ps)//头删
{
	assert(ps);
	if (0 == ps->size)
		return;
	//将顺序表中的有效元素向前搬移一个位置：从前往后搬移
	for (int i = 0; i < ps->size - 1; i++)//注意i的取值
		ps->pdata[i] = ps->pdata[i + 1];
	ps->size--;
}
void seqlistinsert(pseqlist ps, int pos, datatype data)//pos位置插：pos>=0&&pos<=size
{
	assert(ps);
	if (pos<0 || pos>ps->size)//先判断
	{
		printf("插入位置有误！\n");
		return;
	}
	//checkcapacity（ps）;//容量够不够
	//插入：1从pos在内开始以后元素整体向后搬移
	for (int i = ps->size - 1; i >= pos; i--)
		ps->pdata[i + 1] = ps->pdata[i];
	ps->pdata[pos] = data;
	ps->size++;
}
void seqlisterase(pseqlist ps, int pos)//r任意位置删
{
	assert(ps);
	if (pos < 0 || pos >= ps->size)
	{
		printf("删除位置有误！\n");
		return;
	}
	for (int i = pos + 1; i < ps->size; ++i)
		ps->pdata[i - 1] = ps->pdata[i];
	ps->size--;
}
int seqlistfind(pseqlist ps, datatype data)//顺序表中找data元素第一次出现的位置
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->pdata[i] == data)
			return i;
	}
	return -1;
}
void seqlistremove(pseqlist ps, datatype data)//删除顺序表中值为data的第一个元素
{
	int pos = seqlistfind(ps, data);
	seqlisterase(ps, pos);
}
void seqlistdestroy(pseqlist ps)//销毁顺序表：因为在堆上创建的
{
	assert(ps);
	if (pa->pdata)
	{
		free(ps->pdata);
		ps->capacity =0 ;
		ps->size = 0;
	}
}
void checkcapacity(pseqlist ps)//增容：存满后capacity 和size在同一个位置 这时候就需要括增
{
	assert(ps);
	if (ps->size == ps->capacity)//是否需要增容
	{
		int newcapacity = ps->capacity * 2;
		datatype*pnew = (datatype*)malloc(sizeof(datatype)*);//拷贝新空间
		if (NULL == pnew)
		{
			printf("内存空间不足");
			exit(1);
		}
		memcpy(pnew, ps->pdata, sizeof(datatype)*);
		free(ps->pdata);//释放旧空间
		ps->pdata = pnew;//新方法ps->pdata =realloc(ps->pdata,ps->capacity);
		//if(ps->pdata==NULL)
		//{
		//
		//}
		ps->capacity = newcapacity;
	}
}
void seqlistremoveall(pseqlist ps, datatype data)//删除顺序表中所有值为data的元素
{
	assert(ps);
	int i = 0;
	int pos = 0;
	while (i< ps->size)
	{
		for (i = pos; i < ps->size; ++i)
		{
			if (ps->pdata[i] == data)
			{
				pos = i;
				seqlisterase(ps, pos);
				break;
			}

		}
	}
	return -1;
}
void testseqlist2()
{

}
{
	//测试find和remove
	seqlistinit(&s, 10);//创建顺序表
	seqlistpushbakc(&s, 1);
	seqlistpushbakc(&s, 2);
	seqlistpushbakc(&s, 3);
	seqlistpushbakc(&s, 4);
	seqlistpushbakc(&s, 5);
	printseqlist(&s);
	seqlistremove(&s, 3);
	///...
	printseqlist(&s);
}
void testseqlist2()
{
	seqlist s;
	seqlistinit(&s, 10);//创建顺序表
	seqlistpushbakc(&s, 1);
	seqlistpushbakc(&s, 2);
	seqlistpushbakc(&s, 3);
	seqlistpushbakc(&s, 4);
	seqlistpushbakc(&s, 5);
	printseqlist(&s);
	//测试任意位置插删
	seqlistinsert(&s, 3, 7);
}
void testseqlist1()
{
	seqlist s;
	seqlistinit(&s, 10);//创建顺序表
	seqlistpushbakc(&s, 1);
	seqlistpushbakc(&s, 2);
	seqlistpushbakc(&s, 3);
	seqlistpushbakc(&s, 4);
	seqlistpushbakc(&s, 5);
	printseqlist(s);

	//头插 0
	seqlistpushfront(&s, 0);
	//头删
	seqlistpopfront(&s);
}
//