/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:34:56 by rklein            #+#    #+#             */
/*   Updated: 2020/01/16 10:58:56 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_char_to_str(char c)
{
	char	*str;
	
	if (!(str = (char*)malloc(sizeof(*str) + 1)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	ft_char_print(t_var *id, va_list args)
{
	char	c;
	char	*str[2];

	if (id->type == '%')
		str[0] = ft_char_to_str('%');
	else if (id->type == 'c')
	{
		c = va_arg(args, int);
		str[0] = ft_char_to_str(c);
	}
	else if (id->type == 's')
		str[0] = ft_strdup(va_arg(args, char*));
	if ((size_t)ft_atoi(id->fld_min) > ft_strlen(str[0]))
		str[1] = ft_spacepad(id, str[0]);
	else
		str[1] = ft_strdup(str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[0]);
	free(str[1]);
}
