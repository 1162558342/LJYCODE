#pragma once
#include<stdio.h>
#include<windows.h>
typedef int SLDataType;
typedef struct SListNode//链表结点
{
	struct SListNode* _pNext;
	SLDataType _data;
}SListNode;


////////////////////////////////////////////// 
// 不带头节点的单链表 
void SListInit(SListNode** pHead);//初始化
void SListPushBack(SListNode** pHead, SLDataType data);//尾插
void SListPopBack(SListNode** pHead);//尾删
void SListPushFront(SListNode** pHead, SLDataType data);//头插
void SListPopFront(SListNode** pHead);//头删
SListNode* SListFind(SListNode* pHead, SLDataType data);//某数值在哪个位置
void SListInsert(SListNode* pos, SLDataType data);//任意位置插
void SListErase(SListNode** pHead, SListNode* pos);//任意位置删
void SListDestroy(SListNode** pHead);//销毁这个链表
int SListSize(SListNode* pHead);//这个链表占用几个字节？？
int SListEmpty(SListNode* pHead);//这个链表里有几个结点？？
SLDataType Front(SListNode* pHead);
SLDataType Back(SListNode* pHead);
void SListRemove(SListNode* pHead, SLDataType data);//删除第一个值为data的结点
void SListRemoveAll(SListNode** pHead, SLDataType data);//删除所有值为data的结点
void SlistBubbleSort(SListNode* pHead);//冒泡排序
void TestList3();
void TestList();