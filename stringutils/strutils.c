#include <assert.h>
#include <string.h>
#include "strinfo.h"

//Duplicates string
string clone_str(string str) {
    assert(str[0]!='\0');
    int length=len_str(str)+1;
    string return_str=(string)malloc(length*sizeof(char));
    strcpy(return_str,str);
    return return_str;    
}

//Gets substring with length characters from index start
//This function is can be called by substring function with the same signature
string substring3(string str, int start, int length) {
    assert( str[0]!='\0' && 
            start>=0 && 
            start+length<=len_str(str) && 
            start<length);
    string holder=(string)malloc((length+1)*sizeof(char));
    strncpy(holder,&str[start],length);
    holder[length]='\0';
    return holder;
}

//Gets substring from index start to the end to str
//This function is can be called by substring function with the same signature
string substring2(string str,int start) {
    assert(start>=0 && str[0]!='\0');
    int length=len_str(str);
    assert(start<length);
    int holder_length=length-start;
    string holder=(string)malloc((holder_length+1)*sizeof(char));
    strncpy(holder,&str[start],length-start);
    holder[holder_length]='\0';
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
