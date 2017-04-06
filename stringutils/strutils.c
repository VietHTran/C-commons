#include <assert.h>
#include <string.h>
#include "strinfo.h"

//Duplicates string
string clone_str(string str) {
    int length=len_str(str)+1;
    string return_str=(string)malloc(length*sizeof(char));
    strcpy(return_str,str);
    return return_str;    
}

//Gets substring with (length) characters from index start
string substring(string str, int start, int length) {
    assert(start>=0 && start+length<=len_str(str) && start<length);
    string holder=(string)malloc((length-start)*sizeof(char));
    strncpy(holder,&str[start],length);
    return holder;
}

//Returns a lower case version of the string
string lowercase(string str) {
    string result=clone_str(str);
    for (int i=0;str[i]!='\0';i++) {
        int ord=(int)result[i];
        if (ord>=65 && ord<=90) {
            result[i]=(char)(ord+32);
        }
    }
    return result;
}

//Returns a uppercase version of the string
string uppercase(string str) {
    string result=clone_str(str);
    for (int i=0;str[i]!='\0';i++) {
        int ord=(int)result[i];
        if (ord>=97 && ord<=122) {
            result[i]=(char)(ord-32);
        }
    }
    return result;
}
