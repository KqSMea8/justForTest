/*************************************************************************
 * File:	urlencode.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2018年04月22日 星期日 20时30分22秒
 ************************************************************************/

#include<string.h>
#include<ctype.h>
#include "urlencode.h"
static unsigned char hexchars[] = "0123456789ABCDEF";  
  
int url_encode(char *buf,int buf_len,const char *str, int len){
    unsigned char c;  
    unsigned char *dest_start,*dest_end;  
    unsigned char const *src_start, *src_end;  
      
    src_start = (unsigned char *)str;  
    src_end  = src_start + len;  
    dest_start = (unsigned char *)buf;  
    dest_end = dest_start + buf_len;
  
    while (src_start < src_end && dest_start < dest_end)   
    {  
        c = *src_start++;  
        if (c == ' ')   
        {  
            *dest_start++ = '+';  
        }   
        else if ((c < '0' && c != '-' && c != '.') || (c < 'A' && c > '9') || (c > 'Z' && c < 'a' && c != '_') || (c > 'z'))   
        {  
            dest_start[0] = '%';  
            dest_start[1] = hexchars[c >> 4];  
            dest_start[2] = hexchars[c & 15];  
            dest_start += 3;  
        }  
        else   
        {  
            *dest_start++ = c;  
        }  
    }  
    return 0;  
}
int url_decode(char *buf,int buf_len,char const *str, int len){
    int value;
    int c;

    while (len-- && buf_len--) {
        if (*str == '+') {
            *buf = ' ';
        }
        else if (*str == '%' && len >= 2 && isxdigit((int)*(str + 1)) && isxdigit((int)*(str + 2)))
        {
            c = ((unsigned char *)(str+1))[0];
            if(isupper(c)){
                c = tolower(c);
            }
            value = (c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10) * 16;
            c = ((unsigned char *)(str+1))[1];
            if (isupper(c)){
                c = tolower(c);
            }
            value += c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;
            *buf = (char)value ;
            str += 2;
            len -= 2;
        } else {
            *buf = *str;
        }
        str++;
        buf++;
    }
    *buf = '\0';
    return 0;
}
