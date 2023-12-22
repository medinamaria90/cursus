/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:12:29 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/22 17:11:43 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

char	*ft_strdup_len(const char *s, int len);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putptr(void *ptr);
int		ft_putnbr_big(unsigned int n);
int		ft_int_to_hex(unsigned long long int num, int mayus, int size);