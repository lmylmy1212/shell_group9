#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "pwd.h"
#include "getCurWorkDir.h"

int pwd(int argc, char *argv[])
{
  
    getCurWorkDir();
    printf("\n");
    return 0;
}
