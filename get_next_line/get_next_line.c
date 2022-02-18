#include "gnl.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return(0);
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char charactere)
{
    char    *str;
    int     i;
    int     size;

    i = 0;
    size = ft_strlen(s1);
    str = (char *)malloc((size + 2) * sizeof(char));
    if (!str)
        return(NULL);
    while (i < size)
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = charactere;
    str[i + 1] = '\0';
    if (s1)
        free(s1);
    return(str);
}

char *get_next_line(int fd)
{
    static t_read   strct = {.fd = -1}; //init la struct
    char            *str;
    char            charactere;

    str = NULL;
    if (strct.fd != fd) 
    {
        if(!init_check(fd, &strct))
            return(NULL);
    }
    charactere = read_check(&strct);
    while(charactere)
    {
        str = ft_strjoin(str, charactere);
        if (charactere == '\n')
            return (str);
        charactere = read_check(&strct);
    }
    return (str);
}