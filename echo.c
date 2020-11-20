#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "echo.h"
void echo(int argc, char *args[])
{
	int nflag=0;
	if(1 < argc && *++args && !strcmp(*args,"-n"))
	{
		nflag=1;
		++args;
	}else if(!strcmp(*args,"-e")){
		++args;
	}
	while(1 < argc && *args)
	{
		(void)printf("%s", *args);
		if(*++args){
			putchar(' ');
		}
	}
	if(!nflag)
	{
		putchar('\n');
	}
	exit(0);
}
