/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:52:17 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/10 12:42:38 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"
# define ERROR -1
# define FALSE 0
# define TRUE 1
# define ALT 1
# define LEFT 2
# define PLUS 43
# define SPACE 32
# define ZERO 48
# define MINUS 45
typedef struct s_prfb{
	int		alt;
	int		left_zero;
	int		pl_mn_sp;
	int		def_pres;
	size_t	wid;
	size_t	pres;
	size_t	len;
	size_t	max;
	ssize_t	writelen;
	char	padding;
	char	type;
}			t_prfb;
ssize_t	ft_adjust_strpos(t_prfb ag, int pres_sign);
void	ft_zero_alloc(char *buf, t_prfb ag, int pres_sign);
void	ft_char_alloc(long n, char *str, t_prfb ag);
void	ft_str_alloc(char *s, char *str, t_prfb ag);
void	ft_diu_alloc(long n, char *str, t_prfb ag, int pres_sign);
void	ft_pxX_alloc(unsigned long long n, char *str, t_prfb ag, int alt);
size_t	ft_get_num_length_lng_b(long n, t_prfb *ag, int radix);
size_t	ft_get_num_length_ull_b(unsigned long long n, t_prfb ag);
size_t	ft_get_max(size_t size1, size_t size2, size_t size3);
ssize_t	ft_fmt_di(va_list *ap, t_prfb *ag);
ssize_t	ft_fmt_xX(va_list *ap, t_prfb *ag);
ssize_t	ft_fmt_u(va_list *ap, t_prfb *ag);
ssize_t	ft_fmt_p(va_list *ap, t_prfb *ag);
ssize_t	ft_fmt_c(va_list *ap, t_prfb *ag);
ssize_t	ft_fmt_s(va_list *ap, t_prfb *ag);
ssize_t	ft_fmt_percent(void);
void	ft_init_ag(t_prfb *ag);
int		ft_printf(const char *fmt, ...);
#endif
