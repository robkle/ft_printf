#include "printf.h"
#include <stdio.h>

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

static char	*ft_cut_zero(char *str)
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

static char	*ft_enum_g(t_var *id, long double f, int pr)
{
	int	e;
	char	sign;
	char	*str[4];
	
	sign = ((f < 1.0 && f > 0.0) || (f > -1.0 && f < 0.0)) ? '-' : '+';
		e = 0;
	while ((f > 0 && !(f < 10.0 && f >= 1.0)) || (f < 0 && !(f > -10.0 && f <= -1.0)))
	{
		if ((f < 1.0 && f > 0.0) || (f > -1.0 && f < 0.0))
			f = f * 10;
		if (f >= 10.0 || f <= -10.0)
			f = f / 10;
		e++;
	}
	str[0] = ft_ftoa(id, f, pr);
	if (pr == 0 && ft_strchr_int(id->flags, '#'))
		str[1] = ft_strjoin(str[0], ".");
	else
		str[1] = ft_cut_zero(str[0]);
	free(str[0]);
	str[2] = ft_suffix(id->type, sign, e);
	str[3] = ft_strjoin(str[1], str[2]);
	free(str[1]);
	free(str[2]);
	return (str[3]);
}

static char	*ft_g_direct(t_var *id, long double fl)
{
	int	pr;
	int	sn;
	char	*str[3];

	pr = 6;
	if (id->dot)
		pr = ft_atoi(id->prec);
	str[0] = (pr == 0) ? ft_enum_g(id, fl, pr) : ft_enum_g(id, fl, pr - 1);
	sn = pr - ft_sdigits(fl);
	if (sn >= 0)
	{
		str[1] = ft_ftoa(id, fl, sn);
		if (sn == 0 && ft_strchr_int(id->flags, '#'))
			str[2] = ft_strjoin(str[1], ".");
		else
			str[2] = ft_cut_zero(str[1]);
		free(str[1]);
		str[1] = ft_strlen(str[0]) < ft_strlen(str[2]) ? ft_strdup(str[0]) : ft_strdup(str[2]);
		free(str[2]);
	}
	else
		str[1] = ft_strdup(str[0]);
	free(str[0]);
	return (str[1]);
}

void	ft_g_print(t_var *id, va_list args)
{
	double		d;
	long double	ld;
	char		*str[2];

	if (ft_strcmp (id->type_spec, "L") == 0)
	{
		ld = va_arg(args, long double);
		str[0] = ft_g_direct(id, ld);
	}
	else
	{
		d = va_arg(args, double);
		str[0] = ft_g_direct(id, d);
	}
	str[1] = ft_double_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
