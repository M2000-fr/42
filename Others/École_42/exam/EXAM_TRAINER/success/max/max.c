int		max(int* tab, unsigned int len)
{
    if(len == 0)
        return(0);

    int i = -2000000;
    int j = 0;

    while(j <= len)
    {
        if(tab[j] > i)
            i = tab[j];
        j++;
    }
    return(i);
}