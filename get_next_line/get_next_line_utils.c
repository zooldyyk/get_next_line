#include "get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] && s)
        i++;
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		size;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc((sizeof(char) * size));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
    int i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i]== (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}
char *ft_glitch(char *buf, int *ret)
{
    int     i;
    char    *dest;

    i = 0;
    while (buf && buf[i] && buf[i] != '\n') //compte
        i++;
    dest = malloc(i + 1);
    if (!dest) //protection malloc
        return (NULL);
    i = 0; //renitialise le compteur pour la boucle while
    if (ft_strchr(buf, '\n') != 0) //protection de mémoire
        *ret = 1;
    while (buf && buf[i] && buf[i] != '\n') //mettre chaine dans dest
     {
         dest[i] = buf[i];
         i++;
     }
     dest[i] = '\0';
     return (dest);
}

char *ft_glitch2(char *buf)
{
    int     i;
    int     j;
    char    *dest;

    i = 0;
    while (buf && buf[i] && buf[i] != '\n')
        i++;
    dest = malloc (sizeof(char *) * ft_strlen(buf - i + 1)); //calcule la totale du buf avec ft_strlen
    if (!dest)
        return (NULL);
    j = 0;
    while (buf && buf[i])
        dest[j++] = buf[++i]; //copier après le '\n', donc ++ avant le i
    dest[j] = 0;
    return(dest);
}
