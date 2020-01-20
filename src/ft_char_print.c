/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:34:56 by rklein            #+#    #+#             */
/*   Updated: 2020/01/20 12:01:44 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static char	*ft_char_to_str(char c)
{
	char	*str;
	
	if (!(str = (char*)malloc(sizeof(*str) + 1)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

static char	*ft_str_flags(t_var *id, char *str)
{
	char *tmp;
	
	if (id->type == 's')
	{
		if (id->dot)
		{
			tmp = ft_strsub(str, 0, ft_atoi(id->prec));
			free(str);
			str = tmp;
		}
	}
	if ((size_t)ft_atoi(id->fld_min) > ft_strlen(str))
		tmp = ft_spacepad(id, str);
	else
		tmp = ft_strdup(str);
	return (tmp);
}

void	ft_char_print(t_var *id, va_list args)
{
	char	c;
	char	*tmp;
	char	*str[2];

	if (id->type == '%')
		str[0] = ft_char_to_str('%');
	else if (id->type == 'c')
	{
		c = va_arg(args, int);
		str[0] = ft_char_to_str(c);
	}
	else if (id->type == 's')
	{
		tmp = va_arg(args, char*);
		if (!tmp)
			str[0] = ft_strdup("(null)");
		else
			str[0] = ft_strdup(tmp);
	}
	str[1] = ft_str_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
