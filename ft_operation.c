#include "push_swap.h"

void	ft_ra(t_stack **lst, t_inst_count *bench)
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
	write(1,"ra\n",3);
	bench->ra++;
}

void	ft_rra(t_stack **lst, t_inst_count *bench)
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
	write(1,"rra\n",4);
	bench->rra++;
}

void	ft_push(t_stack **dest, t_stack **src)
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
}
