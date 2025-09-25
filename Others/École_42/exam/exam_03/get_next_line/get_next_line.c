#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *rem;
    char *buf, *line, *new_rem;
    int r, i, j, k, len1, len2;

    if (fd < 0 || BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE + 1)))
        return NULL;
    while (1)
    {
        for (i = 0; rem && rem[i]; i++)
            if (rem[i] == '\n')
                break;
        if (rem && rem[i] == '\n')
            break;
        r = read(fd, buf, BUFFER_SIZE);
        if (r <= 0)
            break;
        buf[r] = '\0';
        for (len1 = 0; rem && rem[len1]; len1++);
        for (len2 = 0; buf[len2]; len2++);
        new_rem = malloc(len1 + len2 + 1);
        if (!new_rem) { free(buf); return NULL; }
        for (i = 0; i < len1; i++)
            new_rem[i] = rem[i];
        for (j = 0; j <= len2; j++)
            new_rem[len1 + j] = buf[j];
        free(rem);
        rem = new_rem;
    }
    free(buf);
    if (!rem || !rem[0]) { free(rem); rem = 0; return NULL; }
    for (i = 0; rem[i] && rem[i] != '\n'; i++);
    if (rem[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (!line)
        return NULL;
    for (j = 0; j < i; j++)
        line[j] = rem[j];
    line[i] = '\0';
    for (k = 0; rem[i + k]; k++);
    if (k == 0) { free(rem); rem = 0; }
    else
    {
        new_rem = malloc(k + 1);
        for (j = 0; j <= k; j++)
            new_rem[j] = rem[i + j];
        free(rem);
        rem = new_rem;
    }
    return line;
}

int    main(int ac, char **av)
{
<<<<<<< HEAD
    char    *line;
    int        fd;
    int        i;

    i = 0;
    if (ac != 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        printf("res[%d] = [%s]\n", i++, line);
        free(line);
    }
=======
	static char	buffer[BUFFER_SIZE];
	char		line[BUFFER_SIZE];
	static int	buffer_reading;
	static int	buffer_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_reading)
		{
			buffer_reading = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_reading <= 0)
				break ;
		}
		line[i] = buffer[buffer_pos++];
		if (line[i] == '\n')
			break ;
		i++;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("res[%d] = [%s]\n", i++, line);
		free(line);
	}
>>>>>>> 2ed242d (Tue Feb 11 01:16:20 PM CET 2025 - /home/mechard/Desktop/42_Paris update)
}
