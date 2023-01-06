/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:50:59 by rdoukali          #+#    #+#             */
/*   Updated: 2022/07/26 21:20:57 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*str_extr_norm(char *str, int n, int tmp, int start)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = malloc(sizeof(char) * 90);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ':')
		{
			tmp++;
			start = i + 1;
		}
		while (tmp == n && str[start] != ':' && str[start])
		{
			ptr[j] = str[start];
			start++;
			j++;
		}
		ptr[j] = '\0';
		i++;
	}
	return (ptr);
}

char	*str_extr(char *str, int n)
{
	int		tmp;
	int		start;
	char	*ptr;

	tmp = 1;
	if (n > 6 || n <= 0)
		return (NULL);
	start = 0;
	ptr = str_extr_norm(str, n, tmp, start);
	return (ptr);
}

char	*ffss_norm(char **file, int i, int j)
{
	int		k;
	char	*ptr;

	ptr = malloc(sizeof(char) * ft_strlen2(&file[i][j]) + 1);
	k = 0;
	while (file[i][j])
	{
		ptr[k] = file[i][j];
		j++;
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}

char	*ft_file_search_str(char **file, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	k = 0;
	j = 0;
	while (file[i][j])
	{
		j = 0;
		k = 0;
		while (file[i][j] == str[j])
		{
			j++;
			k++;
		}
		if (k == 5)
		{
			ptr = ffss_norm(file, i, j);
			return (ptr);
		}
		i++;
	}
	return (0);
}

char	*ft_path(char *path, char *cmd)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	while (str_extr(path, i) != NULL)
	{
		str = ft_strjoin(str_extr(path, i), "/");
		str = ft_strjoin(str, cmd);
		if (access(str, F_OK | X_OK) == 0)
			return (str);
		i++;
	}
	return (NULL);
}
