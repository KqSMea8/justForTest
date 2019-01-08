/*************************************************************************
 * File:	base64.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2018年04月22日 星期日 20时28分41秒
 *************************************************************************/

#ifndef _UTILS_BASE64_H_
#define _UTILS_BASE64_H_
int base64_decode(char *out,int outlen, const char *in, int inlen);
int base64_encode(char *out, int outlen,const char *in, int inlen);
#endif
