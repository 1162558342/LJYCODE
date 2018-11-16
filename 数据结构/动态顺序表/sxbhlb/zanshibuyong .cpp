void seqlistinit(pseqlist ps, int capacity)//����˳���
{
	assert(ps);
	ps->pdata = (datatype*)malloc(sizeof(datatype));
	if (ps->pdata != NULL)
	{

	}
	ps->capacity = capacity;
	ps->size = 0;

}
void seqlistpushback(pseqlist ps, datatype data)//β��
{
	//�������checkcapacity()
	ps->pdata[ps->size++] = data;
}
void seqlistpopback(pseqlist ps)//βɾ
{
	assert(ps);
	if (ps->size)
		ps->size--;
}
/////////////////////////////////
void printseqlist(pseqlist ps)//���˳���
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->pdata[i]);
	}
	printf("\n");
}

void seqlistpushfront(pseqlist ps, datatype data)//ͷ��
{
	assert(ps);
	//checkcapacity(ps);
	//ͳһ������һ��λ��:�Ӻ���ǰ�� ����ͼ
	for (int i = ps->size; i > 0i--)
		ps->pdata[i] = ps->pdata[i - 1];
	ps->pdata[0] = data;//charuyuansu
	ps->size++;
}
void seqlistpopbfront(pseqlist ps)//ͷɾ
{
	assert(ps);
	if (0 == ps->size)
		return;
	//��˳����е���ЧԪ����ǰ����һ��λ�ã���ǰ�������
	for (int i = 0; i < ps->size - 1; i++)//ע��i��ȡֵ
		ps->pdata[i] = ps->pdata[i + 1];
	ps->size--;
}
void seqlistinsert(pseqlist ps, int pos, datatype data)//posλ�ò壺pos>=0&&pos<=size
{
	assert(ps);
	if (pos<0 || pos>ps->size)//���ж�
	{
		printf("����λ������\n");
		return;
	}
	//checkcapacity��ps��;//����������
	//���룺1��pos���ڿ�ʼ�Ժ�Ԫ������������
	for (int i = ps->size - 1; i >= pos; i--)
		ps->pdata[i + 1] = ps->pdata[i];
	ps->pdata[pos] = data;
	ps->size++;
}
void seqlisterase(pseqlist ps, int pos)//r����λ��ɾ
{
	assert(ps);
	if (pos < 0 || pos >= ps->size)
	{
		printf("ɾ��λ������\n");
		return;
	}
	for (int i = pos + 1; i < ps->size; ++i)
		ps->pdata[i - 1] = ps->pdata[i];
	ps->size--;
}
int seqlistfind(pseqlist ps, datatype data)//˳�������dataԪ�ص�һ�γ��ֵ�λ��
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->pdata[i] == data)
			return i;
	}
	return -1;
}
void seqlistremove(pseqlist ps, datatype data)//ɾ��˳�����ֵΪdata�ĵ�һ��Ԫ��
{
	int pos = seqlistfind(ps, data);
	seqlisterase(ps, pos);
}
void seqlistdestroy(pseqlist ps)//����˳�����Ϊ�ڶ��ϴ�����
{
	assert(ps);
	if (pa->pdata)
	{
		free(ps->pdata);
		ps->capacity =0 ;
		ps->size = 0;
	}
}
void checkcapacity(pseqlist ps)//���ݣ�������capacity ��size��ͬһ��λ�� ��ʱ�����Ҫ����
{
	assert(ps);
	if (ps->size == ps->capacity)//�Ƿ���Ҫ����
	{
		int newcapacity = ps->capacity * 2;
		datatype*pnew = (datatype*)malloc(sizeof(datatype)*);//�����¿ռ�
		if (NULL == pnew)
		{
			printf("�ڴ�ռ䲻��");
			exit(1);
		}
		memcpy(pnew, ps->pdata, sizeof(datatype)*);
		free(ps->pdata);//�ͷžɿռ�
		ps->pdata = pnew;//�·���ps->pdata =realloc(ps->pdata,ps->capacity);
		//if(ps->pdata==NULL)
		//{
		//
		//}
		ps->capacity = newcapacity;
	}
}
void seqlistremoveall(pseqlist ps, datatype data)//ɾ��˳���������ֵΪdata��Ԫ��
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
	//����find��remove
	seqlistinit(&s, 10);//����˳���
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
	seqlistinit(&s, 10);//����˳���
	seqlistpushbakc(&s, 1);
	seqlistpushbakc(&s, 2);
	seqlistpushbakc(&s, 3);
	seqlistpushbakc(&s, 4);
	seqlistpushbakc(&s, 5);
	printseqlist(&s);
	//��������λ�ò�ɾ
	seqlistinsert(&s, 3, 7);
}
void testseqlist1()
{
	seqlist s;
	seqlistinit(&s, 10);//����˳���
	seqlistpushbakc(&s, 1);
	seqlistpushbakc(&s, 2);
	seqlistpushbakc(&s, 3);
	seqlistpushbakc(&s, 4);
	seqlistpushbakc(&s, 5);
	printseqlist(s);

	//ͷ�� 0
	seqlistpushfront(&s, 0);
	//ͷɾ
	seqlistpopfront(&s);
}
//