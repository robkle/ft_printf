/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:19:50 by rklein            #+#    #+#             */
/*   Updated: 2020/02/03 16:46:31 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strchr_int(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	else
		return (0);
}

char	*ft_strmake(char c, int size)
{
	char	*s;
	int		i;

	size = size < 0 ? 0 : size;
	if (!(s = (char*)malloc(sizeof(*s) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
		s[i++] = c;
	s[i] = '\0';
	return (s);
}

static int  ft_valid_type(char c)
{
	if (c >= 'b' && c <= 'g')
		return (1);
	if (ft_toupper(c) == 'E' || ft_toupper(c) == 'G' || ft_toupper(c) == 'X')
		return (1);
	if (c == 'i' || c == 'o' || c == 'p' || c == 's' || c == 'u' || c == '%')
		return (1);
	return (0);
}

int		ft_free_id(t_var *id)
{
	int	count;

	count = id->count;
	free(id->flags);
	free(id->fld_min);
	free(id->prec);
	free(id->type_spec);
	free(id);
	return (count);
}
