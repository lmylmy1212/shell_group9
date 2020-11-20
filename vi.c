#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
#define MAXLINE 100
#include "vi.h"
char Buffer[MAXLEN];
char *LinePointer[MAXLINE];
int modified=0;//正文被修改标志
int LineNum;//当前正文行数

int vi(int argc,char *argv[]){

   if(argc<2){
     return -1;
   }
   FILE *fp=fopen(argv[1],"a");
   FILE *fp2=fopen(argv[1],"r");
   if(fp==NULL){
   printf("创建文件失败\n");
   }

    char str[1024]; 
    int c;
    while((c=fgetc(fp2))!=EOF) putchar(c);

   while(1){
     scanf("%s",str);
     if(strncmp(str,":wq",3)==0){
    //strncmp将str与“exit”前四个字节进行比较
       break;
     } 
     fprintf(fp,"%s\n",str);//将格式化的数据写入文件
     memset(str,0,1024);//复制“0”到str所指向的字符串前1024个字符
   }
   fclose(fp);
   fclose(fp2);
   return 0;
}
