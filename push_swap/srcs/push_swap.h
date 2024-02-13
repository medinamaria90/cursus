/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:45:18 by marimedi          #+#    #+#             */
/*   Updated: 2024/02/08 12:04:54 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

//LINKED LIST//
typedef struct s_stack
{
	int				content;
	int				cost;
	int				movement;
	int				go_to;
	struct s_stack	*next;
}	t_stack;

//BONUS//
int		ft_strncmp(char const *s1, const char *s2, unsigned int n);
char	*get_next_line(int fd);

//SPLIT//
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

//PUSH SWAP//
void	ft_sort(t_stack **a, t_stack **b);

//PROCESS INPUT//
int		ft_return_error(void);
int		process_input(char *input[], t_stack **stack_a);

//LINKED LISTS //
void	ft_add_node_front(t_stack **lst, t_stack *new);
int		ft_add_node(int content, t_stack **lst);
void	ft_add_node_back(t_stack **lst, t_stack *new);
t_stack	*ft_lastnode(t_stack *lst);

//OPERATIONS//
int		is_ordered(t_stack *a);
void	ft_push(t_stack **dst, t_stack **src, int times);
void	ft_swap(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_rrotate(t_stack **stack);

//CALCULATIONS//
int		count_elements(t_stack *stack);
void	best_movement(t_stack *stack_a, int pos_a, t_stack *stack_b, int pos_b);

//MOVEMENTS//
void	ft_move(t_stack **a, t_stack **b, int pos_a, int movement);
void	move_diff_directions(t_stack **stack, int pos, int len, int name);

//SORT THREE//
void	ft_sort_three(t_stack **stack);
void	ft_push_back(t_stack **stack_a, t_stack **stack_b);
//FIND POSITIONS//
int		ft_find_max(t_stack *stack, int to_return);
int		ft_find_min(t_stack *stack, int to_return);
int		ft_find_below(int elm, t_stack *stack);
int		ft_is_smallest(int elm, t_stack *stack);
int		find_destination(int elm, t_stack *stack, int dest);
//SPLIT UTILS//
size_t	ft_strlen2(const char *str);
//OTHER UTILS//
int		ft_strncmp(char const *s1, const char *s2, unsigned int n);
void	free_stack(t_stack **stack);