//Returns length of string
int len_str(string str) {
    int i;
    for (i=0;str[i]!='\0';i++);
    return i;
}

//Checks if contains only alphabetic characters
bool is_word(string str) {
    for (int i=0;str[i]!='\0';i++) {
        int ascii_num=(int)str[i];
        if (!((ascii_num>=65 && ascii_num<=90) 
                || (ascii_num>=97 && ascii_num<=122))) {
            return false;
        }
    }
    return true;
}
