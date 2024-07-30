/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:25:52 by pmorello          #+#    #+#             */
/*   Updated: 2024/07/30 18:33:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
	int i;
	int j;
	char *dest;

	j = 0;
	while (s[j] != '\0')
		j++;
	dest = (char *)malloc(sizeof(char) * (j + 1));
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == s2)
		return (0);
	else if (s1< s2)
		return (-1);
	else if (s1 > s2)
		return (1);
}

void	ft_itoa(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_itoa(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_write_itoa(unsigned int n)
{
	write(1, "Number of steps: ", 17);
	ft_itoa(n);
	write(1, "\n", 1);
}