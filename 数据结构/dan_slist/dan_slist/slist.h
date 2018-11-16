#pragma once
#include<stdio.h>
#include<windows.h>
typedef int SLDataType;
typedef struct SListNode//������
{
	struct SListNode* _pNext;
	SLDataType _data;
}SListNode;


////////////////////////////////////////////// 
// ����ͷ�ڵ�ĵ����� 
void SListInit(SListNode** pHead);//��ʼ��
void SListPushBack(SListNode** pHead, SLDataType data);//β��
void SListPopBack(SListNode** pHead);//βɾ
void SListPushFront(SListNode** pHead, SLDataType data);//ͷ��
void SListPopFront(SListNode** pHead);//ͷɾ
SListNode* SListFind(SListNode* pHead, SLDataType data);//ĳ��ֵ���ĸ�λ��
void SListInsert(SListNode* pos, SLDataType data);//����λ�ò�
void SListErase(SListNode** pHead, SListNode* pos);//����λ��ɾ
void SListDestroy(SListNode** pHead);//�����������
int SListSize(SListNode* pHead);//�������ռ�ü����ֽڣ���
int SListEmpty(SListNode* pHead);//����������м�����㣿��
SLDataType Front(SListNode* pHead);
SLDataType Back(SListNode* pHead);
void SListRemove(SListNode* pHead, SLDataType data);//ɾ����һ��ֵΪdata�Ľ��
void SListRemoveAll(SListNode** pHead, SLDataType data);//ɾ������ֵΪdata�Ľ��
void SlistBubbleSort(SListNode* pHead);//ð������
void TestList3();
void TestList();