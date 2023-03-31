/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:14:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/31 18:53:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H	/*Push Swap Header*/
# define PUSHSWAP_H

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf_bonus.h"
# include <limits.h>

# define TRUE 1
# define FALSE !TRUE
# define SA 1
# define PA 2
# define RA 3
# define RRA 4
# define SB 10
# define PB 20
# define RB 30
# define RRB 40
# define SS 11
# define RR 33
# define RRR 44
# define ASC 'A'
# define DESC 'D'

//ANCHOR - Structs declaration
typedef struct s_stack
{
	int			index;
	t_list		*stack;
}				t_stack;

typedef struct s_variables
{
	int			counter;
	int			max_a;
	int			max_b;
	int			min_a;
	int			min_b;
	int			top_a;
	int			top_b;
	int			last_a;
	int			last_b;
	int			size_a;
	int			steps;
	int			signal;
	int			full_size;
	int			flag;
}				t_variables;

//ANCHOR - PUSHSWAP UTIL
t_stack		*ft_create_stack(int index);
void		ft_push(t_list **top, void *data);
int			ft_pop(t_list **top);
int			ft_isempty(t_list *top);
int			ft_gettop(t_list *top);

//ANCHOR	 - PushSWAP AUX
void		ft_deletestack(t_list **top);
int			ft_getlast(t_list *top);
void		ft_initiatestack(t_list **a, char **av);
int			ft_checkduplicates(t_list *a);
void		ft_free(t_stack **a, t_stack **b, t_list *sorted);

//ANCHOR -  Operation
t_list		*ft_getnode(t_list *stac, int pos);
int			ft_getmin(t_list *stac);
int			ft_getmax(t_list *stac);
int			ft_getpos(t_list *stac, int num);
int			ft_len_strarr(char **strarr);

//ANCHOR -  Actions
int			ft_swap_first_two(t_stack **top);
int			ft_swap_push(t_stack **to_stack, t_stack **from_stack);
int			ft_swap_rotate(t_stack **top);
int			ft_swap_reverse_rotate(t_stack **top);
void		ft_printer(int signal);

//ANCHOR - SORT
void		ft_sort_stack(t_stack **stack_a, t_stack *stack_b);
void		ft_setvariables(t_stack *stack_a, t_stack *stack_b,
				t_variables *vars);
int			ft_checktop(t_stack *stack_a, t_stack *stack_b, t_variables *vars);
int			ft_checkmax(t_stack *stack_a, t_stack *stack_b, t_variables *vars);
int			ft_checkmin(t_stack *stack_a, t_stack *stack_b, t_variables *vars);

//FIXME - To be deleted
void		ft_printstack(t_list *a);

//ANCHOR - UTILs2
int			ft_isdigit_str(char *str);
void		ft_reverse_stack(t_list **top);
int			ft_max(int x, int y);
int			ft_issorted(t_list *top, int order);

//ANCHOR - MERGE
void		ft_mergesort(t_list **stack);
t_list		*ft_copylist(t_list *list);

//ANCHOR - SORT AUX
void		ft_finalcheck(t_stack *stack_a, t_stack *stack_b,
				t_variables *vars);
int			ft_findchr(char *s, char c);
void		ft_free_strarr(char **s);
char		**ft_copy_strarr(char **s, int input, int *count);
void		ft_avtype(char **av, char ***arg, int *i);
#endif	/*Push Swap Header*/