#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
ino_t get_ino_byname(char *filename);
char* find_name_byino(ino_t ino);
int pwd(int argc, char *argv[]);
