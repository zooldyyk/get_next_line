#include "get_next_line.h"

char *ft_read(int fd, char buf, char **line)
{
    int         ret;

    ret = read(fd, buf, BUFFER_SIZE) //recalcule ret sinon reste à 0, read sert à lire la variable
    while (ret > 0)
    {
        buf[ret] = 0; //afficher la fin du fichier, read va retourner le nombre d'octet du fichier
        if (!line)
            *line = ft_substr(buf, 0, ret);
        else
        {
            temp = *line;
            *line = ft_strjoin(*line, buf, BUFFER_SIZE)
            free(temp);  //pour eviter d'avoir des leaks
        }
        if(ft_strchr(buf, '\n'))//si dans buf je trouve un retour à la ligne, la boucle s'arrête
            break;
            //LIONEL EN Y SUR LE TMAX\nYAMMAHA
        ret = read fd, buf, BUFFER_SIZE);
    }
    free(buf);
}
    

    while (ret > 0)
    {
        ret =  read (fd, buf, BUFFER_SIZE); //recalcule ret sinon reste à 0, read sert à lire la variable
        if (ret == -1)
            ret = -1; 
        buf[ret] = 0; //afficher la fin du fichier, read va retourner le nombre d'octet du fichier
        temp = *line; 
        *line = ft_strjoin(str, buf);
        free(temp); //pour eviter d'avoir des leaks au niveau de str
        if (ft_strchr(str, '\n')) //si dans str je trouve un retour à la ligne, la boucle s'arrête
            break;
            //LIONEL EN Y SUR LE TMAX\nYAMMAHA
    }
    //gerer en cas de \n + autre chose(caractère)
    **line = ft_glitch(str, &ret); // LIONEL EN Y SUR LE TMAX \n
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