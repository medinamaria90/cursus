#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			//printf("i is %d, s[i] is %c\n", i, s[i]);
			return ((char *)(&s[i]));
		}
		i++;	
	}
	if ((char)c == '\0')
	{
		//printf("not found, going to return %p, the 0 position was %p\n", (char *)(&s[i]), (char *)s);
		return ((char *)(&s[i]));
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	if (str == 0)
		return (0);
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len || size == 0)
		return (src_len + size);
	count = 0;
	while (src[count])
	{
		if (dest_len + count < size - 1)
			dest[count + dest_len] = src[count];
		count++;
	}
	if (size > src_len + dest_len)
		dest[src_len + dest_len] = '\0';
	else if (size > dest_len)
		dest[size - 1] = '\0';
	return (src_len + dest_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	if (src == NULL)
		return (-1);
	count = 0;
	while (count < n - 1 && src[count] && n != 0)
	{
		if (src[count])
			dest[count] = src[count];
		else
			dest[count] = '\0';
		count ++;
	}
	if (n != 0)
		dest[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s3 = (char *)malloc(((lens1 + lens2) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, lens1 + 1);
	ft_strlcat(s3, s2, lens2 + lens1 + 1);
	return (s3);
}
