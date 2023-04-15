/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:32:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/15 13:10:14 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION UTILS 2
//ANCHOR - Digit in String
int	ft_isdigit_str(char	*str)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (-1);
	else if (*str == '-')
		++i;
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

// ANCHOR - IS sorted
int	ft_issorted(t_list *top, int order)
{
	t_list	*node;

	if (ft_isempty(top) || ft_isempty(top->next))
		return (TRUE);
	node = top;
	if (order == ASC)
	{
		return ((int)node->content < (int)node->next->content
			&& ft_issorted(node->next, ASC));
	}
	else if (order == DESC)
	{
		return ((int)node->content > (int)node->next->content
			&& ft_issorted(node->next, DESC));
	}
	return (TRUE);
}

//ANCHOR - GET NEXT
int	ft_getnext(t_list *lst, int direction)
{
	t_list	*top;

	if (ft_isempty(lst) || ft_isempty(lst->next))
		return (0);
	top = ft_copylist(lst);
	if (direction == FORWARD)
		return ((int)top->next->content);
	else if (direction == BACKWARD)
	{
		ft_reverse_stack(&top);
		return ((int)top->next->content);
	}
	return (0);
}
//!SECTION
