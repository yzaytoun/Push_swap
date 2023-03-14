/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:14:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/14 19:21:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H	/*Push Swap Header*/
# define PUSHSWAP_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <limits.h>
# include <time.h>	//FIXME - To be deleted

# define TRUE 1
# define FALSE !TRUE
# define SA 10
# define PA 11
# define RA 12
# define RRA 13
# define SB 14
# define PB 15
# define RB 16
# define RRB 17
# define SS 18
# define RR 19
# define RRR 20
# define ASC 'A'
# define DESC 'D'

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
int		ft_swap_rotate(t_stack **top);
int		ft_swap_reverse_rotate(t_stack **top);
int		ft_swap_first_two(t_stack **top);
int		ft_swap_push(t_stack **to_stack, t_stack **from_stack);
void	ft_printer(int signal);

//FIXME - To be deleted
void	ft_printstack(t_stack *a);

//ANCHOR - UTILs2
int		ft_isdigit_str(char *str);
void	ft_reverse_stack(t_stack **top);
int		ft_max(int x, int y);
int		ft_issorted(t_stack *top, int order);
int		ft_classifier(int signal);
#endif	/*Push Swap Header*/