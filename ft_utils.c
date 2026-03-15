/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 11:48:35 by ervillca          #+#    #+#             */
/*   Updated: 2026/03/14 11:48:37 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_find_min_index(t_stack *lst)
{
	int	i, min_i, min_value;
	
	if (!lst)
		return (-1);
	i = 0;
	min_i = 0;
	min_value = lst->num;
	
	while(lst)
	{
		if (lst->num < min_value)
		{
			
			min_value = lst->num;
			min_i = i;
		}
		lst = lst->next;
		i++;
	}
	
	return min_i;
}

void	ft_move_min_to_top(t_stack **lst, t_inst_count *bench)
{
	int	minIndex;
	int	size;
	
	size = ft_lstsize(*lst);
	minIndex = ft_find_min_index(*lst);
	
	if(minIndex <= size/2)
	{
		while(minIndex-- > 0)
			ft_rotate(lst, bench, 'a');
	}
	else
	{
		while(minIndex++ < size)
			ft_rotate_reverse(lst, bench, 'a');
	}
}

int	*ft_sort_array(int *lst, int len)
{
	int	i;
	int	j;
	int	tmp;
	
	i = 0;
	
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (lst[i] < lst[j])
			{
				tmp = lst[i];
				lst[i] = lst[j];
				lst[j] = tmp;
			}
			j++;	
		}
		i++;
	}
	return (lst);
}

void	ft_addIndex2stack(t_stack *nodos, int *list, int len)
{
	int	i;
	int	j;
	
	if (!nodos || !list)
		return;
		
	i = 0;
	while (i < len && nodos != NULL)
	{
		j = 0;
		while (j < len)
		{
			if (list[j] == nodos->num)
			{
				nodos->index = j;
			}
			j++;
		}
		nodos = nodos->next;
		i++;
	}
}
