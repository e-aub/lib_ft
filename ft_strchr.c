char *ft_strchr(const char *s, int c){

    char c_c = (char) c;
    while(*s && *s != c_c){
        s++;
    }

    if (c_c == *s){
        return (char *)s;
    }

    return 0;
}