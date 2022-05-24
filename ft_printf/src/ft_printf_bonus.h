/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:16:29 by darian            #+#    #+#             */
/*   Updated: 2022/04/01 22:33:22 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

# include <stdio.h>
# include "../../libft/libft.h"
# include "limits.h"

int				count_args(char const *str);
int				is_type(char c);

int				space_flag(va_list args, char c1, char c2, int *nb);
int				hashtag_flag(va_list args, char c1, char c2, int *nb);
int				plus_flag(va_list args, char c1, char c2, int *nb);

int				is_flag(char *str, int i);
int				call_flags_functions(va_list args, char c1, char c2, int *nb);

int				call_function(va_list args, char const *str, int i, int *nb);

void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			ft_putnbr_unsigned(unsigned int n);
char			*ft_itoa_llu(unsigned long long nb);
char			*str_rev(char *str);

void			neg_case(char *nb, int *i, int *neg);
unsigned int	val(char c, int lower);
int				size_nb_base_llu(unsigned long long nb, int base_len);
long long		val_llu(char c);
unsigned int	base_to_dec(char *nb, char *base);
char			*convert_hexa(char *nb, int *len, int maj);
int				size_nb_base(unsigned int nb, unsigned int base_len);
int				ft_printf(const char *str, ...);
int				size_nb(int nbr);
int				size_nb_unsigned(unsigned int nbr);
int				print_pointer(unsigned long long pointer, int *nb);
char			*base_converter_llu(char *nb, char *base_from,
					char *base_to, int *len);
char			*negative_dec_to_hex(long nb);
char			*str_rev(char *str);
char			*base_converter(char *nb, char *base_from,
					char *base_to, int *len);

#endif