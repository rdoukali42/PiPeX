/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:48:27 by rdoukali          #+#    #+#             */
/*   Updated: 2022/07/25 20:32:51 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

///  ///////////////////////////////  ///
///  ///          STACK          ///  ///
///  ///////////////////////////////  ///
typedef struct s_parm
{
	int		ac;
	int		cmd_index;
	char	**av;
	char	**envr;
}			t_parm;
///  ///////////////////////////////  ///
///  ///          PIPEX          ///  ///
///  ///////////////////////////////  ///
void	ft_error(int n);
///  ///////////////////////////////  ///
///  ///          PATHS          ///  ///
///  ///////////////////////////////  ///
char	*ft_path(char *path, char *cmd);
char	*ft_file_search_str(char **file, char *str);
char	*str_extr(char *str, int n);
///  ///////////////////////////////  ///
///  ///          UTILS          ///  ///
///  ///////////////////////////////  ///
size_t	ft_strlen(const char *str);
int		ft_strlen2(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const*s, char c);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
void	free_path(char **path);
#endif