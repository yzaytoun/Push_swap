/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:15:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/20 19:44:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "pushswap.h"
# include "../libft/get_next_line.h"

//ANCHOR CHECKER AUX
int		ft_getline(t_stack *stack_a, t_stack *stack_b);
int		ft_applyinstructions(char ***sol, t_stack **stack_a, t_stack **stack_b);
int		ft_getline_aux(char **line, char **input);
int		ft_checkinput(char *input);
void	ft_printstack(t_stack *stack);
#endif