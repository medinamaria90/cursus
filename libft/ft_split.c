/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:04:45 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/04 19:59:36 by marimedi         ###   ########.fr       */
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

static void	ft_skip_char(const char *str, char c, size_t *str_f, size_t *str_s)
{
	while (str[*str_f] == c)
		(*str_f)++;
	*str_s = *str_f;
}

static void	ft_take_word(const char *str, char c, size_t *str_f)
{
	while (str[*str_f] != c && str[*str_f] != '\0')
		(*str_f)++;
}

static	void	ft_find_words(char **array, const char *str, char c)
{
	size_t	str_s;
	size_t	str_f;
	int		arr_pos;
	char	*tempstr;

	str_f = 0;
	str_s = 0;
	arr_pos = 0;
	while (str[str_f] != '\0')
	{
		ft_skip_char(str, c, &str_f, &str_s);
		ft_take_word(str, c, &str_f);
		if (str_f > str_s)
		{
			tempstr = (char *)malloc((str_f - str_s + 1) * sizeof(char));
			if (tempstr == NULL)
			{
				ft_free_array(array);
				return (NULL);
			}
			ft_strlcpy(tempstr, &str[str_s], str_f - str_s + 1);
			array[arr_pos++] = tempstr;
		}
	}
	array[arr_pos] = NULL;
}

static size_t	ft_calculate_size_array(const char *s, char c)
{
	size_t size;
	size_t counter;

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
		if (ft_find_words(array, s, c) != 1)
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