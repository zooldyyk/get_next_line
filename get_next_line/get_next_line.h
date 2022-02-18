
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef     BUFFER_SIZE
#  define BUFFER_SIZE 8
#endif

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

//structure = regroupement de données
typedef struct t_read
{
    int     fd;
    int     max;
    int     pos;
    char    str[BUFFER_SIZE];
   // defini nom de la structure (pour ne pas mettre a chaque fois struct t_read)
}   t_read;

int     ft_strlen(char	*str);
char    *ft_strjoin(char *s1, char chara);
char	*get_next_line(int fd);
int	    init_check(int fd, t_read *strct);
char    read_check(t_read *strct);
#endif
