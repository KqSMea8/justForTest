/*************************************************************************
 * File:	rune_width.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019年03月13日 星期三 20时46分31秒
 ************************************************************************/

#ifndef _UTILS_RUNE_WIDTH_H_
#define _UTILS_RUNE_WIDTH_H_

#define TABLE_LEN(a) ( (sizeof(a)) / (sizeof(a[0])) )

//utf8编码第一个字节的最大值
#define CHAR1_UTF8_MAX 127
#define CHAR2_UTF8_MAX -33
#define CHAR3_UTF8_MAX -17
#define CHAR4_UTF8_MAX -9

#include<stdint.h>
#include<stdarg.h>

typedef struct _runeInterval {
    int32_t first;
    int32_t last;
} runeInterval;


//转换成runes
void convRunes(const char *utf8_str, int32_t str_len, int32_t *runes, int32_t *rune_len, int32_t run_limit);
int isRuneInTable(int32_t rune, runeInterval *table, size_t tableLen);
int isRuneInTables(int32_t rune, ...);
int isEastAsianLocale();

#endif