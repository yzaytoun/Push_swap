/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:10:15 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/30 20:31:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_finalcheck(t_stack *stack_a, t_stack *stack_b, t_variables *vars)
{
	t_list	*node;

	(void)vars;
	if (ft_isempty(stack_a->stack))
		return ;
	node = stack_b->stack;
	if (ft_issorted(node, DESC) == TRUE
		&& ft_lstsize(node) > 0 && ft_issorted(stack_a->stack, ASC) == TRUE)
	{
		while (node != NULL)
		{
			ft_printer(ft_swap_push(&stack_a, &stack_b));
			node = node->next;
		}
		vars->flag = 1;
	}
	else if (ft_issorted(stack_a->stack, ASC) != TRUE)
		ft_printer(ft_swap_push(&stack_b, &stack_a));
	if (ft_issorted(stack_a->stack, ASC) == TRUE
		&& ft_lstsize(stack_b->stack) == 0)
		vars->flag = 1;
}

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
