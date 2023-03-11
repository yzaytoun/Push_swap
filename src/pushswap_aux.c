/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:23:57 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/11 11:14:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//ANCHOR - Delete Stack
void	ft_deletestack(t_stack **top)
{
	t_stack	*node;

	if (ft_isempty(*top))
		return ;
	node = *top;
	while (node != NULL)
	{
		(*top) = (*top)->next;
		free(node);
		node = (*top);
	}
	free(*top);
}

//ANCHOR - Get last 
int	ft_getlast(t_stack *top)
{
	t_stack	*node;

	node = top;
	if (node->next == NULL)
		return (node->num);
	else
		while (node->next != NULL)
			node = node->next;
	return (node->num);
}

//ANCHOR - INITIATE STACK
void	ft_initiatestack(t_stack **a, char **av, int ac)
{
	int	i;
	int	x;

	x = 0;
	i = ac - 1;
	while (i > 0)
	{
		if (ft_isdigit_str(av[i]) == TRUE)
			x = ft_atoi(av[i]);
		else
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		if (x > INT_MAX || x < INT_MIN)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		ft_push(a, x);
		i--;
	}
}

//ANCHOR - CHECK DUPLICATES
int	ft_checkduplicates(t_stack *a)
{
	t_stack	*top;
	t_stack	*index;
	int		count;

	top = a;
	index = NULL;
	count = 0;
	while (top->next != NULL)
	{
		index = top->next;
		while (index != NULL)
		{
			if (index->num == top->num)
			{
				++count;
				break ;
			}
			index = index->next;
		}
		top = top->next;
	}
	return (count);
}

//ANCHOR - Free
void	ft_free(t_stack **a, t_stack **b)
{
	ft_deletestack(a);
	ft_deletestack(b);
}
