#include <errno.h>
#include <unistd.h>
#include <string.h>


void my_err(char *err_string, int line );


int cp(int argc, char *argv[]);
void copy_data(const int frd,const int fwd);
