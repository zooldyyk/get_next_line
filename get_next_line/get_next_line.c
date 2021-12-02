#include "get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char *get_next_line(int fd)
{
    char        buf[BUFFER_SIZE + 1];
    int         ret;
    static char *str = NULL;
    char        *temp;
    char        **line;

    ret = BUFFER_SIZE;
    if (fd < 0 || fd > 1023  || !line || BUFFER_SIZE <= 0)
        return (- 1);
    while (ret > 0)
    {
        ret =  read (fd, buf, BUFFER_SIZE); //recalcule ret sinon reste à 0, read sert à lire la variable
        if (ret == -1)
            return(- 1); 
        buf[ret] = 0; //afficher la fin du fichier, read va retourner le nombre d'octet du fichier
        temp = str; 
        str = ft_strjoin(str, buf);
        free(temp); //pour eviter d'avoir des leaks au niveau de str
        if (ft_strchr(str, '\n')) //si dans str je trouve un retour à la ligne, la boucle s'arrête
            break;
            //LIONEL EN Y SUR LE TMAX\nYAMMAHA
    }
    //gerer en cas de \n + autre chose(caractère)
    *line = ft_glitch(str, &ret); // LIONEL EN Y SUR LE TMAX \n
    temp  = str; //evite d'avoir des leaks 
    str = ft_glitch2(temp); //YAMMAHA
    free(temp);
   /* if (ret == 0 && (*str)[0] == 0) //gestion des problemes de memoires
    {
        free(*str);
        *str = NULL;
    }*/
    return (ret); // pour ça que "&ret" 
}

int main ()
{
    int fd = open("LIONEL", O_RDONLY);
    char *line = NULL;
    int ret = get_next_line(fd, &line);

    while (ret != 0)
    {
        printf("%s", line);
        ret = get_next_line(fd, &line);
    }
}
