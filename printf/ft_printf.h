/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:12:29 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/09 11:09:59 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(char const *str, ...);
int	ft_int_to_hex(unsigned long long int num, char mayus, int size);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr(int n);

#endif
