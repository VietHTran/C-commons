#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "strinfo.h"

//Maximum characters in a string
const int MAX_CHARS=4095;

//Duplicates string
string cpstr(string str) {
    assert(str[0]!='\0');
    int length=lenstr(str)+1;
    string return_str=(string)malloc(length*sizeof(char));
    strcpy(return_str,str);
    return_str[length-1]='\0';
    return return_str;    
}

//Gets substr with length characters from index start
//This function is can be called by substr function with the same signature
string substr3(string str, int start, int length) {
    assert( str[0]!='\0' && 
            start>=0 && 
            start+length<=lenstr(str) && 
            start<length);
    string holder=(string)malloc((length+1)*sizeof(char));
    strncpy(holder,&str[start],length);
    holder[length]='\0';
    return holder;
}

//Gets substring from index start to the end to str
//This function is can be called by substr function with the same signature
string substr2(string str,int start) {
    assert(start>=0 && str[0]!='\0');
    int length=lenstr(str);
    assert(start<length);
    int holder_length=length-start;
    string holder=(string)malloc((holder_length+1)*sizeof(char));
    strncpy(holder,&str[start],length-start);
    holder[holder_length]='\0';
    return holder;
}

//Return an allocated, non-whitespace version of string str
string rmspace(string str) {
    assert(str!='\0');
    string new_str=cpstr(str);
    int cur_index=-1;
    ITR_STR(str,i) {
        if (str[i]==' ' || str[i]=='\n' || str[i]=='\t') {
            continue;
        }
        new_str[++cur_index]=str[i];
    }
    new_str[++cur_index]='\0';
    return new_str;
}

//Returns a lower case version of the string
string lowercase(string str) {
    string result=cpstr(str);
    ITR_STR(str,i) {
        int ord=(int)result[i];
        if (ord>=65 && ord<=90) {
            result[i]=(char)(ord+32);
        }
    }
    return result;
}

//Returns a uppercase version of the string
string uppercase(string str) {
    string result=cpstr(str);
    ITR_STR(str,i) {
        int ord=(int)result[i];
        if (ord>=97 && ord<=122) {
            result[i]=(char)(ord-32);
        }
    }
    return result;
}
