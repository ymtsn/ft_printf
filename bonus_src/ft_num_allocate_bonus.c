/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_allocate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:47:04 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/24 17:23:03 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_zero_alloc(char *buf, t_prfb ag, int pres_sign)
{
	ssize_t	strpos;

	if (!ag.pres || ag.len > ag.pres)
		return ;
	strpos = ft_adjust_strpos(ag, pres_sign);
	while (ag.pres-- && strpos >= 0)
		*(buf + strpos--) = '0';
}

void	ft_diu_alloc(long n, char *str, t_prfb ag, int pres_sign)
{
	ssize_t	strpos;

	if (n < 0)
		n = n * -1;
	strpos = ft_adjust_strpos(ag, pres_sign);
	if (n == 0 && !(ag.def_pres == TRUE && ag.pres == 0))
		*(str + strpos) = '0';
	while (n && strpos >= 0)
	{
		*(str + strpos--) = (n % 10) + '0';
		n = n / 10;
	}
	while (strpos > 0 && *(str + strpos) != ' ')
		strpos--;
	if (ag.pl_mn_sp && strpos >= 0)
		*(str + strpos) = ag.pl_mn_sp;
}

static void	ft_ALT_alloc(t_prfb ag, char *str, ssize_t strpos, int alt_sign)
{
	if (ag.alt != ALT || strpos < 1)
		return ;
	while (alt_sign && strpos > 1 && *(str + strpos) != ' ')
		strpos--;
	if ((ag.type == 'x' || ag.type == 'p') && strpos >= 1)
	{
		*(str + strpos--) = 'x';
		*(str + strpos) = '0';
	}
	if (ag.type == 'X' && strpos >= 1)
	{
		*(str + strpos--) = 'X';
		*(str + strpos) = '0';
	}
}

void	ft_pxX_alloc(unsigned long long n, char *str, t_prfb ag, int alt_sign)
{
	ssize_t	strpos;

	if (ag.type == 'p')
		alt_sign = 0;
	strpos = ft_adjust_strpos(ag, alt_sign);
	if (n == 0 && !(ag.def_pres == TRUE && ag.pres == 0))
		*(str + strpos--) = '0';
	if (n == 0 && ag.type != 'p')
		return ;
	while (n && strpos >= 0)
	{
		if (n % 16 < 10)
			*(str + strpos--) = (n % 16) + '0';
		else if (ag.type == 'X')
			*(str + strpos--) = (n % 16) + 55;
		else
			*(str + strpos--) = (n % 16) + 87;
		n = n / 16;
	}
	ft_ALT_alloc(ag, str, strpos, alt_sign);
}
