/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:16:47 by rklein            #+#    #+#             */
/*   Updated: 2020/01/25 15:47:17 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_numlen(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_s_itoa(t_var *id, long long n)
{
	int	i;
	char	*str;

	if (n == -9223372036854775807 - 1)
	{
		id->sign[0] = '-';
		return (ft_strdup("9223372036854775808"));
	}
	i = ft_numlen(n);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		id->sign[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

void	ft_int_print(t_var *id, va_list args)
{
	intmax_t	value;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "l") == 0)
		value = (long int)va_arg(args, intmax_t);
	else if (ft_strcmp(id->type_spec, "ll") == 0)
		value = (long long int)va_arg(args, intmax_t);
	else if (ft_strcmp(id->type_spec, "h") == 0)
		value = (short int)va_arg(args, intmax_t);
	else if (ft_strcmp(id->type_spec, "hh") == 0)
		value = (char)va_arg(args, intmax_t);
	else
		value = (int)va_arg(args, intmax_t);
	str[0] = ft_s_itoa(id, value);
	str[1] = ft_int_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}

/*void	ft_int_print(t_var *id, va_list args)
{
	int			value;
	long		l_value;
	long long	ll_value;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "l") == 0)
	{
		l_value = va_arg(args, long);
		str[0] = ft_s_itoa(id, l_value);
	}
	else if (ft_strcmp(id->type_spec, "ll") == 0)
	{
		ll_value = va_arg(args, long long);
		str[0] = ft_s_itoa(id, ll_value);
	}
	else
	{
		value = va_arg(args, int); //short int is promoted to int when passed as va_arg
		str[0] = ft_s_itoa(id, value);
	}
	str[1] = ft_int_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}*/
