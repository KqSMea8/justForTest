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
		   ${UTILS_DIR}/rbtree.o  \
		   ${UTILS_DIR}/xxhash.o \
		   ${UTILS_DIR}/from_java.o

%.o:%.c
	$(CC) $(CFLAGS) ${INC_DIR} -c $< -o $@ 

all: md5.test \
	rbtree.test \
	hmap.test

md5.test: md5.o ${utils_objs}
	$(CC) ${utils_objs} -o md5.test ${CFLAGS}  ${INC_DIR} md5.c 

rbtree.test: rbtree.o ${utils_objs}
	$(CC) ${utils_objs} -o rbtree.test ${CFLAGS}  ${INC_DIR} rbtree.c 

hmap.test: hmap.o ${utils_objs}
	$(CC) ${utils_objs} -o hmap.test ${CFLAGS}  ${INC_DIR} hmap.c 

clean:
	rm -rf ${utils_objs}
	rm -rf *.test *.o *.dSYM *.DSYM 
	rm -rf core.*




