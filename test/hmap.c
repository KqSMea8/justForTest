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
	HashMapData d1;
	d1.key = key1;
	d1.key_len = strlen(key1);
	d1.data = data1;


	char *key2 = "this is my second key";
	char *data2 = "ASDFASFDASDFADFAi-------FDSADFASDFASFD";
	HashMapData d2;
	d2.key = key2;
	d2.key_len = strlen(key2);
	d2.data = data2;

	HashMapRoot root = RB_ROOT;
	hmap_insert(&root,&d1);
	hmap_insert(&root,&d2);

	hmap_iterate(&root,print1);
	hmap_delete(&root,key1,strlen(key1));
	hmap_iterate(&root,print1);
}
