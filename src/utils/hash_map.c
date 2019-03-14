/*************************************************************************
 * File:	hashmap.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	六  4/28 19:27:03 2018
 ************************************************************************/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "hash_map.h"
#include "xxhash.h"

//https://blog.csdn.net/swwlqw/article/details/22666705


//写入一条数据，成功返回0，失败返回-1
int hmap_insert(HashMapRoot *root, const HashMapData *data){
	if(data == NULL || root == NULL){
		return -1;
	}
	uint64_t hkey = XXH64(data->key,data->key_len,0); 
	struct rb_node *parent = NULL;
	struct rb_node **tmp = &(root->rb_node);
   while(*tmp){
         HashMapNode *tmpNode = container_of(*tmp, HashMapNode, rb_node);
         parent = *tmp;
         if (hkey < tmpNode->hash_key)
             tmp = &((*tmp)->rb_left);
         else if (hkey > tmpNode->hash_key)
             tmp = &((*tmp)->rb_right);
         else
             return -1;
     }

   //如果新建结点失败，则返回。
	HashMapNode *newNode=malloc(sizeof(HashMapNode));
	if(newNode == NULL){
		printf("malloc failed\n");
		return -1;
	}
    newNode->hash_key = hkey;
	newNode->data = data;
    rb_link_node(&newNode->rb_node, parent, tmp);
    rb_insert_color(&newNode->rb_node, root);
	return 0; 
}

HashMapNode * hmap_search(HashMapRoot *root, const void *key, int key_len){
	if(root == NULL || key == NULL || key_len <=0){
		return NULL;
	}
	uint64_t hkey = XXH64(key,key_len,0);  
    struct rb_node *rbnode = root->rb_node;
 
     while (rbnode!=NULL){
         HashMapNode *tnode = container_of(rbnode, HashMapNode, rb_node);
         if (hkey < tnode->hash_key)
             rbnode = rbnode->rb_left;
         else if (hkey > tnode->hash_key)
             rbnode = rbnode->rb_right;
         else
            return tnode;
     }
	return NULL;
}

int hmap_delete(HashMapRoot *root, const void *key, int key_len){
	if(root == NULL || key == NULL || key_len <=0){      
		return -1;
	}
    HashMapNode *tnode;
    if((tnode = hmap_search(root, key, key_len)) == NULL)
         return -1;
 
    rb_erase(&(tnode->rb_node), root);
	free(tnode->data->data);
	free(tnode->data->key);
	free(tnode->data);
	free(tnode);
	return 0;
}

static void rbtree_iterator(struct rb_node *tree, void (*fn)(const HashMapNode* node)){
	if(tree == NULL){
		return;
	}
	HashMapNode *my = container_of(tree, HashMapNode, rb_node);
	fn(my);
    if (tree->rb_left)
        rbtree_iterator(tree->rb_left,  fn);
    if(tree->rb_right)
        rbtree_iterator(tree->rb_right, fn); 
 }
 

void hmap_iterate(const HashMapRoot *root,void (*fn)(const HashMapNode* node)){
	if(root == NULL ){
		return;
	}
	rbtree_iterator(root->rb_node,fn);
}
