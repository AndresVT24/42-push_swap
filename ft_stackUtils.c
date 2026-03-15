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

int *ft_stack2array(t_stack *lst, int len)
{
	int	*listInt;
	int	i;
	
	listInt = (int *)malloc(sizeof(int) * len);
	if (!listInt)
		return (NULL);
	i = 0;
	while(i < len && lst != NULL)
	{
		listInt[i] = lst->num;
		lst = lst->next;
		i++;
	}
	return listInt;
}
