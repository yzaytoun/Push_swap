/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:13:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/11 09:55:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//ANCHOR - Stack Size
int	ft_stacksize(t_stack *stac)
{
	t_stack	*top;
	int		counter;

	counter = 0;
	if (ft_isempty(stac) == TRUE)
		return (0);
	top = stac;
	while (top != NULL)
	{
		counter++;
		top = top->next;
	}
	return (counter);
}

//ANCHOR - GET Position from value
int	ft_getpos(t_stack *stac, int num)
{
	t_stack	*top;
	int		pos;

	pos = 0;
	if (stac == NULL)
		return (0);
	top = stac;
	while (top != NULL)
	{
		if (top->num == num)
			break ;
		++pos;
		top = top->next;
	}
	return (pos);
}

//ANCHOR - Max value
int	ft_getmax(t_stack *stac)
{
	t_stack	*top;
	int		max;

	top = stac;
	max = stac->num;
	while (top != NULL)
	{
		if (top->num > max)
			max = top->num;
		top = top->next;
	}
	return (max);
}

//ANCHOR - Min Value
int	ft_getmin(t_stack *stac)
{
	t_stack	*top;
	int		min;

	top = stac;
	min = stac->num;
	while (top != NULL)
	{
		if (top->num < min)
			min = top->num;
		top = top->next;
	}
	return (min);
}

//ANCHOR - Get node
t_stack	*ft_getnode(t_stack *stac, int pos)
{
	t_stack	*top;
	int		count;

	count = 0;
	if (ft_isempty(stac) == TRUE)
		return (NULL);
	top = stac;
	while (top != NULL)
	{
		if (count == pos)
			break ;
		count++;
		top = top->next;
	}
	return (top);
}
