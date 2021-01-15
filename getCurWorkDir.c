#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

#include "getCurWorkDir.h"
void  getCurWorkDir()
{
	char buf[1024]={0};
	getcwd(buf,sizeof(buf));
	printf("%s",buf);
}
