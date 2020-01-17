/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:17:22 by rklein            #+#    #+#             */
/*   Updated: 2020/01/17 14:49:51 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_u_numlen(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_u_itoa(unsigned long long n)
{
	int	i;
	char	*str;

	i = ft_u_numlen(n);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

void	ft_uint_print(t_var *id, va_list args)
{
	unsigned int		value;
	unsigned long		l_value;
	unsigned long long	ll_value;
	char				*str[2];

	if (ft_strcmp(id->type_spec, "l") == 0)
	{
		l_value = va_arg(args, unsigned long);
		str[0] = (id->type == 'u') ? ft_u_itoa(l_value) : ft_base(l_value, id);
	}
	else if (ft_strcmp(id->type_spec, "ll") == 0)
	{
		ll_value = va_arg(args, unsigned long long);
		str[0] = (id->type == 'u') ? ft_u_itoa(ll_value) : ft_base(ll_value, id);
	}
	else
	{
		value = va_arg(args, unsigned int); //short int is promoted to int when passed as va_arg
		str[0] = (id->type == 'u') ? ft_u_itoa(value) : ft_base(value, id);
	}
	str[1] = ft_uint_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
