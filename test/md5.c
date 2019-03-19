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
#include "../src/utils/str.h"

int main() {
    int i, j;
    char *str = "wendao-liuyongshuai";
    unsigned long long hash = XXH64(str, strlen(str), 0);
    printf("%llu\n", hash);
    uint64_t jhash = hash_code(str, strlen(str));
    printf("%llu\n", jhash);
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

    char *lcType = getenv("LC_CTYPE");
    if (lcType == NULL) {
        lcType = getenv("LANG");
    }
    printf("lc_ctype||lang=%s\n", lcType);


    //正则匹配
    char *bematch = "hhhericchd@gmail.com";
    char *pattern = "h{3,10}(.*)@.{5}.(.*)";
    size_t outlen = 0;
    char **regbuf = find_string_sub_match(pattern, bematch, 10, &outlen);
    for (i = 0; i < outlen; i++) {
        printf("%s\n", regbuf[i]);
    }
    /*
    char *regStr = "http://scmpf.intra.xiaojukeji.com/index.php/home/index/all/104859";
    char *regpattern = "http:\\/\\/scmpf\\.intra\\.(.+?)\\.com(.*)";
    char **regbuf0 = find_string_sub_match(regpattern, regStr, 10, &outlen);
    for (i = 0; i < outlen; i++) {
        printf("%s\n", regbuf0[i]);
    }
     */
    char *regpattern1 = "^[a-z][a-z][a-z]?(?:_[A-Z][A-Z])?\\.(.+)";
    char *regStr1 = "abc_WD.abc";
    char **regbuf1 = find_string_sub_match(regpattern1, regStr1, 10, &outlen);
    for (i = 0; i < outlen; i++) {
        printf("%s\n", regbuf1[i]);
    }
    return 0;
}
