/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:15:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/01 17:30:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "pushswap.h"
# include "../libft/get_next_line.h"

//ANCHOR CHECKER AUX
void	ft_getline(t_stack *stack_a, t_stack *stack_b);
void	ft_applyinstructions(char *sol, t_stack *stack_a, t_stack *stack_b);

#endif