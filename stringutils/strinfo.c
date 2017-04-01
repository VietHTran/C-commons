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

//Get str ends with prefix
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


