/*************************************************************************
 * File:	rune.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019-03-18 16:24
 ************************************************************************/
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include "../src/utils/rune_width.h"

void main() {
    char *str = "C/C++语言提供了几个标准库函数，可以将字符串转换为任意类型(整型、长整型、浮点型等)。";
    int32_t buf[100] = {0};
    int32_t runeNum;
    convRunes(str, strlen(str), buf, &runeNum, 100);
    int i = 0;
    printf("\n");
    for (; i < 100; i++) {
        printf("%d\t", buf[i]);
    }
    printf("\n");
    char *str1 = "语";
    printf("-------%lu-----\n", strlen(str1));
    for(i=0;i<strlen(str1);i++){
        printf("%d\n",*(str1+i));
    }
}