#ifndef __PROCESS_COPY_H__
#define __PROCESS_COPY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int check_pram(int argc, const char*, int);
int block_cur(const char* srcfile, int pronum);
int process_create(const char* srcfile, const char* destfile, int pronum, int blocksize);
void process_wait(void);

#endif