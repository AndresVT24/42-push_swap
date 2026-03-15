/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:38:35 by fliraud-          #+#    #+#             */
/*   Updated: 2026/03/15 12:39:00 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_ic2(t_inst_count *ic, int fd)
{
	ft_putstr_ps("[bench] ra: ", fd);
	ft_putstr_ps(ft_itoa(ic->ra), fd);
	ft_putstr_ps(", rb: ", fd);
	ft_putstr_ps(ft_itoa(ic->rb), fd);
	ft_putstr_ps(", rr: ", fd);
	ft_putstr_ps(ft_itoa(ic->rr), fd);
	ft_putstr_ps(", rra: ", fd);
	ft_putstr_ps(ft_itoa(ic->rra), fd);
	ft_putstr_ps(", rrb: ", fd);
	ft_putstr_ps(ft_itoa(ic->rrb), fd);
	ft_putstr_ps(", rrr: ", fd);
	ft_putstr_ps(ft_itoa(ic->rrr), fd);
	ft_putstr_ps("\n", fd);
}

void	ft_print_ic1(t_inst_count *ic, int fd)
{
	ft_putstr_ps("[bench] sa: ", fd);
	ft_putstr_ps(ft_itoa(ic->sa), fd);
	ft_putstr_ps(", sb: ", fd);
	ft_putstr_ps(ft_itoa(ic->sb), fd);
	ft_putstr_ps(", ss: ", fd);
	ft_putstr_ps(ft_itoa(ic->ss), fd);
	ft_putstr_ps(", pa: ", fd);
	ft_putstr_ps(ft_itoa(ic->pa), fd);
	ft_putstr_ps(", pb: ", fd);
	ft_putstr_ps(ft_itoa(ic->pb), fd);
	ft_putstr_ps("\n", fd);
    ft_print_ic2(ic, fd);
}

void	ft_printstrat(t_flags *flags, int fd)
{
	if (flags->simple)
		ft_putstr_ps("[bench] strategy: Simple / (O(n^2))\n", fd);
	else if (flags->medium)
		ft_putstr_ps("[bench] strategy: Medium / (O(n √ n))\n", fd);
	else if (flags->complex)
		ft_putstr_ps("[bench] strategy: Complex / (O(n log n))\n", fd);
	else if (flags->adaptive)
    {
		if (flags->disorder < 200)
            ft_putstr_ps("[bench] strategy: Adaptive / (O(n^2))\n", fd);
        else if (flags->disorder < 500)
            ft_putstr_ps("[bench] strategy: Adaptive / (O(n √ n))\n", fd);
        else
            ft_putstr_ps("[bench] strategy: Adaptive / (O(n log n))\n", fd);
    }
	else
		ft_putstr_ps("[bench] strategy: ERROR no strategy selected\n", fd);
}

int ft_compute_disorder(t_stack *a)
{
    int     mistakes;
    int     total_pairs;
    float   res;
    t_stack *current;
    t_stack *compare;

    mistakes = 0;
    total_pairs = 0;
    current = a;
    while (current != NULL)
    {
        compare = current->next;
        while (compare != NULL)
        {
            total_pairs++;
            if (current->num > compare->num)
                mistakes++;
            compare = compare->next;
        }
        current = current->next;
    }
    if (total_pairs == 0)
        return (0);
    res = (float)mistakes / (float)total_pairs;
    res = res * 10000.0f;
    return ((int)res);
}

void	ft_bench(t_flags flags, t_inst_count ic, int fd)
{
	int disorder1;
	int disorder2;
	char *str_tmp;
	disorder1 = flags.disorder / 100;
	disorder2 = flags.disorder % 100;
	ft_putstr_ps("[bench] disorder: ", fd);
	str_tmp = ft_itoa(disorder1);
    ft_putstr_ps(str_tmp, fd);
    free(str_tmp);
	ft_putstr_ps(".", fd);
	if (disorder2 < 10)
        ft_putstr_ps("0", fd);
	str_tmp = ft_itoa(disorder2);
    ft_putstr_ps(str_tmp, fd);
    free(str_tmp);	ft_putstr_ps("%\n", fd);
	ft_printstrat(&flags, fd);
	ft_putstr_ps("[bench] total operations: ", fd);
	ft_putstr_ps(ft_itoa(ic.total), fd);
	ft_putstr_ps("\n", fd);
	ft_print_ic1(&ic, fd);
}
