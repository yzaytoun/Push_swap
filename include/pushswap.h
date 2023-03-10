/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:14:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/10 20:44:56 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H	/*Push Swap Header*/
# define PUSHSWAP_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include "limits.h"

# define TRUE 1
# define FALSE !TRUE
# define SA 3
# define SB 4
# define SS 5
# define PA 6
# define PB 7
# define RA 8
# define RB 9
# define RR 10
# define RRA 11
# define RRB 12
# define RRR 13

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
void	ft_swap_rotate(t_stack **top);
void	ft_swap_reverse_rotate(t_stack **top);
void	ft_swap_first_two(t_stack **top);
void	ft_swap_push(t_stack **stack_a, t_stack **stack_b);
void	ft_printer(int pos);

//FIXME - To be deleted
void	ft_printstack(t_stack *a);

//ANCHOR - UTILs2
int		ft_isdigit_str(char *str);
void	ft_reverse_stack(t_stack **top);
#endif	/*Push Swap Header*/