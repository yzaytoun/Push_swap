/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:14:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/04 19:45:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include "limits.h"

# define TRUE 1
# define FALSE !TRUE

typedef struct s_stack	t_stack;
struct s_stack
{
	int			num;
	t_stack		*next;
};

//ANCHOR - PUSHSWAP UTIL
t_stack	*ft_create_stack(void);
void	ft_push(t_stack **top, int data);
int		ft_pop(t_stack **top);
int		ft_isempty(t_stack *top);
int		ft_gettop(t_stack *top);

//ANCHOR - PushSWAP AUX
void	ft_deletestack(t_stack **top);
int		ft_getlast(t_stack *top);
void	ft_initiatestack(t_stack **a, char **av, int ac);
int		ft_checkduplicates(t_stack *a);
void	ft_free(t_stack **a, t_stack **b);

//ANCHOR -  Operation
int		ft_stacksize(t_stack *stac);
t_stack	*ft_getnode(t_stack *stac, int pos);
int		ft_getmin(t_stack *stac);
int		ft_getmax(t_stack *stac);
int		ft_getpos(t_stack *stac, int num);


//ANCHOR -  Actions
int		ft_swapnodes(t_stack **stac, int pos1, int pos2);
void	ft_swapstacks(t_stack **stac1, t_stack **stac2);
void	ft_swap_rotate(t_stack **top);

//ANCHOR -  Actions
void	ft_swap_first_two(t_stack **top);

//FIXME - To be deleted
void	ft_printstack(t_stack *a);
#endif