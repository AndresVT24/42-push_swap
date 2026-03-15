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
		if (flag[i+1] && (flag[i+1] <'0' || flag[i+1] > '9'))
			return (2);
	}
	return (1);
}

int ft_check_duplicates(t_stack *a)
{
    t_stack *current;
    t_stack *compare;

    current = a;
    while (current != NULL)
    {
        compare = current->next;
        while (compare != NULL)
        {
            if (current->num == compare->num)
                return (1);
            compare = compare->next;
        }
        current = current->next;
    }
    return (0);
}

void	ft_medium(t_stack *a, t_stack *b, t_inst_count *ic)
{
	write(1, "Executing medium sorting algorithm...\n", 34);
	a = a; // To avoid unused parameter warning
	b = b; // To avoid unused parameter warning
	ic = ic; // To avoid unused parameter warning
}

void	ft_complex(t_stack *a, t_stack *b, t_inst_count *ic)
{
	write(1, "Executing complex sorting algorithm...\n", 34);
	a = a; // To avoid unused parameter warning
	b = b; // To avoid unused parameter warning
	ic = ic; // To avoid unused parameter warning
}

int	ft_valid_input(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (input[i] == '\0')
		return (0);
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstack(t_stack *stack)
{
	while (stack)
	{
		ft_putstr_ps(ft_itoa(stack->num), 1);
		ft_putstr_ps("\n", 1);
		stack = stack->next;
	}
	ft_putstr_ps("\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int	res;
	t_inst_count ic = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	**split;

	i = 1;
	res = 0;
	t_flags flags = {0, 1, 0, 0, 0, 0};
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
			split = ft_split(argv[i], ' ');
			if (!split || !split[0])
				return (error());
			j = 0;
			while (split[j])
			{
				if (!ft_valid_input(split[j]))
					return (error());
				long num = itol(split[j]);
				if (num < -2147483648 || num > 2147483647)
					return (error());
				t_stack *new_node = ft_stacknew((int)num);
				if (!new_node)
					return (error());
				if (!a)
					a = new_node;
				else
				{
					t_stack *last = ft_lstlast(a);
					last->next = new_node;
				}			
				j++;
			}
			i++;
		}
	}
	if (ft_check_duplicates(a))
		return (error());
	flags.disorder = ft_compute_disorder(a);
	if (flags.adaptive)
	{
		if (flags.disorder < 200)
			ft_simple(&a, &b, &ic);
		else if (flags.disorder < 500)
			ft_medium(a, b, &ic);
		else
			ft_complex(a, b, &ic);
	}
	else if (flags.simple)
		ft_simple(&a, &b, &ic);
	else if (flags.medium)
		ft_medium(a, b, &ic);
	else if (flags.complex)
		ft_complex(a, b, &ic);
	if (flags.bench)
		ft_bench(flags, ic, 2);
	ft_putstack(a);
	return (0);
}