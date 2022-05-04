/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_allocate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:47:04 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/10 13:12:47 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_char_alloc(long n, char *buf, t_prfb ag)
{
	ssize_t	strpos;

	strpos = ft_adjust_strpos(ag, 0);
	*(buf + strpos) = n;
}

void	ft_str_alloc(char *str, char *buf, t_prfb ag)
{
	ssize_t	strpos;

	if (ag.len == 0)
		return ;
	strpos = ft_adjust_strpos(ag, 0);
	str += ag.len - 1;
	while (ag.len-- && strpos >= 0)
		*(buf + strpos--) = *str--;
}
