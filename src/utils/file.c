#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include "file.h"

/**
 * 遍历文件的每一行，用指定的函数去处理
 */
int iter_file(const char *file, void (*fn)(char *line)) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        perror(file);
        return -1;
    }
    char line[BUF_SIZE] = {0};
    while (!feof(fp)) {
        bzero(line, BUF_SIZE);
        if (fgets(line, BUF_SIZE, fp)) {
            fn(line);
        }
    }
    fclose(fp);
    return 0;
}

/**
 * 递归读取目录及子目录下的所有文件，不包括隐藏的文件或目录
 */
int read_dir_files(const char *dir, DirFileList **flist) {
    if (flist == NULL) {
        printf("invalid flist\n");
        return 0;
    }
    if ((*flist) == NULL) {
        (*flist) = (DirFileList *) malloc(sizeof(DirFileList));
        (*flist)->num = 0;
        (*flist)->first = NULL;
        (*flist)->last = NULL;
    }
    DIR *dp = opendir(dir);
    if (dp == NULL) {
        perror(dir);
        return -1;
    }
    struct dirent *d;
    while ((d = readdir(dp)) != NULL) {
        if (d->d_name[0] == '.') {
            continue;
        }
        if (d->d_type == DT_REG) {//普通文件
            char tmpf[1024] = {0};
            char tmpfname[256] = {0};
            strncpy(tmpfname, d->d_name, d->d_reclen);
            sprintf(tmpf, "%s/%s", dir, tmpfname);
            DirFileItem *dfi = (DirFileItem *) malloc(sizeof(DirFileItem));
            bzero(dfi, sizeof(DirFileItem));
            dfi->next = NULL;
            dfi->fname = (char *) malloc(strlen(tmpf));
            bzero(dfi->fname, 0);
            strncpy(dfi->fname, tmpf, strlen(tmpf));
            if ((*flist)->first == NULL) {
                (*flist)->first = dfi;
                (*flist)->last = dfi;
                (*flist)->num++;
                continue;
            }
            (*flist)->last->next = dfi;
            (*flist)->last = dfi;
            (*flist)->num++;
        }
        else if (d->d_type == DT_DIR) {//普通目录
            char tmp_dir[1024] = {0};
            sprintf(tmp_dir, "%s/%s", dir, d->d_name);
            read_dir_files(tmp_dir, flist);
        }
    }
    return 0;
}

/**
 * 打印目录里的文件信息
 */
void print_dir_files(DirFileList *flist) {
    if (flist == NULL) {
        printf("empty files\n");
        return;
    }
    if (flist->num == 0 || flist->first == NULL || flist->last == NULL) {
        printf("empty dir\n");
        return;
    }
    DirFileItem *tmp = flist->first;
    while (tmp != NULL) {
        fprintf(stderr, "%s\n", tmp->fname);
        fflush(stderr);
        tmp = tmp->next;
    }
}

/**
 * 销毁文件列表
 */
void free_dir_files(DirFileList *flist) {
    if (flist == NULL) {
        return;
    }
    if (flist->num == 0 || flist->first == NULL || flist->last == NULL) {
        free(flist);
        return;
    }
    DirFileItem *tmp = flist->first;
    DirFileItem *tmp1;
    while (tmp != NULL) {
        tmp1 = tmp->next;
        free(tmp);
        tmp = tmp1;
    }
    return;
}