/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:16:05 by rklein            #+#    #+#             */
/*   Updated: 2020/01/24 11:53:58 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

static char	*ft_zeropad(t_var *id, char *str, int size)
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

/*char	*ft_spacepad(t_var *id, char *str)
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
}*/ // DELETE THIS WHOLE FUNCTION IF IDENTICAL TO THE ONE IN THE INT_FLAG FILE

char	*ft_double_flags(t_var *id, char *str)
{
	char	*tmp;
	int		plus;
	int		size;

	plus = ((ft_strchr_int(id->flags, '+') || ft_strchr_int(id->flags, ' ')) && ft_atoi(str) >= 0) ? 1 : 0;
	size = ft_atoi(id->fld_min) - ft_strlen(str);
	if (ft_strchr_int(id->flags, '0') && size > 0)
	{
		tmp = ft_zeropad(id, str, size);
		free(str);
		str = tmp;
	}
	if (plus)
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
}

