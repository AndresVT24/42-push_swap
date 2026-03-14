/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 11:16:18 by ervillca          #+#    #+#             */
/*   Updated: 2026/03/14 12:19:52 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->top = new;
	new->bottom = new;
	return (new);
}

void	ft_putstr_ps(char	*str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) == -1)
			return ;
		i++;
	}
}

int ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

// 0 FLAG, 1 VALID NOT FLAG, 2 NOT VALID, 3 CONFLICTING FLAGS
// ./a.out --bench --bench  → OK
// ./a.out --simple --medium → ERROR
int	check_flags(char *flag, t_flags *flags)
{
	int	i;

	i = 0;
	if (flag[i] && flag[i] == '-')
	{
		if (flag[i+1] && flag[i+1] == '-')
		{
			if (ft_strcmp(flag, "--bench") == 0)
				flags->bench = 1;
			else if (ft_strcmp(flag, "--adaptive") == 0)
				flags->adaptive = 1;					
			else if (ft_strcmp(flag, "--simple") == 0)
				flags->simple = 1;
			else if (ft_strcmp(flag, "--medium") == 0)
				flags->medium = 1;
			else if (ft_strcmp(flag, "--complex") == 0)
				flags->complex = 1;
			else
				return (2);
			if  (flags->simple + flags->medium + flags->complex == 1)
				flags->adaptive = 0;
			else if (flags->simple + flags->medium + flags->complex > 1)
				return (3);
			return (0);
		}
		return (2);
	}
	return (1);
}

void	print_flags(t_flags *flags)
{
	ft_putstr_ps("Flags:\n", 1);
	ft_putstr_ps("Adaptive: ", 1);
	ft_putstr_ps(flags->adaptive ? "ON\n" : "OFF\n", 1);
	ft_putstr_ps("Simple: ", 1);
	ft_putstr_ps(flags->simple ? "ON\n" : "OFF\n", 1);
	ft_putstr_ps("Medium: ", 1);
	ft_putstr_ps(flags->medium ? "ON\n" : "OFF\n", 1);
	ft_putstr_ps("Complex: ", 1);
	ft_putstr_ps(flags->complex ? "ON\n" : "OFF\n", 1);
	ft_putstr_ps("Bench: ", 1);
	ft_putstr_ps(flags->bench ? "ON\n" : "OFF\n", 1);
}

long	itol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	error(void)
{
	ft_putstr_ps("Error\n", 1);
	return (1);
}

int compute_disorder(t_stack *a)
{
	float	res;
	int	mistakes;
	int	total_pairs;
	t_stack	*current;
	t_stack	*compare;

	mistakes = 0;
	total_pairs = 0;
	current = a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->num > compare->num)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	res = (float)mistakes / total_pairs;
	res *= 10000;
	return ((int)res);
}

int	main(int argc, char **argv)
{
	int	i;
	int	res;
	int	disorder1;
	int	disorder2;
	t_stack	*node = NULL;

	i = 1;
	res = 0;
	t_flags flags = {1, 1, 0, 0, 0, 0};
	while (i < argc)
	{
		if (res == 0)
		{
			res = check_flags(argv[i], &flags);
			if (res == 0)
				i++;
			else if (res == 2 || res == 3)
				return (error());
		}
		else
		{
			node = ft_stacknew((int)itol(argv[i]));
			if (!node)
				return (error());
			if (node->num < -2147483648 || node->num > 2147483647)
				return (error());
			if (node->num == 0 && *argv[i] != '0') // Not a number
				return (error());			
			i++;
		}
	}
	if (flags.bench)
	{
		/*El índice de desorden ( % con dos decimales).
		◦ El nombre de la estrategia usada y su clase de complejidad teórica.
		◦ El número total de operaciones empleadas.
		◦ El número de operaciones de cada tipo (sa, sb, ss, pa, pb, ra, rb, rr, rra,
		rrb, rrr) empleadas durante la ordenación.
		*/
		flags.disorder = compute_disorder(node);
		disorder1 = flags.disorder / 100;
		disorder2 = flags.disorder % 100;
		ft_printf("[bench] disorder: %d.%d%%\n", disorder1, disorder2);
	}
	/*
	if (flags.adaptive)
	{
		if (disorder < 0.2)
			simple();
		else if (disorder < 0.5)
			medium();
		else
			complex();
	}
	else if (flags.simple)
		simple();
	else if (flags.medium)
		medium();
	else if (flags.complex)
		complex();
	print_flags(&flags);
	return (0);
	*/
}
