#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include "mv.h"
char * getFileName(char * fileName){//获取所要操作的文件名
	char tp[100],*nm=(char*)malloc(sizeof(char));
	int i,j=0;
	for(i=strlen(fileName)-1;i>=0;i--)//从最后开始找，保存最后一个“/”的下标
	{
		if(fileName[i]=='/')break;
	}
	for(i++;i<strlen(fileName);i++)
	{
		tp[j++]=fileName[i];
	}
	tp[j]='\0'; //表示一个字符串结束的标志
	strcpy(nm,tp);
	return nm;
}
int mv(int ac,char * av[]){
	struct stat st;
	if(ac!=3){//控制台输入格式错误
		fprintf(stderr,"usage: %s source destination not found\n",*av);
	}
	//stat获取文件信息 ，成功返回0,失败返回-1
        //函数原型int stat(const char *path,struct stat *buf)
	if(stat(av[1],&st)==-1 || S_ISDIR(st.st_mode)){//判断是否是一个目录
		printf("source is not a file");
		exit(1);
	}
	if(stat(av[2],&st)!=-1){//查看是不是目录 
		if(S_ISDIR(st.st_mode)){
			strcpy(av[2]+strlen(av[2]),"/");
			strcpy(av[2]+strlen(av[2]),getFileName(av[1]));
			strcpy(av[2]+strlen(av[2]),"\0");
		}else{
			printf("destination file is already exist\n");
		}
	}
	if(rename(av[1],av[2])==-1){//实现名字的更改
		printf("error!\n");
	}

	return 1;
}
