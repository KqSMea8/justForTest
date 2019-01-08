/*************************************************************************
 * File:	file.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2018年04月21日 星期六 14时18分50秒
 ************************************************************************/

#ifndef _UTILS_FILE_H_
#define _UTILS_FILE_H_

#define BUF_SIZE 102400

/**
 * 遍历文件的第一行，并传给回调函数
 */
int iter_file(const char *file, void (*fn)(char *line));

/**
 * 暂存目录文件的结构体
 */
typedef struct _DirFileItem {
    char *fname;
    struct _DirFileItem *next;
} DirFileItem;
typedef struct _DirFileList {
    DirFileItem *first;
    DirFileItem *last;
    int num;
} DirFileList;

/**
 * 递归读取目录下的所有文件
 */
int read_dir_files(const char *dir, DirFileList **flist);

/**
 * 打印目录下的所有文件
 */
void print_dir_files(DirFileList *flist);

/**
 * 释放存目录文件的结构体
 */
void free_dir_files(DirFileList *flist);

#endif
