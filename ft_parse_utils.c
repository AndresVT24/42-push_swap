/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:54:04 by fliraud-          #+#    #+#             */
/*   Updated: 2026/03/15 12:54:07 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_digitcount(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_num2str(int num, char *str, int i)
{
	char	c;

	if (num == -2147483648)
	{
		str = ft_strcpy(str, "-2147483648");
		return ;
	}
	if (num < 0)
	{
		str[0] = '-' ;
		num = -num;
	}
	if (num >= 10)
	{
		ft_num2str(num / 10, str, i - 1);
	}
	c = num % 10 + '0';
	str[i] = c;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_digitcount(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_num2str(n, str, len - 1);
	str[len] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
    int	len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}
