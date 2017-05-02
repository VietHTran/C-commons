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

//Return Roman representation of an integer
void inttrome(int num,string result,int length) {
    assert(num>0); //num must be positive
    assert(result!=NULL);
    assert(length<=MAX_CHARS);
    int current_index=-1;
    while (num!=0) {
        if (current_index==length) {
            perror("String limit exceeded");
            exit(1);
        }
        if (num>=1000) {
            num-=1000;
            result[++current_index]='M';
        } else if (num>=900) {
            num-=900;
            result[++current_index]='C';
            result[++current_index]='M';
        } else if (num>=500) {
            num-=500;
            result[++current_index]='D';
        } else if (num>=400) {
            num-=400;
            result[++current_index]='C';
            result[++current_index]='D';
        } else if (num>=100) {
            num-=100;
            result[++current_index]='C';
        } else if (num>=90) {
            num-=90;
            result[++current_index]='X';
            result[++current_index]='C';
        } else if (num>=50) {
            num-=50;
            result[++current_index]='L';
        } else if (num>=40) {
            num-=40;
            result[++current_index]='X';
            result[++current_index]='L';
        } else if (num>=10) {
            num-=10;
            result[++current_index]='X';
        } else if (num>=9) {
            num-=9;
            result[++current_index]='I';
            result[++current_index]='X';
        } else if (num>=5) {
            num-=5;
            result[++current_index]='V';
        } else if (num>=4) {
            num-=4;
            result[++current_index]='I';
            result[++current_index]='V';
        } else if (num>=1) {
            num--;
            result[++current_index]='I';
        }
    }
    result[++current_index]='\0';
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
