#include "get_next_line.h"

/* 
    (*Pointeur).un champ = x;
                = 
    Pointeur->un champ = x;
*/

int init_check(int fd, t_read *strct)
{
    strct->pos = 0;
    strct->max = read(fd, strct->str, BUFFER_SIZE);
    strct->fd = fd;
    if (strct->max <= 0)
        return (0); // 0 = False
    else 
        return (1); // 1 = True
}

char read_check(t_read *strct)
{
    char result;

    if (strct-> pos >= strct->max)
    {
        strct->max = read(strct->fd, strct->str, BUFFER_SIZE);
        strct->pos = 0;
        if (strct->max <= 0)
            return (0);
    }
    result = strct->str[strct->pos];
    strct->pos++;
    return(result);
}
