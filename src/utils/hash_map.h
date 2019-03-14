/*************************************************************************
 * 自定义的hashmap，自自己实现，定义仿照了：https://blog.csdn.net/swwlqw/article/details/22666705
 * File:	hashmap.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	六  4/28 19:26:17 2018
 ************************************************************************/
#ifndef _UTILS_HASHMAP_H_
#define _UTILS_HASHMAP_H_

#include<stdint.h>
#include "rbtree.h"

//kv对
typedef struct _hash_map_entry{
	void *key;
	void *data;
}HashMapEntry;

//node
typedef struct _hash_map_node {
    struct rb_node rb_node; 
    uint64_t hash_key; 
    HashMapEntry *data;
}HashMapNode;


typedef struct _hash_map_root{
	struct rb_root rbroot;
	int len;
}HashMapRoot;

HashMapRoot *hmap_init();

int hmap_insert(HashMapRoot *root, const void *key,int key_len,const void *data,int data_len);

int hmap_len(const HashMapRoot *root);

HashMapNode * hmap_search(HashMapRoot *root, const void *key, int key_len);

int hmap_delete(HashMapRoot *root, const void *key, int key_len);

void hmap_iterate(const HashMapRoot *root,void (*fn)(const HashMapNode* node));


#endif
