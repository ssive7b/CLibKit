/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:02:55 by sstoev            #+#    #+#             */
/*   Updated: 2024/09/22 12:50:20 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len_temp;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		if (src_len >= size)
			len_temp = size - 1;
		else
			len_temp = src_len;
		if (dst && len_temp > 0)
			ft_memcpy(dst, src, len_temp);
		dst[len_temp] = '\0';
	}
	return (src_len);
}
