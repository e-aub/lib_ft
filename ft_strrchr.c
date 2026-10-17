char *ft_strrchr(const char *s, int c){
    char *last;

    last = 0;
    char c_c = (char)c;
    while (*s)
    {
        if (*s == c_c){
            last = (char *)s;
        }
        s++;
    }

    if (*s == c_c){
        last = (char *)s;
    }
    
    return last;
}