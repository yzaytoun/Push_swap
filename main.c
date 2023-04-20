/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:11:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/19 20:36:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
		if (ft_lstsize(stack_a->stack) <= 9)
			ft_sortstack(stack_a, stack_b);
		else
			ft_sortalgo(stack_a, stack_b);
		ft_free(&stack_a, &stack_b, NULL);
	}
	return (EXIT_SUCCESS);
}
