/*************************************************************************
 * File:	str.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019-03-18 19:08
 ************************************************************************/
#ifndef JUSTFORTEST_STR_H
#define JUSTFORTEST_STR_H

#include <stdint.h>
#include <stddef.h>

void str_tolower(char *str, size_t len);

void str_toupper(char *str, size_t len);

//成功返回0，否则返回-1
int has_suffix(const char *str, size_t str_len, const char *suffix, size_t suffix_len);

//正则匹配查找子串
char** find_string_sub_match(const char *pattern, const char *str, size_t subsize, size_t *outlen);

#endif //JUSTFORTEST_STR_H
