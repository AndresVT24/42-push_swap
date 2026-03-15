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

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_find_min_index(t_stack *lst)
{
	int	i, min_i;
	t_stack *actual;
	t_stack *min_node;
	
	if (!lst)
		return (-1);
	i = 0;
	min_i = 0;
	actual = lst;
	min_node = lst;
	
	while(actual != NULL)
	{
		if (actual->num < min_node->num)
		{
			
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
		{
			ft_ra(lst, bench);
		}
	}
	else
	{
		while(minIndex++ < size)
		{
			ft_rra(lst, bench);
		}
	}
}
