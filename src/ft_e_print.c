#include "printf.h"
#include <stdio.h>

char	*ft_suffix(char type, char sign, int e)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = ft_toupper(type) == 'E' ? type : type - 2;
	str[1] = sign;
	str[3] = e % 10 + '0';
	e /= 10;
	str[2] = e % 10 + '0';
	return (str);
}

static long double	ft_epower(long double f, int *e)
{
	while ((f > 0 && !(f < 10.0 && f >= 1.0)) || (f < 0 && !(f > -10.0 && f <= -1.0)))
	{
		if ((f < 1.0 && f > 0.0) || (f > -1.0 && f < 0.0))
			f = f * 10;
		if (f >= 10.0 || f <= -10.0)
			f = f / 10;
		*e = *e + 1;
	}
	return (f);
}

static char	*ft_enum(t_var *id, long double f)
{
	int	e;
	int	pr;
	char	sign;
	char	*str[4];
	
	pr = 6;
	if (id->dot)
		pr = ft_atoi(id->prec);
	sign = ((f < 1.0 && f > 0.0) || (f > -1.0 && f < 0.0)) ? '-' : '+';
	e = 0;
	f = ft_epower(f, &e);
	str[0] = ft_ftoa(id,f, pr);
	if (pr == 0 && ft_strchr_int(id->flags, '#'))
		str[1] = ft_strjoin(str[0], ".");
	else
		str[1] = ft_strdup(str[0]);
	free(str[0]);
	str[2] = ft_suffix(id->type, sign, e);
	str[3] =ft_strjoin(str[1], str[2]);
	free(str[1]);
	free(str[2]);
	return (str[3]);
}

void	ft_e_print(t_var *id, va_list args)
{
	double		d;
	long double	ld;
	char		*str[2];

	if (ft_strcmp (id->type_spec, "L") == 0)
	{
		ld = va_arg(args, long double);
		str[0] = ft_enum(id, ld);
	}
	else
	{
		d = va_arg(args, double);
		str[0] = ft_enum(id, d);
	}
	str[1] = ft_double_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
