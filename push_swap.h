/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 12:32:44 by ervillca          #+#    #+#             */
/*   Updated: 2026/03/14 12:32:47 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_list
{
	int			num;
	int			size;
	struct s_list	*next;
	struct s_list	*top;
	struct s_list	*bottom;
	
} t_list;

int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif
