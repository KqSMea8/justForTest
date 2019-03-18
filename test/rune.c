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
    int32_t buf[50] = {0};
    convRunes(str, strlen(str), buf, 50);
    int i = 0;
    printf("\n");
    for (; i < 50; i++) {
        printf("%d\t", buf[i]);
    }
    printf("\n");
}