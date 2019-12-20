/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:42:01 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:22:25 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslen(const wchar_t *str)
{
	const wchar_t *p_str;

	if (str)
	{
		p_str = str;
		while (*p_str)
			++p_str;
		return (p_str - str);
	}
	else
		return (0);
}
