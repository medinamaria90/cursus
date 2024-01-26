/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:21 by marimedi          #+#    #+#             */
/*   Updated: 2024/01/26 11:41:07 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ft_write_word(const char *str, int str_s, int str_f, char **array)
{
	int		count;

	count = 0;
	while (array[count] != NULL)
		count++;
	array[count] = ft_substr(str, str_s, str_f - str_s);
	if (array[count] == NULL)
		return (1);
	array[count + 1] = NULL;
	return (0);
}

static char	**ft_find_words(char **array, const char *str, char c)
{
	size_t	str_s;
	size_t	str_f;

	str_f = 0;
	str_s = 0;
	array[0] = NULL;
	while (str[str_f] != '\0')
	{
		while (str[str_f] == c)
			(str_f)++;
		str_s = str_f;
		while (str[str_f] != c && str[str_f] != '\0')
			str_f++;
		if (str_f > str_s)
		{
			if (ft_write_word(str, str_s, str_f, array) == 1)
				return (NULL);
		}
	}
	return (array);
}

static size_t	ft_calculate_size_array(const char *s, char c)
{
	size_t	size;
	size_t	counter;

	size = 0;
	counter = 0;
	while (s[counter])
	{
		if (s[counter] != c && (counter == 0 || s[counter - 1] == c))
			size++;
		counter++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	size_t	size_array;
	char	**array;

	size_array = ft_calculate_size_array(s, c);
	array = (char **)malloc((sizeof(char *) * (size_array + 1)));
	if (array == NULL)
		return (NULL);
	if (ft_find_words(array, s, c) == NULL)
	{
		ft_free_array(array);
		return (NULL);
	}
	return (array);
}