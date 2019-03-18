/*************************************************************************
 * File:	regexp.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019-03-18 20:01
 ************************************************************************/
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<regex.h>

int main() {

    char *bematch = "hhhericchd@gmail.com";
    char *pattern = "h{3,10}(.*)@.{5}.(.*)";
    char errbuf[1024];
    char match[100];
    regex_t reg;
    int err, nm = 10;
    regmatch_t pmatch[nm];

    if (regcomp(&reg, pattern, REG_EXTENDED) < 0) {
        regerror(err, &reg, errbuf, sizeof(errbuf));
        printf("err:%s\n", errbuf);
    }

    err = regexec(&reg, bematch, nm, pmatch, 0);

    if (err == REG_NOMATCH) {
        printf("no match\n");
        exit(-1);
    }
    else if (err) {
        regerror(err, &reg, errbuf, sizeof(errbuf));
        printf("err:%s\n", errbuf);
        exit(-1);
    }

    for (int i = 0; i < 10 && pmatch[i].rm_so != -1; i++) {
        int len = pmatch[i].rm_eo - pmatch[i].rm_so;
        if (len) {
            memset(match, '\0', sizeof(match));
            memcpy(match, bematch + pmatch[i].rm_so, len);
            printf("%s\n", match);
        }
    }
    return 0;
}