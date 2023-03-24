/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:11:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/24 20:03:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

//KEYWORDS - Find the shortes path / Algorithm validation /  
//REVIEW - https://www.computerscienceai.com/2019/04/c-program-for-binary-search.html
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*sorted;
	int		maxsteps;
	time_t	rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	ft_printf("Time [%d:%d]\n", timeinfo->tm_min, timeinfo->tm_sec);
	if (ac > 4 && ac < ARG_MAX)
	{
		maxsteps = (2 * (ac - 1)) - 1;
		stack_a = ft_create_stack(1);
		stack_b = ft_create_stack(2);
		ft_initiatestack(&stack_a->stack, av, ac);
		if (ft_checkduplicates(stack_a->stack) != FALSE)
		{
			ft_putstr_fd("Error", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		sorted = ft_copylist(stack_a->stack);
		ft_mergesort(&sorted);
		ft_sort_stack(&stack_a, stack_b, maxsteps, sorted);
		printf("sorted version\n");
		ft_printstack(sorted);
		printf("stack version\n");
		ft_printstack(stack_a->stack);
		ft_free(&stack_a, &stack_b, sorted);
	}
	else
	{
		ft_putstr_fd("Minimum 4 arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	timeinfo = localtime(&rawtime);
	ft_printf("Time [%d:%d]\n", timeinfo->tm_min, timeinfo->tm_sec);
	//system("leaks push_swap");
	return (EXIT_SUCCESS);
}
