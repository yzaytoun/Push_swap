/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:32:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/21 19:20:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION UTILS 2
//ANCHOR - Digit in String
int	ft_isdigit_str(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != TRUE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

//ANCHOR - Reverse stack
void	ft_reverse_stack(t_list **top)
{
	t_list	*prev;
	t_list	*next;
	t_list	*curr;

	curr = (*top);
	prev = NULL;
	next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	(*top) = prev;
}

//ANCHOR - MAX
int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

// ANCHOR - IS sorted
int	ft_issorted(t_list *top, int order)
{
	t_list	*node;

	if (ft_isempty(top))
		return (0);
	node = top;
	if (order == ASC)
	{
		while (node->next != NULL)
		{
			if (node->content > node->next->content)
				return (FALSE);
			node = node->next;
		}
	}
	else if (order == DESC)
	{
		while (node->next != NULL)
		{
			if (node->content > node->next->content)
				return (FALSE);
			node = node->next;
		}
	}
	return (TRUE);
}
//!SECTION
