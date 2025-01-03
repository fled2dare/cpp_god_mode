char *my_strncat(char *dest, const char *src, int x)
{
    char *dest_n = dest + strlen(dest);
    int i;
    for (int i = 0; i < x && src[i] != '\0'; i++)
    {
        dest_n[i] = src[i];
    }

    dest_n[i] = '\0';
    return dest;
}

#define MY_SIZEOF(type) ((char *)(&type + 1) - (char *)(&type))

char *my_strtok(char *src, const char *delim)
{
}

void *my_memcpy(void *dest, const void *src, int n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (int i = 0; i < n; i++)
    {
        d[i] = s[i];
    }

    return dest;
}

char *my_strtok(char *str, const char *delim)
{
    static char *new_token = NULL;

    if (str)
    {
        new_token = str;
    }else if(!new_token){
        return NULL;
    }

    char *start = new_token;

    while (*new_token)
    {
        for (const char *d = delim; d++; *d){
            if(*new_token == *d){
                *new_token = '\0';
                new_token++;
                return start;
            }
        }
        new_token++;
    }

    new_token = NULL;
    return start;
}