/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_csper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:32:16 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/03 15:22:11 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

ssize_t	ft_fmt_c(va_list *ap, t_prfb *ag)
{
	unsigned char	nb;
	char			*buf;

	nb = (unsigned char)va_arg(*ap, int);
	ag->len = 1;
	ag->max = ft_get_max(ag->wid, 0, ag->len);
	if (ag->max >= INT_MAX)
		return (ERROR);
	buf = (char *)malloc(ag->max + 1);
	if (buf == NULL)
		return (ERROR);
	buf = (char *)ft_memset(buf, ag->padding, ag->max);
	*(buf + ag->max) = '\0';
	ft_char_alloc(nb, buf, *ag);
	write(1, buf, ag->max);
	free(buf);
	return (ag->max);
}

static void	ft_get_fmt_s_len(char *s, t_prfb *ag)
{
	if (s == NULL)
		ag->len = 6;
	else
		ag->len = ft_strlen(s);
	if (ag->len == 0)
		return ;
	if (ag->def_pres == TRUE && ag->pres < ag->len)
		ag->len = ag->pres;
	if (ag->def_pres == TRUE && ag->pres > ag->len)
		ag->pres = ag->len;
}

ssize_t	ft_fmt_s(va_list *ap, t_prfb *ag)
{
	char	*s;
	char	*buf;

	s = va_arg(*ap, char *);
	ft_get_fmt_s_len(s, ag);
	if (ag->len == 0 && ag->wid == 0)
		return (0);
	ag->max = ft_get_max(ag->wid, 0, ag->len);
	if (ag->max >= INT_MAX)
		return (ERROR);
	buf = (char *)malloc(ag->max + 1);
	if (buf == NULL)
		return (ERROR);
	buf = (char *)ft_memset(buf, ag->padding, ag->max);
	*(buf + ag->max) = '\0';
	if (s != NULL)
		ft_str_alloc(s, buf, *ag);
	else
		ft_str_alloc("(null)", buf, *ag);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ag->max);
}

ssize_t	ft_fmt_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
