/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <smight@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 00:26:01 by smight            #+#    #+#             */
/*   Updated: 2019/04/21 00:27:04 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_clear_table(char **table, int i)
{
	int index;

	index = 0;
	while (index < i)
	{
		//ft_memdel((void**)&table[index++]);
		table[index++] = NULL;
	}
	//ft_memdel((void**)&table);
	return (0);
}
