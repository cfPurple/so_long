#include "libft.h"

int extend_stash(char **stash, char *buf)
{
	char *temp;
	int i;

	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(*stash) + 1));
	if (temp == NULL)
		return (0);
	while ((*stash)[i])
	{
		temp[i] = (*stash)[i];
		i++;
	}
	temp[i] = '\0';
	free(*stash);
	*stash = malloc(sizeof(char) * (i + ft_strlen(buf) + 1));
	if (*stash == NULL)
		return (0);
	i = 0;
	while (temp[i])
	{
		(*stash)[i] = temp[i];
		i++;
	}
	free(temp);
	return (i);
}

void stock(char **stash, char *buf, int red)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*stash == NULL)
	{
		*stash = malloc(sizeof(char) * (ft_strlen(buf)+ 1));
		if (*stash == NULL)
			return;
	}
	else
		j = extend_stash(stash, buf);
	while(buf[i] && i < red)
		(*stash)[j++] = buf[i++];
	(*stash)[j] = '\0';
}

void read_n_stock(int fd, char **stash)
{
	char *buf;
	int red;

	red = 1;
	while (!found_new_line(*stash) && red != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		red = read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && red == 0) || red < 0)
		{
			free(buf);
			return ;
		}
			buf[red] = '\0';
		stock(stash, buf, red);
		free(buf);
	}
}

void extract_line(char **stash, char **line)
{
	int i;

	i = 0;
	if (*stash == NULL)
		return;
	*line = malloc(sizeof(char) * (char_until_end(*stash) + 1));
	if (*line == NULL)
		return;
	while ((*stash)[i])
	{

		(*line)[i] = (*stash)[i];
		i++;
		if((*stash)[i - 1] == '\n')
			break;
	}
	(*line)[i] = '\0';
}

char *get_next_line(int fd)
{
	char *line;
	static char *stash[FD_SIZE];

	line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//if (stash == NULL)
	//	stash = malloc(sizeof(char *));
	//if (stash == NULL)
	//	return (NULL);
	if (stash[fd] != NULL)
		clean_stash(&stash[fd]);
	if (!found_new_line(stash[fd]))
		read_n_stock(fd, &stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	if (stash[fd][0] != '\0')
		extract_line(&stash[fd] ,&line);
	if (stash[fd][0] == '\0')
	{
		free(stash[fd]);
		return (NULL);
	}
	return (line);
}