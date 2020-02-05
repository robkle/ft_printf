/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:40:29 by rklein            #+#    #+#             */
/*   Updated: 2020/02/05 15:16:25 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_sdigits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (i);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_cut_zero(char *str)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	i = ft_strlen(tmp) - 1;
	while (tmp[i] == '0' && i > 0)
		tmp[i--] = '\0';
	if (tmp[i] == '.' && i > 0)
		tmp[i] = '\0';
	return (tmp);
}

static char	*ft_g_direct(t_var *id, long double fl)
{
	int		pr;
	char	*str[3];

	str[0] = ft_enum(id, fl);
	ft_printf("after enum: $%s$\n", str[0]);
	pr = id->dot ? ft_atoi(id->prec) : 6;
	fl = ft_prep(id, fl, pr);
	pr = pr - ft_sdigits(fl);
	if (sn >= 0)
	{
		str[1] = ft_ftoa(id, fl, sn);
		ft_printf("after ftoa: $%s$\n", str[1]);
		if (sn == 0 && ft_strchr_int(id->flags, '#'))
			str[2] = ft_strjoin(str[1], ".");
		else
			str[2] = ft_cut_zero(str[1]);
		free(str[1]);
		str[1] = ft_strlen(str[0]) < ft_strlen(str[2]) ? ft_strdup(str[0])
			: ft_strdup(str[2]);
		free(str[2]);
	}
	else
		str[1] = ft_strdup(str[0]);
	free(str[0]);
	return (str[1]);
}

void		ft_g_print(t_var *id, va_list args)
{
	long double	ld;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "L") == 0)
	{
		ld = (long double)va_arg(args, long double);
		str[0] = ft_g_direct(id, ld);
	}
	else
	{
		ld = (long double)va_arg(args, double);
		str[0] = ft_g_direct(id, ld);
	}
	str[1] = ft_double_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
