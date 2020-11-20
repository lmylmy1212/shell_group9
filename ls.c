#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "ls.h"
int ls()
{
	DIR *dir;
	struct dirent *rent;
	dir=opendir(".");
	char str[100];
	memset(str,0,100);
	while((rent=readdir(dir)))
	{
		strcpy(str,rent->d_name);
		if(str[0]=='.')
			continue;
		printf("%s ",str);
	}
	puts("");
	closedir(dir);
}
