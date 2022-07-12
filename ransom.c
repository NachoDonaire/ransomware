#include "ransomlib.h"

void	outside_directory()
{
	int	fd_pwd;
	int	i;
	char	*bufete;
	int	count;

	system("pwd > piwd");
	fd_pwd = open("piwd", O_RDONLY);
	bufete = get_next_line(fd_pwd);
	i = 0;
	while (bufete[i])
	{
		if (bufete[i] == '/')
			count++;
		i++;
	}
	while (count > 2)
	{
		system("cd ..");
		count--;
	}
}

void	fr_every_single_directory()
{
	int	fd_ls_2;
	char	*fete;
	int	i;
	char	**com;
	char	*sol;

	system("ls -l> first_ls");
	i = 0;
	fd_ls_2 = open("first_ls", O_RDONLY);
	fete = get_next_line(fd_ls_2);
	while (fete)
	{
		if (fete[0] == 'd')
		{
			while (fete[i] != '\n')
				i++;
			fete[i] = '\0';
			com = ft_split(fete, ' ');
			i = 0;
			while (i <= 7)
				free(com[i++]);
			sol = ft_strjoin("cd ", com[i]);
			sol = ft_strjoin(sol, " && pwd");
			system(sol);
		}
		fete = get_next_line(fd_ls_2);
	}

}
