//Methods that gets provide common Unix shell feature

#ifndef CSHELL_H
#define CSHELL_H

#include "../stringutils/strgeneral.h"

//return string of current directory
//X_STR: char* type
#define pwd(X_STR) do {                                         \
    assert(getcwd(X_STR,sizeof(X_STR))!=NULL);                  \
} while (0)

#include "cshell.c"

#endif
