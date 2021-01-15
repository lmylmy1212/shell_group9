#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include "execute.h"
#include "getCurWorkDir.h"
#include "split.h"

#include "bianliang.h"
int main()
{
	
	while(1)
	{	
		
		getCurWorkDir();
		printf(":");
		//printf("%s:",buf);
		fgets(buf,LEN,stdin);//读入单行指令
	        num=my_system(buf,arglist);//指令分割

		execute(num,arglist);//执行
		
	}
}
