/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:16:05 by rklein            #+#    #+#             */
/*   Updated: 2020/01/31 17:51:21 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

/*static char	*ft_zeropad(t_var *id, int size)
{
	char	*z_pad;
	char	*tmp;

	if (ft_atoi(str) >= 0)
	{
		if (ft_strchr_int(id->flags, '+') || ft_strchr_int(id->flags, ' '))
		{
			if (size - 1 <= 0)
				return (str);
			z_pad = ft_strmake('0', (ft_atoi(id->fld_min) - (ft_strlen(str) + 1)));
		}
		else
			z_pad = ft_strmake('0', (ft_atoi(id->fld_min) - (ft_strlen(str))));  
		tmp = ft_strjoin(z_pad, str);
		free(z_pad);
		return (tmp);
	}
	else
	{
		z_pad = ft_strmake('0', (ft_atoi(id->fld_min) - (ft_strlen(str))));
		tmp = ft_strjoin(z_pad, &str[1]);
		free(z_pad);
		return (ft_strjoin("-", tmp));
	}
}

static char	*ft_spacepad(t_var *id, char *str)
{
	char	*s_pad;
	char	*tmp;

	s_pad = ft_strmake(' ', (ft_atoi(id->fld_min) - (ft_strlen(str))));
	if (ft_strchr_int(id->flags, '-'))
		tmp = ft_strjoin(str, s_pad);
	else
		tmp = ft_strjoin(s_pad, str);
	free(s_pad);
	return (tmp);
}*/

char	*ft_double_flags(t_var *id, char *str)
{
	char	*tmp[4];
	int		size;

	size = ft_strlen(str);
	if ((id->sign == '-' || ft_strchr_int(id->flags, '+') || ft_strchr_int(id->flags, ' ')) &&
			ft_strchr_int(id->flags, '0'))
		size++;
	tmp[0] = (ft_strchr_int(id->flags, '0') && !ft_strchr_int(id->flags, '-')) ?
		ft_strmake('0', ft_atoi(id->fld_min) - size) : ft_strnew(0);
	tmp[1] = ft_strjoin(tmp[0], str);
	free(tmp[0]);
	free(str);
	tmp[2] = ft_addsign(id, tmp[1]);
	tmp[3] = (!ft_strchr_int(id->flags, '0')) ? ft_spacepad(id, tmp[2]) : tmp[2];
	return(tmp[3]);
}

/*	sign = ((ft_strchr_int(id->flags, '+') || ft_strchr_int(id->flags, ' ')) && ft_atoi(str) >= 0) ? 1 : 0;
	size = ft_atoi(id->fld_min) - ft_strlen(str);
	if (ft_strchr_int(id->flags, '0') && size > 0)
	{
		tmp = ft_zeropad(id, str, size);
		free(str);
		str = tmp;
	}
	if (sign)
	{
		if (ft_strchr_int(id->flags, '+'))
			tmp = ft_strjoin("+", str);
		else
			tmp = ft_strjoin(" ", str);
		free(str);
		str = tmp;
	}
	if (ft_strchr_int(id->flags, '0') == 0 && (size_t)ft_atoi(id->fld_min) > ft_strlen(str))
	{
		tmp = ft_spacepad(id, str);
		free(str);
		str = tmp;	
	}
	return (str);
}*/

