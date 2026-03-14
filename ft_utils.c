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

t_list *ft_find_min(t_list *lst)
{
	int	min;
	struct t_list actual;
	
	acual = lst;
	min = actual->num;
	while(lst != NULL)
	{
		if (lst->num < min)
		{
			actual = lst;
			min = actual->num;
		}
		lst = lst->next;
	}
	
	return actual;
}


