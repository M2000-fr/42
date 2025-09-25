#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int start;
    int end;
    int flag;

    flag = 0;
    //on regarde d'abord si on a au moins un arg et qu'il s'agit bien d'une string ou au moins d'un char
    if (argc > 1 && argv[1][0])
    {
        i = 0;
        //d'abord on passe tous les espaces
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        //ainsi on connais le début du premier mot
        start = i;
        //ensuite on avance jusqu'à la fini du mot
        while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;
        // on continue de passer les espaces
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i]) 
        {
            //on continue de passer les DOUBLES espaces après le deuxième mot
            while ((argv[1][i] == ' ' && argv[1][i + 1] == ' ') || (argv[1][i] == '\t' && argv[1][i + 1] == '\t'))
                i++; 
            //on met un flag pour mettre un espace à la fin de la string pour y écrit ensuite le premier mot q'ion a passé au début
            //ce flag va s'actualiser à chaque espace pour être décalé à chaque fin de mot à par le dernier évidement
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1; 
            write(1, &argv[1][i], 1);
            i++;
        }
        // on met donc cet espace
        if (flag)
            write(1, " ", 1);
        while (start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return(0);
}