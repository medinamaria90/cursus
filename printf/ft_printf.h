/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:12:29 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/23 12:51:27 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

int	ft_printf(char const *str, ...);
int	ft_int_to_hex(unsigned long long int num, int mayus, int size);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr(int n);
