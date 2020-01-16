/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:16:47 by rklein            #+#    #+#             */
/*   Updated: 2020/01/15 16:19:26 by rklein           ###   ########.fr       */
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
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_s_itoa(long long n)
{
	int	i;
	char	*str;

	//if (n == <minimum long long>
	//	return (ft_strdup("<minimum long long>");
	i = ft_numlen(n);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
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

void	ft_int_print(t_var *id, va_list args)
{
	int			value;
	long		l_value;
	long long	ll_value;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "l") == 0)
	{
		l_value = va_arg(args, long);
		str[0] = ft_s_itoa(l_value);
	}
	else if (ft_strcmp(id->type_spec, "ll") == 0)
	{
		ll_value = va_arg(args, long long);
		str[0] = ft_s_itoa(ll_value);
	}
	else
	{
		value = va_arg(args, int); //short int is promoted to int when passed as va_arg
		str[0] = ft_s_itoa(value);
	}
	str[1] = ft_sdec_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
