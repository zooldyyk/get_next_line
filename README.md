
                                      APRES QUELQUES RECHERCHES, J'AI TROUVÉ QUE C'ÉTAIT PLUS SIMPLE DE FAIRE GNL AVEC DES STRUCTS
                                    DONC LE CODE EST FAIT AVEC DES STRUCTS, RENSEIGNEZ VOUS SUR LES STRUCTS C'EST VRAIMENT PLUS SIMPLE!



LES COMMENTAIRES SONT FAIT POUR BALLTROU PORTOS ET TCHOUPI BANDE D'INCAPABLES (EHH MERCCEEE JM)

<h1 align="center">
    Project n°2 - get_next_line
    <h4 align="center" style="width: 54%; margin: 2rem auto; font-weight: normal;"> 
    Fonction qui retourne une ligne lue depuis un file descriptor.
    </h4>
</h1>

## Description

L'appel de la fonction ``char *get_next_line(int fd)`` dans une boucle vous permettra de lire le texte disponible sur le descripteur de fichier une ligne à la fois jusqu'à la fin.
disponible sur le descripteur de fichier, une ligne à la fois, jusqu'à la fin de celui-ci.

Le fichier doit être lu ligne par ligne jusqu'à ce qu'il trouve une nouvelle ligne (ASCII = '\n') et pas plus. Lire tout le fichier en une seule fois n'est pas recommandé, c'est pourquoi nous utilisons un ``BUFFER_SIZE`` global pour définir le nombre d'octets que la fonction va lire.

## Functions needed
- [malloc()](https://man7.org/linux/man-pages/man3/malloc.3.html), [free()](https://man7.org/linux/man-pages/man1/free.1.html)
- [read()](https://man7.org/linux/man-pages/man2/read.2.html) ([open()](https://man7.org/linux/man-pages/man2/open.2.html) and [close()](https://man7.org/linux/man-pages/man2/close.2.html) are used only in the main)
- [ft_strchr()](https://github.com/zooldyyk/Libft.a/blob/main/ft_strchr.c), [ft_strlen()](https://github.com/zooldyyk/piscine/blob/main/c04/ex00/ft_strlen.c), [ft_strdup()](https://github.com/zooldyyk/Libft.a/blob/main/ft_strdup.c), [ft_substr()](https://github.com/MarJC5/Libft/blob/main/libft/ft_substr.c), [ft_strjoin()](https://github.com/zooldyyk/Libft.a/blob/main/ft_strjoin.c)

## Set-by-step

### 1. Configuration des variables
Pour cette fonction, nous avons besoin d'utiliser 2 variables importantes :
- ``static char *save`` : Une variable statique est capable de sauvegarder les données qui lui sont passées même après la fin de la fonction, cela nous permettra de réutiliser les données qu'elle contient après un nouvel appel de la fonction.
- ``char *buf`` : Sera utilisé pour stocker la valeur lue actuelle concernant le ``BUFFER_SIZE``.

### 2. Vérifier si notre ``descripteur de fichier`` est valide
Pour lire un fichier, nous utilisons la fonction ``read()`` qui prend un ``int fd`` comme argument. Le ``fd`` retourne le nombre d'octet qu'il a lu, 0 si c'est la fin du fichier et -1 si le descripteur de fichier n'est pas valide.

### 3. Vérifiez le ``BUFFER_SIZE`` et malloc
Comme nous avons besoin d'un tampon pour savoir combien d'octets le programme va lire à chaque fois, le `BUFFER_SIZE`` doit être supérieur à 0. Si les étapes 1 et 2 ne sont pas bonnes, nous retournons (null).

Ensuite, si ``BUFFER_SIZE`` est correct, nous pouvons créer un ``malloc()`` concernant sa taille et ajouter +1 pour le '``0'.

Nous sécurisons le ``malloc()`` en vérifiant que ``buf`` n'est pas NULL et nous créons un ``malloc()`` vide dans le ``save`` statique seulement s'il n'a pas de valeur dedans (c'est une sécurité pour plus tard dans le programme).

Comme tout est maintenant réglé, nous pouvons passer à l'étape suivante du programme et appeler la fonction ``char *ft_read_file(int fd, char **save, char *buf)``.

### 4. Lire le fichier
2 variables sont nécessaires :
- ``int file`` : Pour stocker la valeur de retour de ``read()``.
- ``char *tmp`` : Pour sauvegarder les données et les échanger plus tard

Une boucle while est utilisée pour boucler le fichier jusqu'à ce que ``file`` soit égal à 0. La boucle va :
- Ajouter un '\0' à la fin du fichier, ce qui nous indiquera quand arrêter le fichier à la fin.
- Joindre à notre ``*save`` statique tout le contenu du ``buf`` que nous venons de lire. C'est pourquoi nous devons définir un ``malloc()`` vide car ``ft_strjoin()`` ne fonctionne pas avec une valeur NULL.
- L'étape suivante consiste à ``free()`` notre statique pour y enregistrer ses nouvelles données. (Ceci pour éviter les fuites de mémoire)
- Avant de lire le fichier, nous vérifions avec ``ft_strchr()`` si nous avons déjà un ``n'' dans notre ``buf``.
    - ``NO`` : Recommencez la boucle jusqu'à ce que vous trouviez un '\n'.
    - OUI : On quitte la boucle et on ``free()`` le ``buf``, puis on vérifie la ligne avec la fonction ``char *ft_return_line(char **save, char *res).``

### 5. Vérifiez la ligne et renvoyez la valeur
Comme nous avons maintenant trouvé la nouvelle ligne, nous devons boucler la statique ``*save`` pour voir ce qu'il faut retourner.
- Bouclez le ``*save`` avec un compteur pour trouver la position '\n'.
- Soustrayez la ligne du début jusqu'à l'inclusion du '\n'.
- Si aucun '\n' n'est trouvé, nous vérifions avec ``ft_strchr()`` si un '\0' est trouvé
    - ``Non trouvé`` : Nous sauvegardons dans ``tmp`` la valeur statique ``*save`` sans la ligne que nous allons retourner. Cela signifie que maintenant ``tmp`` est égal à ``*save`` moins tout ce que nous avons obtenu jusqu'à '\n'. (ex : Hello \n world -> world) Ensuite on peut ``free()`` la statique pour assigner la nouvelle valeur et retourner la ligne.
    - ``0 trouvé`` : Si la statique ``**save`` est == '\0', nous retournons NULL car il n'y a aucune ligne dans la statique. Il ne faut pas forger pour libérer la statique car nous lui avons donné une taille de ``malloc(1)`` au début du programme. (pour éviter les fuites). Sinon la ligne comme une certaine date a inclus '\0', nous retournons simplement la valeur de la statique.
    -
