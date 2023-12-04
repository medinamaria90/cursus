/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimedi <marimedi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:04:45 by marimedi          #+#    #+#             */
/*   Updated: 2023/12/04 14:13:45 by marimedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"



static	void	ft_find_words(char **array, char *str, char c)
{
	int		str_s_pos;
	int		str_f_pos;
	int		arr_pos;
	char	*tempstr;
	int		strlen;

	strlen = ft_strlen(str);
	printf("in ft_find_words str = %s\n", str);
	str_s_pos = 0;
	str_f_pos = 0;
	arr_pos = 0;
	while (str_f_pos <= strlen)
	{
		if ((str[str_f_pos] == c || str_f_pos == strlen))
		{
			if (str_f_pos > str_s_pos + 1)
			{
				tempstr = ft_strdup(&str[str_s_pos]);
				ft_bzero(&tempstr[str_f_pos - str_s_pos], strlen - str_f_pos);
				array[arr_pos] = tempstr;
				arr_pos++;
				str_s_pos = str_f_pos + 1;
			}
			else
			{
				str_s_pos++;
				str_f_pos++;
			}
		}
		str_f_pos++;
	}
	array[arr_pos] = NULL;
}

static	size_t	ft_calculate_size_array(char const *s, char c)
{
	size_t	size;
	size_t	counter;

	counter = 0;
	size = 0;
	while (s[counter])
	{
		if (s[counter] == c)
			size++;
		counter++;
	}
	return (size + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	size_array;
	char	*trimmedstr;
	char	**array;
	
	trimmedstr = ft_strtrim(s, &c);
	size_array = ft_calculate_size_array(trimmedstr, c);
	array = (char **)malloc((sizeof(char *) * (size_array)) + 1);
	if (array == NULL)
		return (NULL);
	ft_find_words(array, trimmedstr, c);
	return (array);
}

int main()
{
    char **result;
    char *str = "   Hola  mundo, soy  yo  ";
    char c = ' ';
    int i = 0;

    result = ft_split(str, c);

    while (result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }

    // Aquí debes liberar la memoria asignada por ft_split
    // for (i = 0; result[i]; i++)
    //     free(result[i]);
    // free(result);

    return 0;
}
