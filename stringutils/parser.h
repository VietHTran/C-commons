//Methods that allow string parsing

#ifndef PARSER_H
#define PARSER_H
#define ULL unsigned long long 

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "strgeneral.h"

//Return Roman representation of an integer
void inttrome(int num,string result,int buffer);

//Return unsigned long long representation of a Roman numeral
ULL rometull(string rnum,int buffer);

#include "parser.c"
#undef ULL
#endif
