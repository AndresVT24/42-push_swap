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

void	simple(t_stack **lst, t_stack **lstTmp , t_inst_count *bench)
{
	int	flag;
	
	if(!lst || !*lst)
		return;
	while(*lst != NULL)
	{
		ft_move_min_to_top(lst, bench);
		ft_push(lstTmp, lst);
		write(1,"pb\n",3);
		bench->pb++;
	}
	
	while(*lstTmp != NULL)
	{
		ft_push(lst, lstTmp);
		write(1, "pa\n", 3);
		bench->pa++;
	}
}

int *bucket_sort(int *listNum, int lenList)
{
	int	i;
	
	return 1;
	
}
