#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

#include "cd.h"
#include "bianliang.h"
int cd()
{
	char buf[LEN];
        if (chdir(arglist[1])>=0)
        {
            getcwd(buf,sizeof(buf));
            printf("Current dir is:%s\n",buf);
        }

}
