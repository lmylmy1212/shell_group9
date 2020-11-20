#include <stdio.h>
#include "cat.h"
int cat(char *argv[])
{
    FILE *fp = fopen(argv[1], "r");   // 以只读方式打开文件，argv[1]是输入的要显示的文件路径名
    int read_ret;
   
    while(1)  //成功打开
    {
        read_ret = fgetc(fp);  //单个字符读写
        if(feof(fp))  // feof判断文件结束，若fp已经指向文件末尾，则feof（fp）函数值为“真”，即返回非零值
        {
           // printf("read file %s endl\n",argv[1]);   //提示读写结束       
            break;
        }
        fputc(read_ret,stdout);  //把单个字符输出到屏幕
    }
}
