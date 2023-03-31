/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:33:39 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/31 20:29:43 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap_bonus.h"

int	main(int ac, char **av)
{
	t_list	*stack;
	char	**solution;

	if (ac > 1 && ac < ARG_MAX)
	{
		stack = ft_calloc(sizeof(t_list), 1);
		if (!stack)
			return (EXIT_FAILURE);
		ft_getline(&solution);
		ft_initiatestack(&stack, av);
		ft_printstack(stack);
		ft_lstclear(&stack, 0);
		ft_free_strarr(solution);
	}
	else
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	//system("leaks checker");
	return (EXIT_SUCCESS);
}