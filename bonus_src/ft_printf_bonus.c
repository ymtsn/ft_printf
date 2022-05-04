/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 08:41:37 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/03 20:26:53 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_out_ap(const char *fmt, t_prfb *ag, va_list *ap)
{
	if (ag->left_zero == ZERO && ag->def_pres == FALSE)
		ag->padding = '0';
	if (*fmt == 'c')
		ag->writelen = ft_fmt_c(ap, ag);
	if (*fmt == 's')
		ag->writelen = ft_fmt_s(ap, ag);
	if (*fmt == 'p')
		ag->writelen = ft_fmt_p(ap, ag);
	if (*fmt == '%')
		ag->writelen = ft_fmt_percent();
	if (*fmt == 'd' || *fmt == 'i')
		ag->writelen = ft_fmt_di(ap, ag);
	if (*fmt == 'u')
		ag->writelen = ft_fmt_u(ap, ag);
	if (*fmt == 'x')
	{
		ag->type = 'x';
		ag->writelen = ft_fmt_xX(ap, ag);
	}
	if (*fmt == 'X')
	{
		ag->type = 'X';
		ag->writelen = ft_fmt_xX(ap, ag);
	}
}

static size_t	ft_atoi_skip(const char **str, t_prfb *ag, va_list *ap)
{
	size_t	buf;
	long	nb;

	buf = 0;
	if (**str == '*')
	{
		(*str)++;
		nb = va_arg(*ap, int);
		if (ag->def_pres == FALSE && nb < 0)
			ag->left_zero = LEFT;
		if (ag->def_pres == TRUE && nb < 0)
		{
			ag->def_pres = FALSE;
			return (0);
		}
		if (nb < 0)
			return ((size_t)(nb * -1));
		else
			return ((size_t)nb);
	}
	while (ft_isdigit(**str))
		buf = buf * 10 + (*(*str)++ - '0');
	return (buf);
}

static void	ft_get_flg_wid_pre(const char **fmt, t_prfb *ag, va_list *ap)
{
	ft_init_ag(ag);
	(*fmt)++;
	while (**fmt && ft_strchr("#0- +", **fmt) != NULL)
	{
		if (**fmt == '#')
			ag->alt = ALT;
		if (**fmt == '0' && ag->left_zero != LEFT)
			ag->left_zero = ZERO;
		if (**fmt == '-')
			ag->left_zero = LEFT;
		if (**fmt == ' ' && ag->pl_mn_sp != PLUS)
			ag->pl_mn_sp = SPACE;
		if (**fmt == '+')
			ag->pl_mn_sp = PLUS;
		(*fmt)++;
	}
	if (ft_isdigit(**fmt) || **fmt == '*')
		ag->wid = ft_atoi_skip(&(*fmt), ag, ap);
	if (**fmt == '.')
	{
		(*fmt)++;
		ag->def_pres = TRUE;
		ag->pres = ft_atoi_skip(&(*fmt), ag, ap);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				ret;
	t_prfb			ag;

	va_start(ap, fmt);
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_get_flg_wid_pre(&fmt, &ag, &ap);
			ft_out_ap(fmt++, &ag, &ap);
			if (ag.writelen == ERROR)
			{
				va_end(ap);
				return (-1);
			}
			ret += ag.writelen;
		}
		else
			ret += write(1, fmt++, 1);
	}
	va_end(ap);
	return (ret);
}
