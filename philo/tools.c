/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:23:56 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/25 16:02:45 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int	ft_atoi(char *str)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] != 0 && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
				i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
		res = res * 10 + (str[i++] - 48);
	if (sign == 1 && res > 2147483647)
		return (error("too large number !!"));
	if (sign == -1 && res > 2147483648)
		return (error("too large number !!"));
	return (res * sign);
}

int	error(char *s)
{
	int	i;

	i = 0;
	printf("%sError : ", RED);
	printf("%s%s", CYAN, s);
	return (-1);
}

int	ft_strlen_a(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*stj;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen_a(s1);
	stj = malloc((ft_strlen_a(s1) + ft_strlen_a(s2) + 1));
	if (!stj)
		return (0);
	while (s1 && s1[i])
	{
		stj[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		stj[i + j] = s2[i];
		i++;
	}
	free(s1);
	stj[i + j] = '\0';
	return (stj);
}
