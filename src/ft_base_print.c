/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:17:06 by rklein            #+#    #+#             */
/*   Updated: 2020/01/24 17:10:34 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_itoa_base(unsigned long long value, int base)
{
	char			*base_char;
	char			*str;
	unsigned long long	tmp;
	int			len;
	
	base_char = "0123456789abcdef";
	tmp = value;
	len = 1;
	while (tmp /= base)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = base_char[value % base];
		value /= base;
	}
	return (str);
}

void	ft_addr_print(t_var *id, va_list args)
{
	void				*ar;
	unsigned long long	value;
	char				*str[3];

	ar = va_arg(args, void*);
	value = (unsigned long long)ar;
	str[0] = ft_itoa_base(value, 16);
	str[1] = ft_strjoin("0x", str[0]);
	if ((size_t)ft_atoi(id->fld_min) > ft_strlen(str[1]))
		str[2] = ft_spacepad(id, str[1]);
	else
		str[2] = ft_strdup(str[1]);
	ft_putstr(str[2]);
	id->count += ft_strlen(str[2]);
	free(str[0]);
	free(str[1]);
	free(str[2]);
}

char	*ft_base(unsigned long long value, t_var *id)
{
	char	*str;
	int		i;

	if (value == 0 && id->dot && ft_strchr_int(id->prec, '0'))
		str = ft_strnew(0);
	else if (id->type == 'b')
		str = ft_itoa_base(value, 2);
	else if (id->type == 'o')
		str = ft_itoa_base(value, 8);
	else if (id->type == 'x' || id->type == 'X')
	{
		str = ft_itoa_base(value, 16);
		if (id->type == 'X') 
		{	
			i = -1;
			while (str[++i])
				str[i] = ft_toupper(str[i]);
		}
	}
	else
		str = NULL;
	return (str);
}
