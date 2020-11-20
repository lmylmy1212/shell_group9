#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include "rm.h"
int rm(char *argv[]){
  if(unlink(argv[1])!=0) //删除这个名字所指向的我呢间
  perror("unlink"),exit(-1);

  printf("unlink %s success!\n",basename(argv[1]));
  return 0;
}
