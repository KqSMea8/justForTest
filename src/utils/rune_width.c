/*************************************************************************
 * File:	rune_width.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019年03月13日 星期三 20时50分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#include "rune_width.h"

//计算字符长度
void convRunes(const char *utf8_str, int32_t str_len, int32_t *runes, int32_t *rune_len) {
    int i = 0, j = 0;
    char buf[4] = {0};
    char *tmp;
    do {
        bzero(buf, 4);
        tmp = utf8_str + i;
        char c = *tmp;
        if (c <= 127) {//单字节编码形式
            strncpy(buf, tmp, 1);
            i++;
        }
        else if (c <= 0b11011111) {//双字节编码形式
            strncpy(buf, tmp, 2);
            i += 2;
        }
        else if (c <= 0b11101111) {//三字节编码形式
            strncpy(buf, tmp, 3);
            i += 3;
        }
        else if (c <= 0b11110111) {//四字节编码形式
            strncpy(buf, tmp, 4);
            i += 4;
        }
        int32_t ci = atoi(buf);
        *(runes + j) = ci;
        j++;
        if (j >= rune_len) {
            break;
        }
        if (i >= str_len) {
            break;
        }
    } while (1);
}