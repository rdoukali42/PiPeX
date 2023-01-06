/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdoukali <rdoukali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:09:56 by rdoukali          #+#    #+#             */
/*   Updated: 2022/07/25 19:49:00 by rdoukali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(int n)
{
	if (n == 1)
	{
		ft_putstr_fd("No file or Directory", 2);
		exit(0);
	}
	else if (n == 2)
	{
		ft_putstr_fd("command not found", 2);
		exit(1);
	}
}
