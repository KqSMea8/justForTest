/*************************************************************************
 * 自定义的hashmap，自自己实现，定义仿照了：https://blog.csdn.net/swwlqw/article/details/22666705
 * File:	hashmap.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	六  4/28 19:26:17 2018
 ************************************************************************/
#ifndef _UTILS_HASHMAP_H_
#define _UTILS_HASHMAP_H_

#include "rbtree.h"

struct _hash_map_node {
    struct rb_node rb_node;    // 红黑树节点
    unsigned long long hash_key;                // 键值
    void *data;
}HashMapNode;


#endif
