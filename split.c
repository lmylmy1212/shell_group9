#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include "split.h"
#include "bianliang.h"
char* make(char *buf)//将字符串传入参数表内
{
    char *cp;
    cp=malloc(strlen(buf)+1);
    if (cp==NULL)
    {
        fprintf(stderr,"no memory\n");
        exit(1);
    }
    strcpy(cp,buf);
    return cp;
}
int my_system(char *buf,char *arglist[])//对于字符串进行分割
{
    int num,j,i,last;
    char buffer[LEN];
    num=0;
    i=0;
    while (num<MAX)
    {
        if (buf[i]=='\n')
        {
            arglist[num]=NULL;
            return num;
        }
        if (buf[i]==' ') i++;
        last=i;
        while (buf[i]!=' ' && buf[i]!='\n') i++;
        for (j=last;j<i;j++) buffer[j-last]=buf[j];
        buffer[j-last]='\0';
        arglist[num++]=make(buffer);
    }
}

