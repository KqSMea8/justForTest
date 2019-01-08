#ifndef _UTILS_LINK_LIST_H_
#define _UTILS_LINK_LIST_H_

#include<stdio.h>

//单向链表节点
typedef struct _linkListNode {
    void *data;
    struct _linkListNode *next;
} LinkListNode;

//单向链表头结构体 
typedef struct _linkList {
    LinkListNode *first;
    LinkListNode *last;
    int total;
} LinkList;

//创建链表  
LinkList *linkListCreate();

//释放链表  
void linkListFree(LinkList *list);

//在尾部插入数据
void linkListAppend(LinkList *const list, void *const data, unsigned int data_len);

//插入在首部  
void linkListPrepend(LinkList *const list, void *const data, unsigned int data_len);

//插入  
void linkListInsertAt(LinkList *const list, void *const data, unsigned int data_len, int index);

//删除在尾部  
void linkListRemoveTail(LinkList *const list);

//删除在首部  
void linkListRemoveHeader(LinkList *const list);

//删除  
void linkListRemoveAt(LinkList *const list, int index);

//删除对象,返回是否删除成功  
int linkListRemoveData(LinkList *const list, void *data, int (*equal)(void *a, void *n));

//长度  
int linkListLength(const LinkList *const list);

//打印  
void linkListIterator(const LinkList *const list, void(*pt)(const void *const data, int index));

//取得数据  
void *linkListGetAt(const LinkList *const list, int index);

//取得第一个数据  
void *linkListGetHeader(const LinkList *const list);

//取得最后一个数据  
void *linkListGetTail(const LinkList *const list);

//查找某个数据的位置,如果equal方法为空，比较地址，否则调用equal方法  
//如果不存在返回-1，如果存在，返回出现的第一个位置  
int linkListFind(const LinkList *const list, void *data, int (*cmp_fn)(void *a, void *b));

//去重
int linkListUnique(LinkList *list, int (*cmp_fn)(void *a, void *b));

//合并有序的链表并且去重
void lineListMergeSortedAndUnuque(LinkList *list, ...);

//给链表插入排序
void linkListInsertSort(LinkList *list, int (*cmp)(void *a, void *n));

//选择排序
void linkListSelectSort(LinkList *list, int (*cmp)(void *a, void *n));

//冒泡排序
void linkListBubbleSort(LinkList *list, int (*cmp)(void *a, void *n));

#endif
