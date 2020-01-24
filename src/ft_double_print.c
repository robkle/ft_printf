/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:03:25 by rklein            #+#    #+#             */
/*   Updated: 2020/01/24 17:20:18 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* Double is passed as an integer, to determine the length of the number 
** in front of the decimal point*/

static int	ft_intl(int n) //put in integer file, or as separate file
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

/* Coverts precision to the power of 10. The ft_ftoa funtion handles an integer, 
** so everything behind the decimal point as to be moved in front of it by
** multiplying the double with 10 to the power of the precision*/

static long long	ft_dec(int pr)
{
	long	dec;

	dec = 1;
	while (pr-- > 0)
		dec = dec * 10;
	return (dec);
}

/* The main float to string functions. Memory for the string is allocated; the size is
** the sum of the number of digits in front of the decimal point, the precision, and the 
** the decimal point (if precision is 0, no space allocated for decimal point. The double 
** is multiplied by the precision to the power of 10, and the string is filled from the 
** back using % 10*/

char		*ft_ftoa(long double fl, int pr)
{
	long long	num;
	long long	dec;
	char		*str;
	int		len;

	dec = ft_dec(pr);
	fl = (fl >= 0) ? fl + (5.0 / (dec * 10)) : fl - (5.0 / (dec * 10));
	len = (pr == 0 ? ft_intl(fl) + pr : ft_intl(fl) + pr + 1);
	str = ft_strnew(len);
	if ((num = fl * dec) < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[len--] = '\0';
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num = num / 10;
		dec = dec / 10;
		if (dec == 1/* && (pr != 0*/) 
			str[len--] = '.';
	}
	return (str);
}

void			ft_double_print(t_var *id, va_list args)
{
	double 		d;
	long double	ld;
	int			pr;
	char		*str[3];

	pr = 6;
	if (id->dot)
		pr = ft_atoi(id->prec); //Check what happens (and should happen) if id->prec is NULL
	if (ft_strcmp (id->type_spec, "L") == 0)
	{
		ld = va_arg(args, long double);
		str[0] = ft_ftoa(ld, pr);
	}
	else
	{
		d = va_arg(args, double);
		str[0] = ft_ftoa(d, pr);
	}
	if (pr == 0 && ft_strchr_int (id->flags, '#'))
		str[1] = ft_strjoin(str[0], ".");
	else
		str[1] = ft_strdup(str[0]);
	free(str[0]);
	str[2] = ft_double_flags(id, str[1]);
	ft_putstr(str[2]);
	id->count += ft_strlen(str[2]);
	free(str[2]);
}
