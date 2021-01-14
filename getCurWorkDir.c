#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "getCurWorkDir.h"
void  getCurWorkDir()
{
	char buf[1024]={0};
	getcwd(buf,sizeof(buf));
	printf("%s",buf);
}
