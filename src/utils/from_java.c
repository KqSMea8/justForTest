/*************************************************************************
 * File:	from_java.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	Thu 14 Mar 2019 10:48:47 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>

#include "from_java.h"

//从java搬过来的计算hashCode的方法
int64_t hash_code(const void *data,int len){
	int64_t hash;
	const char *d = (char*)data;
	int off = 0;
	int i;
	for(i=0;i<len;i++){
		 hash = 31 * hash + (int)d[off++]; 	
	}
	return hash;
}
