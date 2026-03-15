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

typedef struct s_stack
{
	int			num;
	struct t_stack	*next;
	
} t_stack;

typedef struct s_flags
{
	int	disorder;
	int	adaptive;
	int	simple;
	int	medium;
	int	complex;
	int	bench;
}	t_flags;

typedef struct s_inst_count
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int total;
} t_inst_count;

int	ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);

void	ft_bench(t_flags flags, t_inst_count ic, t_stack *node, int fd);
char	*ft_itoa(int n);
long	itol(char *str);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);
int		ft_compute_disorder(t_stack *a);
void	ft_putstr_ps(char	*str, int fd);
int		error(void);
int 	ft_strcmp(char *str1, char *str2);
void	ft_putstr_ps(char	*str, int fd);
t_stack	*ft_stacknew(int num);

void	ft_ra(t_stack **lst, t_inst_count *bench);
void	ft_rra(t_stack **lst, t_inst_count *bench);
void	ft_push(t_stack **dest, t_stack **src);

int	ft_find_min_index(t_stack *lst);
void	ft_move_min_to_top(t_stack **lst, t_inst_count *bench);

void	simple(t_stack **lst, t_stack **lstTmp , t_inst_count *bench);
#endif
