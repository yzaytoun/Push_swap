/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:13:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/16 20:23:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//ANCHOR - Stack Size
int	ft_stacksize(t_pushswap *stac)
{
	t_pushswap	*top;
	int			counter;

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
int	ft_getpos(t_pushswap *stac, int num)
{
	t_pushswap	*top;
	int			pos;

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
int	ft_getmax(t_pushswap *stac)
{
	t_pushswap	*top;
	int			max;

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
int	ft_getmin(t_pushswap *stac)
{
	t_pushswap	*top;
	int			min;

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
t_pushswap	*ft_getnode(t_pushswap *stac, int pos)
{
	t_pushswap	*top;
	int			count;

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
