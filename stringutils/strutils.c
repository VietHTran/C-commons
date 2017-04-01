#include <assert.h>
#include <string.h>
#include "strinfo.h"

//Duplicate string
string clone_str(string str) {
    int length=len_str(str)+1;
    string return_str=(string)malloc(length*sizeof(char));
    strcpy(return_str,str);
    return return_str;    
}

//Get substring with (length) characters from index start
string substring(string str, int start, int length) {
    assert(start>=0 && start+length<=len_str(str) && start<length);
    string holder=(string)malloc((length-start)*sizeof(char));
    strncpy(holder,&str[start],length);
    return holder;
}
