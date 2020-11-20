#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include "ls.h"
#include "cat.h"
#include "rm.h"
#include "touch.h"
#include "cp.h"
#include "echo.h"
#include "mv.h"
#include "pwd.h"
#include "vi.h"
#define MAX 100
#define LEN 100

char *arglist[MAX];  //shell指令参数表
int num;             //shell指令参数个数

int execute(char* arglist[])//执行外部命令
{
    if (strcmp(arglist[0],"cat\0")==0){
    	cat(arglist);
    }
    else if(strcmp(arglist[0],"rm\0")==0)
    {
    	rm(arglist);
    }
    else if(strcmp(arglist[0],"touch\0")==0)
    {
        touch(num,arglist);
    }
    else if(strcmp(arglist[0],"cp\0")==0)
    {
        cp(num,arglist);
    }
    else if(strcmp(arglist[0],"echo\0")==0)
    {
        echo(num,arglist);
    }
    else if(strcmp(arglist[0],"ls\0")==0)
    {
        ls();
    }
    else if(strcmp(arglist[0],"mv\0")==0)
    {
        mv(num,arglist);
    }
    else if(strcmp(arglist[0],"vi\0")==0)
    {
        vi(num,arglist);
    }



    exit(1);
}

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
int inner(char *arglist[])//执行内置指令
{
    if (strcmp(arglist[0],"exit\0")==0)//exit
    {
        exit(0);
        return 1;
    }
    else if (strcmp(arglist[0],"pwd\0")==0)//pwd
    {
	 pwd(num,arglist);
	 return 1;
    }
    else if (strcmp(arglist[0],"cd\0")==0)//cd
    {
        char buf[LEN];
        if (chdir(arglist[1])>=0)
        {
            getcwd(buf,sizeof(buf));
            printf("Current dir is:%s\n",buf);
        }
        return 1;
    }
    else return 0;
}

int main()
{
    int i,pid;
    char buf[LEN];
    while (1)
    {
	printf("shell@group_9$:");
        fgets(buf,LEN,stdin);//读入单行指令
        num=my_system(buf,arglist);//指令分割
	//printf("%d",num);
        int inner_flag;
        inner_flag=inner(arglist);//内置指令判断
        //printf("%d",inner_flag);
	if (inner_flag==0)//外部指令
        {
            pid=fork();//建立新的进程
            if (pid==0)//子进程
            {
               execute(arglist);//执行	      
            }
            waitpid(pid,NULL,0);
        }
    }
    return 0;
}
