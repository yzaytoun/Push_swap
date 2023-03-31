/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:23:57 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/31 17:58:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
//SECTION AUX
//ANCHOR - Delete Stack
void	ft_deletestack(t_list **top)
{
	t_list	*node;

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
int	ft_getlast(t_list *top)
{
	t_list	*node;

	if (ft_isempty(top))
		return (0);
	node = top;
	if (node->next == NULL)
		return ((int)node->content);
	else
		while (node->next != NULL)
			node = node->next;
	return ((int)node->content);
}

//ANCHOR - INITIATE STACK
void	ft_initiatestack(t_list **a, char **av)
{
	int		i;
	int		x;
	char	**arg;

	x = 0;
	ft_avtype(av, &arg, &i);
	while (i >= 0)
	{
		if (ft_isdigit_str(arg[i]) == TRUE)
			x = ft_atoi(arg[i]);
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
		ft_push(a, (void *)(uintptr_t)x);
		i--;
	}
	ft_free_strarr(arg);
}

//ANCHOR - CHECK DUPLICATES
int	ft_checkduplicates(t_list *a)
{
	t_list		*top;
	t_list		*index;
	int			count;

	if (ft_isempty(a))
		return (0);
	top = a;
	index = NULL;
	count = 0;
	while (top->next != NULL)
	{
		index = top->next;
		while (index != NULL)
		{
			if ((int)index->content == (int)top->content)
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
void	ft_free(t_stack **a, t_stack **b, t_list *sorted)
{
	ft_deletestack(&(*a)->stack);
	ft_deletestack(&(*b)->stack);
	ft_deletestack(&sorted);
	free(*a);
	free(*b);
}
//!SECTION
