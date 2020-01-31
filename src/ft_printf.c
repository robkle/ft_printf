/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:04:08 by rklein            #+#    #+#             */
/*   Updated: 2020/01/31 12:41:02 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h> //REMOVE

static int	ft_valid_type(char c)
{
	if (c >= 'b' && c <= 'g')
		return (1);
	if (ft_toupper(c) == 'E' || ft_toupper(c) == 'G' || ft_toupper(c) == 'X')
		return (1);
	if (c == 'i' || c == 'o' || c == 'p' || c == 's' || c == 'u' || c == '%')
		return (1);
	return (0);
}

static int	ft_read_id(t_var *id, const char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] && (str[i] == '#' || str[i] == '0'  || str[i] == ' '  ||
			str[i] == '-'  || str[i] == '+'))
		id->flags[x++] = str[i++];
	x = 0;
	while (str[i] && ft_isdigit(str[i]))
		id->fld_min[x++] = str[i++];
	if (str[i] == '.')
	{
		id->dot = 1;
		i++;
	}
	x = 0;
	while (str[i] && ft_isdigit(str[i]))
		id->prec[x++] = str[i++];
	x = 0;
	if (str[i] && (str[i] == 'l' || str[i] == 'h' || str[i] == 'L'))
	{
		id->type_spec[x++] = str[i++];
		if (str[i] && str[i] == str[i - 1] && str[i] != 'L')
			id->type_spec[x++] = str[i++];
	}
	id->type = str[i++];
	if (!ft_valid_type(id->type))
		return (0);
	return (i);
}

static t_var	*ft_idalloc(void)
{
	t_var	*id;

	if(!(id = malloc(sizeof(t_var))))
		return (NULL);
	id->count = 0;
	id->flags = ft_strnew(6);
	id->fld_min = ft_strnew(11);
	id->prec = ft_strnew(3);
	id->type_spec = ft_strnew(3);
	return (id);
}

static void	ft_reset(t_var *id)
{
	id->sign = '+';
	ft_strclr(id->flags);
	ft_strclr(id->fld_min);
	id->dot = 0;
	ft_strclr(id->prec);
	id->prec[0] = '0';
	ft_strclr(id->type_spec);
	id->type = 0;
}

static void	ft_direct(t_var *id, va_list args)
{
	if (id->type == 'f')
		ft_double_print(id, args);
	else if (id->type == 'p')
		ft_addr_print(id, args);
	else if (id->type == 'd' || id->type == 'i')
		ft_int_print(id, args);
	else if (id->type == 'o' || id->type == 'u' || id->type == 'x' || id->type == 'X' || id->type == 'b')
		ft_uint_print(id, args);
	else if (id->type == 's' || id->type == 'c' || id->type == '%')
		ft_char_print(id, args);
	else if (ft_toupper(id->type) == 'E')
		ft_e_print(id, args);
	else if (ft_toupper(id->type) == 'G')
		ft_g_print(id, args);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_var	*id;
	int	i;
	
	va_start(args, format);
	id = ft_idalloc(); 
	i = 0;
	while (format[i] != '\0')
	{
		ft_reset(id);
		if (format[i] == '%')
		{
			i = i + ft_read_id(id, &format[i + 1]);//problem with % may lie here
			ft_direct(id, args);
		}
		else
		{
			write(1, &format[i], 1);
			id->count++;
		}
		i++;
	}
	va_end(args);
	return (ft_free_id(id));
}
