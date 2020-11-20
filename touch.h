#include<stdio.h>
#include<getopt.h>
#include<sys/types.h>
#include<time.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/time.h>
#include<sys/stat.h>
static bool mytouch(const char *file);
int touch(int argc, char **argv);
