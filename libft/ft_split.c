/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:04:45 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/05 08:43:03 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

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

static char	*ft_write_word(const char *str, int str_s, int str_f, char **array)
{
	char	*tempstr;

	tempstr = (char *)malloc((str_f - str_s + 1) * sizeof(char));
	if (tempstr == NULL)
	{
		ft_free_array(array);
		return (NULL);
	}
	ft_strlcpy(tempstr, &str[str_s], str_f - str_s + 1);
	return (tempstr);
}

static char	**ft_find_words(char **array, const char *str, char c)
{
	size_t	str_s;
	size_t	str_f;
	int		arr_pos;

	str_f = 0;
	str_s = 0;
	arr_pos = 0;
	while (str[str_f] != '\0')
	{
		while (str[str_f] == c)
			(str_f)++;
		str_s = str_f;
		while (str[str_f] != c && str[str_f] != '\0')
			str_f++;
		if (str_f > str_s)
		{
			array[arr_pos++] = ft_write_word(str, str_s, str_f, array);
			if (array[arr_pos - 1] == NULL)
				return (NULL);
		}
	}
	array[arr_pos] = NULL;
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
	else
		if (ft_find_words(array, s, c) == NULL)
			return (NULL);
	return (array);
}
/*
int main()
{
    char **result;
    char *str =  " Hello   there ";
    char c = ' ';
    int i = 0;

    result = ft_split(str, c);

    while (result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    return 0;
}
*/