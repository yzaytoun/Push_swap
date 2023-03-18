/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:14:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/18 17:24:44 by yzaytoun         ###   ########.fr       */
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
# define SA 1
# define PA 2
# define RA 3
# define RRA 4
# define SB 5
# define PB 6
# define RB 7
# define RRB 8
# define SS 6
# define RR 10
# define RRR 12
# define ASC 'A'
# define DESC 'D'

typedef struct s_stack
{
	int			index;
	t_list		*stack;
}				t_stack;

//ANCHOR - PUSHSWAP UTIL
t_stack		*ft_create_stack(int index);
void		ft_push(t_list **top, void *data);
int			ft_pop(t_list **top);
int			ft_isempty(t_list *top);
int			ft_gettop(t_list *top);

//ANCHOR	 - PushSWAP AUX
void		ft_deletestack(t_list **top);
int			ft_getlast(t_list *top);
void		ft_initiatestack(t_list **a, char **av, int ac);
int			ft_checkduplicates(t_list *a);
void		ft_free(t_stack **a, t_stack **b);

//ANCHOR -  Operation
int			ft_stacksize(t_list *stac);
t_list		*ft_getnode(t_list *stac, int pos);
int			ft_getmin(t_list *stac);
int			ft_getmax(t_list *stac);
int			ft_getpos(t_list *stac, int num);

//ANCHOR -  Actions
int			ft_swap_rotate(t_stack **top);
int			ft_swap_reverse_rotate(t_stack **top);
int			ft_swap_first_two(t_list **top);
int			ft_swap_push(t_stack *to_stack, t_stack *from_stack);
void		ft_printer(int signal);

//FIXME - To be deleted
void		ft_printstack(t_list *a);

//ANCHOR - UTILs2
int			ft_isdigit_str(char *str);
void		ft_reverse_stack(t_list **top);
int			ft_max(int x, int y);
int			ft_issorted(t_list *top, int order);


#endif	/*Push Swap Header*/