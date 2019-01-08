/*************************************************************************
 * File:	urlencode.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2018年04月22日 星期日 20时28分41秒
 ************************************************************************/

#ifndef _UTILS_URLENCODE_H_
#define _UTILS_URLENCODE_H_
int url_decode(char *buf,int buf_len,const char *str, int len);  
int url_encode(char *buf,int buf_len,char const *str, int len);  
#endif
