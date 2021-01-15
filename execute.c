#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "execute.h"
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
#include "cd.h"
#include "pwd.h"
#include "bianliang.h"


int execute(int argc,char* arglist[])
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
    
   
    
    else if(strcmp(arglist[0],"exit\0")==0)
    {
        exit(0);
    }
    else if(strcmp(arglist[0],"pwd\0")==0)
    {
        pwd();
    }
    else if (strcmp(arglist[0],"cd\0")==0)
    {
        cd();
    }



    
}

