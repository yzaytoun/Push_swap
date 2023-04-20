/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:14:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/04/20 20:24:37 by yzaytoun         ###   ########.fr       */
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
# define BACKWARD 'B'
# define FORWARD 'F'

//ANCHOR - Structs declaration
typedef struct s_stack
{
	int			index;
	t_list		*stack;
}				t_stack;

typedef struct s_variables
{
	int			max_a;
	int			max_b;
	int			min_a;
	int			min_b;
	int			top_a;
	int			top_b;
	int			last_a;
	int			last_b;
	int			next_a;
	int			next_b;
	int			size_a;
	int			size_b;
	int			full_size;
	int			revnext_a;
	int			revnext_b;
	int			algo;
	int			curr;
	int			currpos;
	int			currrevpos;
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
int			ft_getnum(t_list *stac, int pos, int direction);
int			ft_getmin(t_list *stac);
int			ft_getmax(t_list *stac);
int			ft_getpos(t_list *stac, int num);
int			ft_len_strarr(char **strarr);

//ANCHOR -  Actions
int			ft_swap_first_two(t_stack **top);
int			ft_swap_push(t_stack *to_stack, t_stack *from_stack);
int			ft_swap_rotate(t_stack **top);
int			ft_swap_reverse_rotate(t_stack **top);
void		ft_printer(int signal);

//ANCHOR - SORT
void		ft_finalstep(t_stack *stack_a, t_stack *stack_b, t_variables *vars);
int			ft_searchstack(t_list *stack, int num);
void		ft_sortstack(t_stack *stack_a, t_stack *stack_b);
void		ft_checkpoint(t_stack *stack_a, t_stack *stack_b,
				t_variables *vars);
void		ft_sortloop(t_stack *stack_1, t_stack *stack_2, t_variables *vars);

//ANCHOR - SORT AUX
int			ft_findchr(char *s, char c);
void		ft_free_strarr(char **s);
char		**ft_copy_strarr(char **s, int input, int *count);
void		ft_avtype(char **av, char ***arg, int *i);
int			ft_getpos_rev(t_list *stac, int num);

//ANCHOR - UTILs2
int			ft_isdigit_str(char *str);
void		ft_reverse_stack(t_list **top);
int			ft_issorted(t_list *top, int order);
int			ft_getnext(t_list *lst, int direction);
t_list		*ft_getbottom(t_list *stac);

//ANCHOR - MERGE
void		ft_getnext_element(t_stack *stack_a, t_stack *stack_b,
				t_variables *vars);
void		ft_mergesort(t_list **stack);
t_list		*ft_copylist(t_list *list);

//ANCHOR - SORT AUX2
void		ft_checkrotate(t_stack *stack_a, t_stack *stack_b,
				t_variables *vars);
void		ft_checkreverse(t_stack *stack_a, t_stack *stack_b,
				t_variables *vars);
void		ft_checkswap(t_stack *stack_a, t_stack *stack_b, t_variables *vars);
void		ft_checkmax(t_stack *stack_a, t_stack *stack_b, t_variables *vars);
void		ft_checkmin(t_stack *stack_a, t_stack *stack_b, t_variables *vars);

//ANCHOR - PUSHSWAP
void		ft_checkpos(t_stack *stack_a, t_stack *stack_b, t_variables *vars);
void		ft_pushtob(t_stack *stack_a, t_stack *stack_b,
				t_variables *vars);
void		ft_sortalgo(t_stack *stack_a, t_stack *stack_b);
int			ft_getchunk(t_list *sorted,
				t_stack *stack, int (*func)(t_list *, int), t_variables *vars);

#endif	/*Push Swap Header*/