#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#define MAX_BUFF 1024

//return string of current directory
string pwd() {
   char pwd[MAX_BUFF];
   assert(getcwd(pwd,sizeof(pwd))!=NULL);
   return pwd;
}
