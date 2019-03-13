/*************************************************************************
 * File:	color.c
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019年03月13日 星期三 16时51分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#include "color.h"

void Green(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_GREEN,0,blink,underline,output);
}

void LightGreen(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_LIGHTGREEN,1,blink,underline,output);
}

void Cyan(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_CYAN,0,blink,underline,output);
}

void LightCyan(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_LIGHTCYAN,1,blink,underline,output);
}

void Red(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_RED,0,blink,underline,output);
}

void LightRed(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_LIGHTRED,1,blink,underline,output);
}

void Yellow(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_YELLOW,0,blink,underline,output);
}

void Black(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_BLACK,0,blink,underline,output);
}

void DarkGray(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_DARKGRAY,1,blink,underline,output);
}

void LightGray(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_LIGHTGRAY,0,blink,underline,output);
}

void White(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_WHITE,1,blink,underline,output);
}

void Blue(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_BLUE,0,blink,underline,output);
}

void LightBlue(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_LIGHTBLUE,1,blink,underline,output);
}

void Purple(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_PURPLE,0,blink,underline,output);
}

void LightPurple(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_LIGHTPURPLE,1,blink,underline,output);
}

void Brown(const char * const originStr, int blink, int underline, char *output){
	cliColorRender(originStr,COLOR_BROWN,0,blink,underline,output);
}


void printlnGreen(const char * const originStr){
	printlnColor(originStr,Green);
}
void printlnLightGreen(const char * const originStr){
	printlnColor(originStr,LightGreen);
}
void printlnCyan(const char * const originStr){
	printlnColor(originStr,Cyan);
}
void printlnLightCyan(const char * const originStr){
	printlnColor(originStr,LightCyan);
}
void printlnRed(const char * const originStr){
	printlnColor(originStr,Red);
}
void printlnLightRed(const char * const originStr){
	printlnColor(originStr,LightRed);
}
void printlnYellow(const char * const originStr){
	printlnColor(originStr,Yellow);
}
void printlnBlack(const char * const originStr){
	printlnColor(originStr,Black);
}
void printlnDarkGray(const char * const originStr){
	printlnColor(originStr,DarkGray);
}
void printlnLightGray(const char * const originStr){
	printlnColor(originStr,LightGray);
}
void printlnWhite(const char * const originStr){
	printlnColor(originStr,White);
}
void printlnBlue(const char * const originStr){
	printlnColor(originStr,Blue);
}
void printlnLightBlue(const char * const originStr){
	printlnColor(originStr,LightBlue);
}
void printlnPurple(const char * const originStr){
	printlnColor(originStr,Purple);
}
void printlnLightPurple(const char * const originStr){
	printlnColor(originStr,LightPurple);
}
void printlnBrown(const char * const originStr){
	printlnColor(originStr,Brown);
}

void printlnColor(const char * const originStr,void(*fn)(const char * const , int , int , char *)){
	if(strlen(originStr)<COLOR_BUF_SIZE_LIMIT-32){
		char tmpBuf[COLOR_BUF_SIZE_LIMIT] = {0};
		fn(originStr,0,0,tmpBuf);
		printf("%s\n",tmpBuf);
		return;
	}
	int s = (strlen(originStr)+32)*sizeof(char);
	char *tmpBuf = (char*)malloc(s);
	bzero(tmpBuf,s);
	fn(originStr,0,0,tmpBuf);
	printf("%s\n",tmpBuf);
	free(tmpBuf);
	return;
}

//渲染颜色
void cliColorRender(const char * const originStr, int color, int weight, int blink, int underline, char *output){
	char modifier[512] = {0};
	if(blink > 0){
		strcat(modifier,"05;");
	}
	if(underline>0){
		strcat(modifier,"04;");
	}
	if(weight>0){
		char tmpWeight[8] = {0};
		sprintf(tmpWeight,"%d;",weight);
		strcat(modifier,tmpWeight);
	}
	if(strlen(modifier)<=0){
		strcat(modifier,"0;");
	}
	char tmpColor[8]={0};
	sprintf(tmpColor,"%d",color);
	sprintf(output,"\033[%s%sm%s\033[0m",modifier,tmpColor,originStr);
}
