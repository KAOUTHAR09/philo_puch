/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:29:29 by kkouaz            #+#    #+#             */
/*   Updated: 2023/07/17 10:58:36 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int			*args;
	t_public	*public;

	if (ac != 5 && ac != 6)
	{
		printf("%sError : ", RED);
		printf("%sinvalid arguments !!\n", CYAN);
		return (0);
	}
	args = ft_parse(ac, av);
	if (!args)
	{
		printf("%sError : ", RED);
		printf("%sinvalid arguments !!\n", CYAN);
		return (0);
	}
	public = ft_init(args, ac);
	free(args);
	return (0);
}
