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
    for (; i < runeNum; i++) {
        printf("%s\t", (char *) &buf[i]);
    }
    printf("\n");
    extern runeInterval combiningTable[];
    extern size_t combiningTableLen;
    extern runeInterval privateTable[];
    extern size_t privateTableLen;
    extern runeInterval nonPrintTable[];
    extern size_t nonPrintTableLen;
    int a = isRuneInTable(0x0A3F, combiningTable, combiningTableLen);
    printf("a=%d\n", a);
    int b = isRuneInTables(0,
                           combiningTable, combiningTableLen,
                           privateTable, privateTableLen,
                           nonPrintTable, nonPrintTableLen);
    printf("b=%d\n", b);
}