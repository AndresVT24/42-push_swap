#include "push_swap.h"

void	ft_rotate(t_stack **lst, t_inst_count *bench, char opt)
{
	t_stack *first;
	t_stack *last;
	
	if(!lst || !*lst || !(*lst)->next)
		return;
	
	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	if (opt == 'a')
	{
		write(1,"ra\n",3);
		bench->ra++;
	}
	if (opt == 'b')
	{
		write(1,"rb\n",3);
		bench->rb++;
	}
}

void	ft_rotate_reverse(t_stack **lst, t_inst_count *bench, char opt)
{
	t_stack *prev;
	t_stack *last;
	
	if(!lst || !*lst || !(*lst)->next)
		return;
	prev = NULL;
	last = *lst;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
	if (opt == 'a')
	{
		write(1,"rra\n",4);
		bench->rra++;
	}
	if (opt == 'b')
	{
		write(1,"rrb\n",4);
		bench->rrb++;
	}
}

void	ft_push(t_stack **dest, t_stack **src, t_inst_count *bench, char opt)
{
	t_stack *tmp;
	
	if(!src || !*src)
	{
		return;
	}
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (opt == 'a')
	{
		write(1, "pa\n", 3);
		bench->pa++;
	}
	else
	{
		write(1, "pb\n",3);
		bench->pb++;
	}
}
