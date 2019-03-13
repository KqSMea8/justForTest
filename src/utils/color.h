/*************************************************************************
 * File:	color.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019年03月13日 星期三 16时44分08秒
 ************************************************************************/

#ifndef _UTILS_COLOR_H_
#define _UTILS_COLOR_H_

#define COLOR_BUF_SIZE_LIMIT 1024

//绿色字体
#define COLOR_GREEN 32
//淡绿
#define COLOR_LIGHTGREEN 32
//青色/蓝绿色
#define COLOR_CYAN 36
//淡青色
#define COLOR_LIGHTCYAN 36
//红字体
#define COLOR_RED 31
//淡红色
#define COLOR_LIGHTRED 31
//黄色字体
#define COLOR_YELLOW 33
//黑色
#define COLOR_BLACK 30
//深灰色
#define COLOR_DARKGRAY 30
//浅灰色
#define COLOR_LIGHTGRAY 37
//白色
#define COLOR_WHITE 37
//蓝色
#define COLOR_BLUE 34
//淡蓝
#define COLOR_LIGHTBLUE 34
//紫色
#define COLOR_PURPLE 35
//淡紫色
#define COLOR_LIGHTPURPLE 35
//棕色
#define COLOR_BROWN 33


void Green(const char * const originStr, int blink, int underline, char *output);
void LightGreen(const char * const originStr, int blink, int underline, char *output);
void Cyan(const char * const originStr, int blink, int underline, char *output);
void LightCyan(const char * const originStr, int blink, int underline, char *output);
void Red(const char * const originStr, int blink, int underline, char *output);
void LightRed(const char * const originStr, int blink, int underline, char *output);
void Yellow(const char * const originStr, int blink, int underline, char *output);
void Black(const char * const originStr, int blink, int underline, char *output);
void DarkGray(const char * const originStr, int blink, int underline, char *output);
void LightGray(const char * const originStr, int blink, int underline, char *output);
void White(const char * const originStr, int blink, int underline, char *output);
void Blue(const char * const originStr, int blink, int underline, char *output);
void LightBlue(const char * const originStr, int blink, int underline, char *output);
void Purple(const char * const originStr, int blink, int underline, char *output);
void LightPurple(const char * const originStr, int blink, int underline, char *output);
void Brown(const char * const originStr, int blink, int underline, char *output);


void cliColorRender(const char * const originStr, int color, int weight, int blink, int underline, char *output);
void printlnColor(const char * const originStr,void(*fn)(const char * const,int,int,char *));


void printlnGreen(const char * const originStr);
void printlnLightGreen(const char * const originStr);
void printlnCyan(const char * const originStr);
void printlnLightCyan(const char * const originStr);
void printlnRed(const char * const originStr);
void printlnLightRed(const char * const originStr);
void printlnYellow(const char * const originStr);
void printlnBlack(const char * const originStr);
void printlnDarkGray(const char * const originStr);
void printlnLightGray(const char * const originStr);
void printlnWhite(const char * const originStr);
void printlnBlue(const char * const originStr);
void printlnLightBlue(const char * const originStr);
void printlnPurple(const char * const originStr);
void printlnLightPurple(const char * const originStr);
void printlnBrown(const char * const originStr);

#endif
