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

void	ft_simple(t_stack **lst, t_stack **lstTmp , t_inst_count *bench)
{
	if(!lst || !*lst)
		return;
	while(*lst != NULL)
	{
		ft_move_min_to_top(lst, bench);
		ft_push(lstTmp, lst, bench, 'b');
	}
	
	while(*lstTmp != NULL)
	{
		ft_push(lst, lstTmp, bench, 'a');
	}
}

void intermedio(int *listNum, int lenList)
{	
	listNum = listNum; // To avoid unused parameter warning
	lenList = lenList; // To avoid unused parameter warning
	int	*i;
	i = malloc(sizeof(int) * lenList);
	if (!i)
		return (NULL);

	return (i);	
}
