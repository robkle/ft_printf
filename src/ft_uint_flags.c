/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:38:21 by rklein            #+#    #+#             */
/*   Updated: 2020/01/16 10:46:32 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_b_prefix(t_var *id, char *str)
{
	char *s;

	if (ft_strcmp(id->type_spec, "hh") == 0)
		s = ft_strmake('0', 8 - ft_strlen(str));
	else if (ft_strcmp(id->type_spec, "h") == 0)
		s = ft_strmake('0', 16 - ft_strlen(str));
	else if (ft_strcmp(id->type_spec, "l") == 0 || ft_strcmp(id->type_spec, "ll") == 0)
		s = ft_strmake('0', 64 - ft_strlen(str));
	else
		s = ft_strmake('0', 32 - ft_strlen(str));
	return (s);
}

static char	*ft_prefix(t_var *id, char *str)
{
	char	*s;

	if (id->type == 'b')
		s = ft_b_prefix(id, str);
	if (id->type == 'x')
		s = ft_strdup("0x");
	if (id->type == 'X')
		s = ft_strdup("0X");
	if (id->type =='o')
		s = ft_strdup("0");
	else
		s = NULL;
	return (s);
}

static char	*ft_spad_uint(t_var *id, char *str)
{
	char	*tmp;

	if (ft_strchr_int(id->flags, '0') == 0 && (size_t)ft_atoi(id->fld_min) > ft_strlen(str))
		tmp = ft_spacepad(id, str);
	else
		tmp = ft_strdup(str);
	free(str);
	return (tmp);
}

char	*ft_uint_flags(t_var *id, char *str)
{
	char	*tmp[3];
	int		size;

	size = ft_atoi(id->fld_min) - ft_strlen(str); 
	if (ft_strchr_int(id->flags, '#') && id->type != 'u')
	{
		tmp[0] = ft_prefix(id, str);
		size += ft_strlen(tmp[0]);
	}
	if (ft_strchr_int(id->flags, '0'))
	{
		tmp[1] = ft_strmake('0', size);
		tmp[2] = ft_strjoin(tmp[1], str);
		free(tmp[1]);
		free(str);
		str = tmp[2];
	}
	if (ft_strchr_int(id->flags, '#') && id->type != 'u')
	{
		tmp[2] = ft_strjoin(tmp[0], str);
		free (tmp[0]);
		free(str);
		str = tmp[2];
	}
	return (ft_spad_uint(id, str));
}
