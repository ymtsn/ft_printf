/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_diuoxXp_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:36:39 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/03 16:21:18 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

ssize_t	ft_fmt_di(va_list *ap, t_prfb *ag)
{
	int		nb;
	char	*buf;
	int		pres_sign;

	nb = va_arg(*ap, int);
	if (nb == 0 && ag->def_pres == TRUE && ag->pres == 0 && ag->wid == 0)
		return (0);
	ag->len = ft_get_num_length_lng_b(nb, ag, 10);
	pres_sign = 0;
	if (ag->def_pres == TRUE && ag->pres >= ag->len && ag->pl_mn_sp > 0)
		pres_sign = 1;
	ag->max = ft_get_max(ag->wid, ag->pres + pres_sign, ag->len);
	buf = (char *)malloc(ag->max + 1);
	if (buf == NULL)
		return (ERROR);
	buf = (char *)ft_memset(buf, ag->padding, ag->max);
	*(buf + ag->max) = '\0';
	ft_zero_alloc(buf, *ag, pres_sign);
	ft_diu_alloc(nb, buf, *ag, pres_sign);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ag->max);
}

ssize_t	ft_fmt_u(va_list *ap, t_prfb *ag)
{
	unsigned int	nb;
	char			*buf;

	nb = va_arg(*ap, int);
	if (nb == 0 && ag->def_pres == TRUE && ag->pres == 0 && ag->wid == 0)
		return (0);
	ag->type = 'u';
	ag->len = ft_get_num_length_ull_b(nb, *ag);
	ag->max = ft_get_max(ag->wid, ag->pres, ag->len);
	if (ag->max >= INT_MAX)
		return (ERROR);
	buf = (char *)malloc(ag->max + 1);
	if (buf == NULL)
		return (ERROR);
	buf = (char *)ft_memset(buf, ag->padding, ag->max);
	*(buf + ag->max) = '\0';
	ft_zero_alloc(buf, *ag, 0);
	ft_diu_alloc(nb, buf, *ag, 0);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ag->max);
}

ssize_t	ft_fmt_xX(va_list *ap, t_prfb *ag)
{
	unsigned int	nb;
	char			*buf;
	int				alt_sign;

	nb = va_arg(*ap, unsigned int);
	if (nb == 0 && ag->def_pres == TRUE && ag->pres == 0 && ag->wid == 0)
		return (0);
	ag->len = ft_get_num_length_ull_b(nb, *ag);
	alt_sign = 0;
	if (nb && ag->def_pres == TRUE && ag->pres > ag->len && ag->alt == ALT)
		alt_sign = 2;
	ag->max = ft_get_max(ag->wid, ag->pres + alt_sign, ag->len);
	if (ag->max >= INT_MAX)
		return (ERROR);
	buf = (char *)malloc(ag->max + 1);
	if (buf == NULL)
		return (ERROR);
	buf = (char *)ft_memset(buf, ag->padding, ag->max);
	*(buf + ag->max) = '\0';
	ft_zero_alloc(buf, *ag, alt_sign);
	ft_pxX_alloc(nb, buf, *ag, alt_sign);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ag->max);
}

ssize_t	ft_fmt_p(va_list *ap, t_prfb *ag)
{
	unsigned long long	nb;
	char				*buf;

	nb = (unsigned long long)va_arg(*ap, void *);
	ag->alt = ALT;
	ag->type = 'p';
	ag->len = ft_get_num_length_ull_b(nb, *ag);
	ag->max = ft_get_max(ag->wid, ag->pres, ag->len);
	if (ag->max >= INT_MAX)
		return (ERROR);
	buf = (char *)malloc(ag->max + 1);
	buf = (char *)ft_memset(buf, ag->padding, ag->max);
	if (buf == NULL)
		return (ERROR);
	*(buf + ag->max) = '\0';
	ft_pxX_alloc(nb, buf, *ag, 0);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ag->max);
}
