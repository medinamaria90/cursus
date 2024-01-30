/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:45:18 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/29 11:49:22 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 42

//BONUS//
int		ft_strncmp(char const *s1, const char *s2, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup_len(const char *s, int len);

//PUSH_SWAP//
typedef struct s_stack {
	int				content;
	int				cost;
	int				movement;
	int				place_to_go;
	struct s_stack	*next;
} t_stack;

//SPLIT//
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
//PUSH SWAP//
void 	ft_print_stack(t_stack *stack, int name);
void	ft_sort(t_stack **a, t_stack **b);
//MANAGE INPUT//
int		process_input(char *input[], t_stack **stack_a);
int		are_there_spaces(char *str);
int		ft_str_to_int(char *str);
int		ft_save_int(char *str, int *i);
int 	ft_return_error(void);
//LINKED LISTS //
void	ft_add_node_front(t_stack **lst, t_stack *new);
t_stack	*ft_new_node(int content);
void	ft_add_node_back(t_stack **lst, t_stack *new);
int		ft_add_node(int content, t_stack **lst);
t_stack	*ft_lastnode(t_stack *lst);
//OPERATIONS//
int		is_ordered(t_stack *a);
void	ft_push(t_stack **dst, t_stack **src, int times);
void	ft_swap(t_stack **stack);
void	ft_rotate(t_stack **stack);
void	ft_rrotate(t_stack **stack);
//CALCULATIONS//
int		count_elements(t_stack *stack);
int 	calculate_cost(t_stack *a, t_stack *b, int pos_a, int a_value);
int		find_cheapest_movement(t_stack *a, t_stack *b);
//MOVEMENTS//
void 	ft_best_movement(t_stack **stack, int pos, int len, int name);
void	ft_reverse_rotate_al(t_stack **a, t_stack **b, int pos_a, int pos_b);
void	ft_rotate_al(t_stack **a, t_stack **b, int rotations_a, int rotations_b);
void 	ft_move(t_stack **a, t_stack **b, int pos_a, int movement);
//SORT THREE//
void	ft_sort_three(t_stack **stack);
void	ft_push_back(t_stack **stack_a, t_stack **stack_b);
//FIND POSITIONS//
int		ft_find_max(t_stack *stack, int to_return);
int		ft_find_min(t_stack *stack, int to_return);
int		ft_find_below(int elm, t_stack *stack);
int		ft_is_smallest(int elm, t_stack *stack);
int		find_destination(int elm, t_stack *stack, int dest);
