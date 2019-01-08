#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include "link_list.h"

//创建链表
LinkList *linkListCreate() {
    int l = sizeof(LinkList);
    LinkList *ret = (LinkList *) malloc(l);
    if (ret == NULL) {
        perror("malloc for LinkList");
        return NULL;
    }
    ret->first = NULL;
    ret->last = NULL;
    ret->total = 0;
    return ret;
}

//释放链表
void linkListFree(LinkList *list) {
    if (list == NULL) {
        return;
    }
    LinkListNode *tmp = list->first;
    while (tmp != NULL) {
        list->first = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = list->first;
    }
    free(list);
}

//在尾部插入节点
void linkListAppend(LinkList *const list, void *const data, unsigned int data_len) {
    if (list == NULL) {
        return;
    }
    LinkListNode *node = (LinkListNode *) malloc(sizeof(LinkListNode));
    if (node == NULL) {
        perror("insert last node failed");
        return;
    }
    node->data = malloc(data_len);
    bzero(node->data, data_len);
    memcpy(node->data, data, data_len);
    node->next = NULL;
    if (list->total == 0) {
        list->first = node;
        list->last = node;
        list->total++;
        return;
    }
    list->last->next = node;
    list->last = node;
    list->total++;
    return;
}

//在首部插入节点
void linkListPrepend(LinkList *const list, void *const data, unsigned int data_len) {
    if (list == NULL) {
        return;
    }
    LinkListNode *node = (LinkListNode *) malloc(sizeof(LinkListNode));
    if (node == NULL) {
        perror("insert first failed");
        return;
    }
    node->data = malloc(data_len);
    bzero(node->data, data_len);
    memcpy(node->data, data, data_len);
    node->next = list->first;
    list->first = node;
    if (list->last == NULL) {
        list->last = node;
    }
    list->total++;
    return;
}

//在指定位置插入节点，不够数量时插在最后面
void linkListInsertAt(LinkList *const list, void *const data, unsigned int data_len, int index) {
    if (list == NULL) {
        return;
    }
    if (index <= 0) {
        linkListPrepend(list, data, data_len);
        return;
    }
    if (index >= list->total) {
        linkListAppend(list, data, data_len);
        return;
    }
    LinkListNode *tmp = list->first;
    LinkListNode *node = (LinkListNode *) malloc(sizeof(LinkListNode));
    node->data = malloc(data_len);
    bzero(node->data, data_len);
    memcpy(node->data, data, data_len);
    int i = 0;
    while (i < index && tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    node->next = tmp->next;
    tmp->next = node;
    list->total++;
    return;
}

//删除尾部的节点
void linkListRemoveTail(LinkList *const list) {
    if (list == NULL) {
        return;
    }
    if (list->total <= 0) {
        return;
    }
    LinkListNode *preLast = list->first;
    while (1) {
        if (preLast->next == NULL || preLast->next == list->last) {
            break;
        }
        preLast = preLast->next;
    }
    list->last = preLast;
    list->total--;
    if (list->total <= 0) {
        list->first = NULL;
        list->last = NULL;
    }
    free(preLast->next->data);
    free(preLast->next);
    preLast->next = NULL;
    return;
}

//删除首部节点
void linkListRemoveHeader(LinkList *const list) {
    if (list == NULL) {
        return;
    }
    if (list->total <= 0) {
        return;
    }
    LinkListNode *tmp = list->first;
    list->first = list->first->next;
    free(tmp->data);
    free(tmp);
    list->total--;
    if (list->total <= 0) {
        list->last = NULL;
        list->first = NULL;
    }
    return;
}

//删除指定位置上的节点
void linkListRemoveAt(LinkList *const list, int index) {
    if (list == NULL) {
        return;
    }
    if (index <= 0) {
        return linkListRemoveHeader(list);
    }
    if (index >= list->total) {
        return linkListRemoveTail(list);
    }
    LinkListNode *tmp = list->first;
    int i = 0;
    while (i < index && tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    LinkListNode *tnode = tmp->next;
    tmp->next = tmp->next->next;
    free(tnode->data);
    free(tnode);
    return;
}

//删除对象,返回是否删除成功
int linkListRemoveData(LinkList *const list, void *data, int (*equal)(void *a, void *b)) {
    if (list == NULL) {
        return -1;
    }
    if (list->total <= 0) {
        return -1;
    }
    LinkListNode *tmp = list->first;
    while (tmp != NULL) {
        if (tmp->next == NULL) {
            return -1;
        }
        if (equal != NULL) {
            if (equal(tmp->next->data, data) == 0) {
                break;
            }
        }
        else {
            if (tmp->next->data == data) {
                break;
            }
        }
        tmp = tmp->next;
    }
    if (tmp == NULL || tmp->next == NULL) {
        return -1;
    }
    LinkListNode *ret = tmp->next;
    tmp->next = tmp->next->next;
    free(ret->data);
    free(ret);
    list->total--;
    if (list->total <= 0) {
        list->last = NULL;
        list->first = NULL;
    }
    return 0;
}

//返回链表长度
int linkListLength(const LinkList *const list) {
    if (list == NULL) {
        return 0;
    }
    return list->total;
}

//打印链表信息
void linkListIterator(const LinkList *const list, void(*pt)(const void *const data, int index)) {
    if (list == NULL || pt == NULL) {
        return;
    }
    LinkListNode *tmp = list->first;
    int index = 0;
    while (tmp != NULL) {
        pt(tmp->data, index++);
        tmp = tmp->next;
    }
    return;
}

//取指定位置上的数据
void *linkListGetAt(const LinkList *const list, int index) {
    if (list == NULL || list->total <= 0) {
        return NULL;
    }
    LinkListNode *tmp = list->first;
    int i = 0;
    while (i < index && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    if (tmp == NULL) {
        return list->last->data;
    }
    return tmp->data;
}

//取得第一个数据
void *linkListGetHeader(const LinkList *const list) {
    if (list == NULL || list->total == 0) {
        return NULL;
    }
    return list->first->data;
}

//取得最后一个数据
void *linkListGetTail(const LinkList *const list) {
    if (list == NULL || list->total == 0) {
        return NULL;
    }
    return list->last->data;
}

//查询指定数据第一次出现的位置
int linkListFind(const LinkList *const list, void *data, int (*cmp_func)(void *a, void *b)) {
    if (list == NULL || list->total == 0) {
        return -1;
    }
    LinkListNode *tmp = list->first;
    int i = 0;
    while (tmp != NULL) {
        if (cmp_func(tmp->data, data) == 0) {
            return i;
        }
        tmp = tmp->next;
        i++;
    }
    return -1;
}

//去重
int linkListUnique(LinkList *list, int (*cmp_fn)(void *a, void *b)) {

}

//给链表插入排序
//https://blog.csdn.net/baidu_30000217/article/details/77823084
void linkListInsertSort(LinkList *list, int (*cmp)(void *a, void *n)) {

}

//合并有序的链表并且去重
void lineListMergeSortedAndUnuque(LinkList *list, ...) {

}

//选择排序
void linkListSelectSort(LinkList *list, int (*cmp)(void *a, void *n)) {

}

//冒泡排序
void linkListBubbleSort(LinkList *list, int (*cmp)(void *a, void *n)) {

}