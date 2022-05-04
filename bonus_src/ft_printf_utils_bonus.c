/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:15:29 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/10 12:55:57 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_get_num_length_lng_b(long n, t_prfb *ag, int radix)
{
	size_t	counter;

	if (!n && (ag->pl_mn_sp == PLUS || ag->pl_mn_sp == SPACE))
		return (2);
	if (!n)
		return (1);
	counter = 0;
	if (n < 0)
	{
		n = -1 * n;
		counter = 1;
		ag->pl_mn_sp = MINUS;
	}
	while (n)
	{
		n = n / radix;
		counter++;
	}
	if (ag->pl_mn_sp == PLUS || ag->pl_mn_sp == SPACE)
		counter++;
	return (counter);
}

size_t	ft_get_num_length_ull_b(unsigned long long n, t_prfb ag)
{
	size_t	counter;
	int		radix;

	if (!n && ag.type == 'p')
		return (3);
	if (!n)
		return (1);
	if (ag.type == 'u')
		radix = 10;
	else
		radix = 16;
	counter = 0;
	while (n)
	{
		n = n / radix;
		counter++;
	}
	if (ag.alt && radix == 16)
		counter += 2;
	return (counter);
}

size_t	ft_get_max(size_t size1, size_t size2, size_t size3)
{
	if (size1 > size2)
	{
		if (size1 > size3)
			return (size1);
		else
			return (size3);
	}
	else
	{
		if (size2 > size3)
			return (size2);
		else
			return (size3);
	}
}

ssize_t	ft_adjust_strpos(t_prfb ag, int pres_sign)
{
	ssize_t	adjust_strpos;

	if (ag.left_zero == LEFT && ag.pres >= ag.len)
		adjust_strpos = ag.pres + pres_sign;
	else if (ag.left_zero == LEFT)
		adjust_strpos = ag.len;
	else
		adjust_strpos = ag.max;
	if (adjust_strpos > 0)
		adjust_strpos--;
	return (adjust_strpos);
}
