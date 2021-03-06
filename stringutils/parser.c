#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "strinfo.h"
#include "../generics.h"

//Return Roman representation of an integer
void inttrome(int num,string result,int buffer) {
    assert(num>0); //num must be positive
    assert(result!=NULL);
    assert(buffer<=MAX_CHARS);
    int current_index=-1;
    while (num!=0) {
        checkerr((current_index==buffer),"String limit exceeded");
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

//Return unsigned long long representation of a Roman numeral
ULL rometull(string rnum,int buffer) {
    assert(rnum!=NULL);
    assert(buffer>0);
    int rchar[26]={[0 ... 25]=0};
    rchar[(int)'I'-65]=1;    
    rchar[(int)'V'-65]=5;    
    rchar[(int)'X'-65]=10;    
    rchar[(int)'L'-65]=50;    
    rchar[(int)'C'-65]=100;    
    rchar[(int)'D'-65]=500;    
    rchar[(int)'M'-65]=1000;
    for (int i=0;i<buffer;i++) {
        checkerr(rnum[i]=='\0',"Buffer error");
        int ord=(int) rnum[i]-65;
        checkerr((ord<0 || ord > 25 || rchar[ord]==0),
                "Unrecognized character");
    }
    bool is_vx=false,is_lc=false,is_dm=false;
    ULL sum=rchar[(int)rnum[buffer-1]-65];
    for (int i=buffer-2;i>=0;i--) {
        if (rnum[i]=='I' && (is_vx  || 
                    rnum[i+1]=='X'  || 
                    rnum[i+1]=='V')) {
            --sum;
            if (!is_vx) {
                is_vx=true;
            }
        } else if (rnum[i]=='X' && 
                (is_lc          || 
                 rnum[i+1]=='L' || 
                 rnum[i+1]=='C')) {
            sum-=10;
        } else if (rnum[i]=='C' && 
                (is_dm          || 
                 rnum[i+1]=='D' || 
                 rnum[i+1]=='M')) {
            sum-=100;
        } else {
            sum+=rchar[(int)rnum[i]-65];
            if (is_vx) {
                is_vx=false;
            }
            if (is_lc) {
                is_lc=false;
            }
            if (is_dm) {
                is_dm=false;
            }
        }
    }
    return sum;
}

