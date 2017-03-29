//duplicate string
string clone_str(string str) {
    int length=len_str(str)+1;
    string return_str=(string)malloc(length*sizeof(char));
    strcpy(return_str,str);
    return return_str;    
}
