/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:19:37 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/03 15:23:27 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_ag(t_prfb *ag)
{
	ag->alt = 0;
	ag->left_zero = 0;
	ag->pl_mn_sp = 0;
	ag->def_pres = FALSE;
	ag->wid = 0;
	ag->pres = 0;
	ag->len = 0;
	ag->max = 0;
	ag->writelen = 0;
	ag->padding = ' ';
	ag->type = 0;
}
