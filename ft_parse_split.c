/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:24:35 by fliraud-          #+#    #+#             */
/*   Updated: 2026/03/15 15:24:38 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strc(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	strc;

	i = 0;
	count = 0;
	strc = 0;
	while (s[i])
	{
		if (s[i] == c && count > 0)
		{
			strc++;
			count = 0;
		}
		else if (s[i] != c)
			count++;
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		strc++;
	return (strc);
}

static int	ft_malloc1tab(char **tab, size_t *j, size_t *count)
{
	tab[(*j)] = malloc((*count) + 1);
	if (!tab[(*j)])
	{
		while ((*j) > 0)
		{
			(*j)--;
			free(tab[(*j)]);
		}
		free(tab);
		return (1);
	}
	tab[(*j)][(*count)] = '\0';
	(*count) = 0;
	(*j)++;
	return (0);
}

static int	ft_alloc_words(char **tab, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && count > 0)
		{
			if (ft_malloc1tab(tab, &j, &count) == 1)
				return (1);
		}
		else if (s[i] != c)
			count++;
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		if (ft_malloc1tab(tab, &j, &count) == 1)
			return (1);
	return (0);
}

static void	ft_splitcpy(char **strptr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c && k > 0)
		{
			j++;
			k = 0;
		}
		else
		{
			if (s[i] != c)
				strptr[j][k++] = s[i];
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strptr;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strc(s, c);
	strptr = malloc(sizeof(char *) * (n + 1));
	if (!strptr)
		return (NULL);
	strptr[n] = NULL;
	if (ft_alloc_words(strptr, s, c) == 1)
		return (NULL);
	ft_splitcpy(strptr, s, c);
	return (strptr);
}
