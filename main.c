/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:11:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/10 21:04:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 4 && ac < ARG_MAX)
	{
		stack_a = ft_create_stack();
		stack_b = ft_create_stack();
		ft_initiatestack(&stack_a, av, ac);
		if (ft_checkduplicates(stack_a) != FALSE)
		{
			ft_putstr_fd("Duplicated arguments = ", STDERR_FILENO);
			ft_printf("%d\n", ft_checkduplicates(stack_a));
			return (EXIT_FAILURE);
		}
		ft_printstack(stack_a);
		ft_swap_rotate(&stack_a);
		ft_printstack(stack_a);
		ft_free(&stack_a, &stack_b);
	}
	else
	{
		ft_putstr_fd("Minimum 4 arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	//system("leaks push_swap");
	return (EXIT_SUCCESS);
}
