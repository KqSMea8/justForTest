CC = gcc
CFLAGS = -D__STDC_LIMIT_MACROS -m64 -Wno-deprecated -Wall -g -ggdb 
UTILS_DIR=./../src/utils
INC_DIR = -I${UTILS_DIR}  

utils_objs=${UTILS_DIR}/base64.o \
		   ${UTILS_DIR}/file.o \
		   ${UTILS_DIR}/md5.o \
		   ${UTILS_DIR}/hash_map.o \
		   ${UTILS_DIR}/hash_set.o \
		   ${UTILS_DIR}/link_list.o \
		   ${UTILS_DIR}/urlencode.o \
		   ${UTILS_DIR}/color.o \
		   ${UTILS_DIR}/rbtree.o  

%.o:%.c
	$(CC) $(CFLAGS) ${INC_DIR} -c $< -o $@ 

all: md5 rbtree 

md5: md5.o ${utils_objs}
	$(CC) ${utils_objs} -o $@ ${CFLAGS}  ${INC_DIR} md5.c 

rbtree: rbtree.o ${utils_objs}
	$(CC) ${utils_objs} -o $@ ${CFLAGS}  ${INC_DIR} rbtree.c 

clean:
	rm -rf ${utils_objs}
	rm -rf md5 md5.o 
	rm -rf rbtree rbtree.o




