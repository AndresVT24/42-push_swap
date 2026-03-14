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

int	ft_lstsize(t_list *lst)
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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_find_min_index(t_list *lst)
{
	int	i, min_i;
	t_list *actual;
	
	if (lst == NULL)
	{
		return (NULL);
	}
	i = 0;
	min_i = 0;
	actual = lst;
	while(lst != NULL)
	{
		if (lst->num < actual->num)
		{
			actual = lst;
			min_i = i;
		}
		lst = lst->next;
		i++;
	}
	
	return min_i;
}

void	ft_move_min_to_top(t_list **lst)
{
	int	minIndex, size;
	
	size = ft_lstsize(*lst)
	minIndex = ft_find_min_index(*lst);
	
	if(minIndex <= size/2)
	{
		while(minIndex-- > 0)
		{
			ra(lst);
		}
	}
	else
	{
		while(minIndex++ < size)
		{
			rra(lst);
		}
	}
}

void	ft_ra(t_list *lst)
{
	t_list *first;
	t_list *last;
	
	if(!lst || !*lst || !(*lst)->next)
	{
		return;
	}
	
	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = firts;
	write(1,"ra\n",3);
}

void	ft_rra(t_list *lst)
{
	t_list *first;
	t_list *last;
	
	if(!lst || !*lst || !(*lst)->next)
	{
		return;
	}
	
	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = firts;
	write(1,"ra\n",3);
}
