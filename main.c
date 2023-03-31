/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:11:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/31 18:54:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*sorted;

	if (ac > 1 && ac < ARG_MAX)
	{
		stack_a = ft_create_stack(1);
		stack_b = ft_create_stack(2);
		ft_initiatestack(&stack_a->stack, av);
		if (ft_checkduplicates(stack_a->stack) != FALSE)
		{
			ft_putstr_fd("Error", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		sorted = ft_copylist(stack_a->stack);
		ft_mergesort(&sorted);
		ft_printstack(stack_a->stack);
		ft_sort_stack(&stack_a, stack_b);
		ft_free(&stack_a, &stack_b, sorted);
	}
	else
	{
		ft_putstr_fd("Minimum 4 arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	//system("leaks push_swap");
	return (EXIT_SUCCESS);
}
