/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:13:54 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/30 20:24:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//SECTION - Operations
//ANCHOR - GET Position from value
int	ft_getpos(t_list *stac, int num)
{
	t_list		*top;
	int			pos;

	pos = 0;
	if (ft_isempty(stac))
		return (0);
	top = stac;
	while (top != NULL)
	{
		if (*((int *)top->content) == num)
			break ;
		++pos;
		top = top->next;
	}
	return (pos);
}

//ANCHOR - Max value
int	ft_getmax(t_list *stac)
{
	t_list		*top;
	int			max;

	if (ft_isempty(stac))
		return (0);
	top = stac;
	max = (int)stac->content;
	while (top != NULL)
	{
		if (((int)top->content) > max)
			max = ((int)top->content);
		top = top->next;
	}
	return (max);
}

//ANCHOR - Min Value
int	ft_getmin(t_list *stac)
{
	t_list		*top;
	int			min;

	if (ft_isempty(stac))
		return (0);
	top = stac;
	min = ((int)stac->content);
	while (top != NULL)
	{
		if (((int)top->content) < min)
			min = ((int)top->content);
		top = top->next;
	}
	return (min);
}

//ANCHOR - Get node
t_list	*ft_getnode(t_list *stac, int pos)
{
	t_list		*top;
	int			count;

	count = 0;
	if (ft_isempty(stac))
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

//ANCHOR - STRARRAY LEN
int	ft_len_strarr(char **strarr)
{
	int	i;

	i = 0;
	if (!strarr)
		return (i);
	else
	{
		while (strarr[i] != NULL)
			++i;
	}
	return (i);
}
//!SECTION 
