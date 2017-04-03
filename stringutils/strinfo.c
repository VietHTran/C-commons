//Returns length of string
int len_str(string str) {
    assert(str!=NULL);
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

//Checks if contains only alphabetic characters
bool is_word(string str) {
    assert(str!=NULL);
    for (int i=0;str[i]!='\0';i++) {
        int ascii_num=(int)str[i];
        if (!((ascii_num>=65 && ascii_num<=90) 
                || (ascii_num>=97 && ascii_num<=122))) {
            return false;
        }
    }
    return true;
}

//Get str ends with suffix 
bool ends_with_str(string str, string suffix) {
    assert(str!=NULL && suffix!=NULL);
    int strlength=len_str(str);
    int suflength=len_str(suffix);
    assert(strlength>=suflength);
    while (suflength>0) {
        --suflength;
        --strlength;
        if (str[strlength]!=suffix[suflength]) {return false;}
    }
    return true;
}

//Checks if string only consists of digits
bool is_digit(string str) {
    assert(str!=NULL && str[0]!='\0');
    for (int i=0;str[i]!='\0';i++) {
        if (!(str[i]>=48 && str[i]<=57)) {return false;}
    }
    return true;
}

//Returns the first index that has c character in the string str
//Returns -1 if not found.
int index_of_str_basic(string str, char c) {
    assert(str!=NULL);
    for (int i=0;str[i]!='\0';i++) {
        if (str[i]==c) {return i;}
    }
    return -1;
}

//Returns the first index that has c character in the string str starting from index. 
//Returns -1 if not found.
int index_of_n_str(string str, char c, int index) {
    assert(str!=NULL && len_str(str)>index && index>=0);
    for (int i=index;str[i]!='\0';i++) {
        if (str[i]==c) {return i;}
    }
    return -1;
}

//Returns the index within str of the first occurrence of the substring sub.
//Return -1 if not found
int index_of_str_sub(string str,string sub){
    assert(str!=NULL && sub!=NULL && sub[0]!='\0');
    int str_i=0,sub_i=0,fallback=-1;
    while (str[str_i]!='\0' && sub[sub_i]!='\0') {
        if (str[str_i]==sub[sub_i]) {
            ++sub_i;
            if (fallback==-1) {fallback=str_i;}
        } 
        else {
            sub_i=0;
            if (fallback!=-1) {
                str_i=fallback;
                fallback=-1;
            }
        }
        ++str_i;
    }
    return sub[sub_i]=='\0' ? str_i-sub_i : -1; 
}

//Returns the index within str of the first occurrence of the substring subi, starting at specified index.
//Return -1 if not found
int index_of_n_str_sub(string str,string sub, int index) {
    assert(str!=NULL && sub!=NULL && sub[0]!='\0' && len_str(str)>index && index>=0);
    int str_i=index,sub_i=0,fallback=-1;
    while (str[str_i]!='\0' && sub[sub_i]!='\0') {
        if (str[str_i]==sub[sub_i]) {
            ++sub_i;
            if (fallback==-1) {fallback=str_i;}
        } 
        else {
            sub_i=0;
            if (fallback!=-1) {
                str_i=fallback;
                fallback=-1;
            }
        }
        ++str_i;
    }
    return sub[sub_i]=='\0' ? str_i-sub_i : -1; 
}


