CC = gcc
CFLAGS = -D__STDC_LIMIT_MACROS -m64 -Wno-deprecated -Wall -g 
UTILS_DIR=./../src/utils
INC_DIR = -I${UTILS_DIR}  

utils_objs=${UTILS_DIR}/base64.o \
		   ${UTILS_DIR}/file.o \
		   ${UTILS_DIR}/md5.o \
		   ${UTILS_DIR}/hash_map.o \
		   ${UTILS_DIR}/hash_set.o \
		   ${UTILS_DIR}/link_list.o \
		   ${UTILS_DIR}/urlencode.o 

%.o:%.c
	$(CC) $(CFLAGS) ${INC_DIR} -c $< -o $@ 

all: md5 

md5: ${utils_objs}
	$(CC) ${utils_objs} -o $@ ${CFLAGS}  ${INC_DIR} md5.c 

clean:
	rm -rf ${utils_objs}
	rm -rf md5 




