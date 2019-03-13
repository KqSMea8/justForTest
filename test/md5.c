/*************************************************************************
 * File:	test.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	Thu 11 Oct 2018 07:48:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#include "../src/utils/md5.h"
#include "../src/utils/color.h"

int main() {
    char *str = "wendao-liuyongshuai";
    char out[32] = {0};
    MD5Str(str, strlen(str), out, 32);
    printf("%s\t%s\n", str, out);
    bzero(out, 32);
    MD5FileStr("/Users/liuyongshuai/mycode/github/selftest/selftest.cbp", out, 32);
    printf("%s\n", out);
	printlnGreen(out);
	printlnRed(out);
	printlnYellow(out);
	printlnBlue(out);
	printlnLightRed(out);
	printlnPurple(out);
    return 0;
}
