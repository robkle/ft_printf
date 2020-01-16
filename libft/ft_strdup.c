/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:26:24 by rklein            #+#    #+#             */
/*   Updated: 2020/01/16 13:00:01 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(*dup) * i + 1);
	if (dup == 0)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = src[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
