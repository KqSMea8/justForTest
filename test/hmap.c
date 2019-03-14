/*************************************************************************
 * File:	hmap.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	Thu 14 Mar 2019 05:15:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#include "hash_map.h"

void print1(const HashMapNode* node){
	printf("%llu\t%s\t%s\n",node->hash_key,(char*)node->data->key,(char*)node->data->data);
}

int main(){
	char *key1 = "this is my first key";
	char *data1 = "ASDFASFDASDFADFAFDSADFASDFASFD";


	char *key2 = "this is my second key";
	char *data2 = "ASDFASFDASDFADFAi-------FDSADFASDFASFD";

	HashMapRoot *root = hmap_init();
	hmap_insert(root,key1,strlen(key1),data1,strlen(data1));
	hmap_insert(root,key2,strlen(key2),data2,strlen(data2));

	printf("map_len=%d\n",root->len);
	hmap_iterate(root,print1);
	hmap_delete(root,key1,strlen(key1));
	printf("map_len=%d\n",root->len);
	hmap_iterate(root,print1);
}
