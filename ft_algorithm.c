/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 11:29:18 by ervillca          #+#    #+#             */
/*   Updated: 2026/03/14 11:49:30 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int *exchange_sort(t_list *head)
{
	t_list *lastNode;
	t_list *stackB;
	
	lastNode = ft_lstlast(head);
	while (i < lenList)
	{
		while(j < lenList)
		{
			if (listNum[i] < listNum[j])
			{
				tmp = listNum[i];
				listNum[i] = listNum[j];
				listNum[j] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return listNum;
}

int *bucket_sort(int *listNum, int lenList)
{
	int	i;
	
	return 1;
	
}
