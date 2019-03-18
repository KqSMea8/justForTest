/*************************************************************************
 * File:	str.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019-03-18 19:09
 ************************************************************************/
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<regex.h>
#include "str.h"

void str_tolower(char *str, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        *(str + i) = tolower(*(str + i));
    }
    return;
}

void str_toupper(char *str, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        *(str + i) = toupper(*(str + i));
    }
    return;
}

//成功返回0，否则返回-1
int has_suffix(const char *str, size_t str_len, const char *suffix, size_t suffix_len) {
    if (suffix_len > str_len) {
        return -1;
    }
    if (strncmp(str, suffix, suffix_len) == 0) {
        return 0;
    }
    return -1;
}

//正则匹配查找子串
int find_string_sub_match(const char *pattern, const char *str, char **output, size_t subsize, size_t *outlen) {
    regex_t reg;
    int errno;
    char errbuf[1024];
    if (regcomp(&reg, pattern, REG_EXTENDED) < 0) {
        regerror(errno, &reg, errbuf, sizeof(errbuf));
        printf("err:%s\n", errbuf);
        return -1;
    }

    regmatch_t pmatch[subsize];
    errno = regexec(&reg, str, subsize, pmatch, 0);
    if (errno == REG_NOMATCH) {
        printf("no match\n");
        return -1;
    }
    else if (errno) {
        regerror(errno, &reg, errbuf, sizeof(errbuf));
        printf("err:%s\n", errbuf);
        return -1;
    }

    int i;
    *outlen = 0;
    for (i = 0; i < subsize && pmatch[i].rm_so != -1; i++) {
        int len = pmatch[i].rm_eo - pmatch[i].rm_so;
        if (len <= 0) {
            continue;
        }
        memcpy(*output + *outlen, str + pmatch[i].rm_so, len);
        (*outlen)++;
    }
    return 0;
}