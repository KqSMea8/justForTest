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
#include "../src/utils/rune_width.h"
#include "../src/utils/xxhash.h"
#include "../src/utils/from_java.h"

int main() {
    char *str = "wendao-liuyongshuai";
	unsigned long long hash = XXH64(str,strlen(str),0);
	printf("%lld\n",hash);
	int64_t jhash = hash_code(str,strlen(str));
	printf("%ld\n",jhash);
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

	char *lcType=getenv("LC_CTYPE");
	if(lcType==NULL){
		lcType=getenv("LANG");
	}
	printf("lc_ctype||lang=%s\n",lcType);
    return 0;
}
