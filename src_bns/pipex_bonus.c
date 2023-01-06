/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:58:48 by rdoukali          #+#    #+#             */
/*   Updated: 2022/07/26 21:43:08 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	openfile(char *file, int perm)
{
	int	res;

	if (perm == 0)
	{
		res = open(file, O_RDONLY, 0777);
		if (access(file, F_OK | R_OK) != 0)
			ft_error(1);
	}
	if (perm == 1)
		res = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (perm == 2)
		res = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (res == -1)
		exit(0);
	return (res);
}

void	child_proc(int fd[2], char **argv, char **env, t_parm *parm)
{
	char	*path;
	char	**cmds1;

	cmds1 = ft_split(argv[parm->cmd_index], ' ');
	close(fd[0]);
	dup2(fd[1], 1);
	path = ft_path(ft_file_search_str(env, "PATH="), cmds1[0]);
	if (path == NULL)
		ft_error(2);
	if (execve(path, cmds1, env) == -1)
		ft_error(2);
	close(fd[1]);
	parm->cmd_index++;
	free_path(cmds1);
	free(path);
}

void	main_proc(int fd[2], char **argv, char **env, t_parm *parm)
{
	int		fdout;
	char	*path2;
	char	**cmds2;

	fdout = openfile(argv[parm->ac - 1], 1);
	cmds2 = ft_split(argv[parm->cmd_index], ' ');
	dup2(fdout, STDOUT_FILENO);
	close(fd[1]);
	dup2(fd[0], 0);
	path2 = ft_path(ft_file_search_str(env, "PATH="), cmds2[0]);
	if (path2 == NULL)
		ft_error(2);
	if (execve(path2, cmds2, env) == -1)
		ft_error(2);
	close(fd[0]);
	parm->cmd_index++;
	close(fdout);
	free_path(cmds2);
	free(path2);
}

void	all_proc(t_parm *parm)
{
	int	fdin;
	int	fd[2];
	int	pid1;

	if (parm->cmd_index > 3)
		fdin = openfile(parm->av[parm->ac], 0);
	else
		fdin = openfile(parm->av[1], 0);
	pipe(fd);
	pid1 = fork();
	dup2(fdin, STDIN_FILENO);
	if (pid1 == 0)
		child_proc(fd, parm->av, parm->envr, parm);
	else
	{
		main_proc(fd, parm->av, parm->envr, parm);
		wait(NULL);
	}
	close(fd[0]);
	close(fd[1]);
	close(fdin);
}

int	main(int argc, char **argv, char **env)
{
	t_parm	parm;

	if (argc > 5)
		return (0);
	parm.ac = argc;
	parm.av = argv;
	parm.envr = env;
	parm.cmd_index = 2;
	while (parm.cmd_index < argc)
	{
		all_proc(&parm);
	}
	return (0);
}
