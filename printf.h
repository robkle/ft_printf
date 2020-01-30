/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:32:26 by rklein            #+#    #+#             */
/*   Updated: 2020/01/30 15:05:23 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <stdbool.h>
# include <limits.h>

typedef	struct	s_var
{
	char	sign[1];
	char	flags[6];
	char	fld_min[11];
	_Bool	dot;
	char	prec[3];
	char	type_spec[3];
	char	type;
	int	count;
}		t_var;

/*MAIN FUNCTIONS*/
int		ft_printf(const char *format, ...);
void	ft_double_print(t_var *id, va_list args);
char	*ft_ftoa(long double fl, int pr);
void	ft_int_print(t_var *id, va_list args);
void	ft_uint_print(t_var *id, va_list args);
char    *ft_spad_uint(t_var *id, char *str);
void	ft_base_print(t_var *id, va_list args);
char	*ft_base(uintmax_t value, t_var *id);
void	ft_addr_print(t_var *id, va_list args);
char 	*ft_zpad_uint(t_var *id, int size);
void	ft_char_print(t_var *id, va_list args);
int		ft_strchr_int(char *s, int c);
char	*ft_double_flags(t_var *id, char *str);
char	*ft_int_flags(t_var *id, char *str);
char	*ft_strmake(char c, int size);
char	*ft_spacepad(t_var *id, char *str);
char	*ft_uint_flags(t_var *id, char *str);
void	ft_e_print(t_var *id, va_list args);
char	*ft_suffix(char type, char sign, int e);
void	ft_g_print(t_var *id, va_list args);
void	ft_free_str(char **str, int s);
int		ft_free_id(t_var *id);
/*LIBFT FUNCTIONS*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr(char const *s);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);

#endif
