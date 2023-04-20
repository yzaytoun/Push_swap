/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:10:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/20 19:37:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
//SECTION STRING ARRAY
//ANCHOR - Find Char
int	ft_findchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (TRUE);
		++i;
	}
	return (FALSE);
}

//ANCHOR - Copy String Array
char	**ft_copy_strarr(char **s, int input, int *count)
{
	char	**newstr;
	int		i;
	int		index;

	index = 0;
	if (input == STDIN_FILENO)
		i = 1;
	else
		i = 0;
	if (!s || *s == NULL)
		return (NULL);
	newstr = ft_calloc(sizeof(char *), ft_len_strarr(s) + 1);
	if (!newstr)
		return (NULL);
	while (s[i] != NULL)
	{
		newstr[index] = ft_strdup(s[i]);
		++i;
		++index;
	}
	*count = index;
	newstr[index] = NULL;
	return (newstr);
}

//ANCHOR - Free String Array
void	ft_free_strarr(char **s)
{
	int	i;

	i = 0;
	if (!s || *s == NULL)
		return ;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

//ANCHOR - Check arguments
void	ft_avtype(char **av, char ***arg, int *i)
{
	int		count;

	count = 0;
	if (ft_findchr(av[1], ' ') == TRUE)
	{
		*arg = ft_split(av[1], ' ');
		while ((*arg)[count] != NULL)
			count++;
	}
	else
	{
		*arg = ft_copy_strarr(av, STDIN_FILENO, &count);
		if (!*arg)
			return ;
	}
	*i = count - 1;
}

//ANCHOR - Measure distance
int	ft_getpos_rev(t_list *stac, int num)
{
	t_list	*top;
	t_list	*node;
	int		pos;

	pos = 0;
	if (ft_isempty(stac))
		return (0);
	top = ft_copylist(stac);
	ft_reverse_stack(&top);
	node = top;
	while (node != NULL)
	{
		if ((int)node->content == num)
		{	
			ft_deletestack(&top);
			return (pos);
		}
		++pos;
		node = node->next;
	}
	ft_deletestack(&top);
	return (pos);
}
//!SECTION