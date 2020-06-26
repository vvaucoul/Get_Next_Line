/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:27:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/15 11:27:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*pt;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((pt = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		pt[i] = s1[j];
		++i;
		++j;
	}
	j = 0;
	while (s2[j])
	{
		pt[i] = s2[j];
		++i;
		++j;
	}
	pt[i] = '\0';
	return (pt);
}

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	if ((ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

void		ft_strmove(char *s1)
{
	char *tmp;
	char *base;

	base = s1;
	tmp = s1;
	while (*tmp)
		tmp++;
	tmp++;
	while (*tmp)
		*s1++ = *tmp++;
	*s1 = *tmp;
	s1 = base;
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;

	t = (unsigned char *)b;
	while (len--)
		*(t++) = (unsigned char)c;
	return (b);
}
