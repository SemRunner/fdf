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

void	*ft_clear_table(char **tables, int i)
{
	int index;

	index = 0;
	if (!tables)
		return (NULL);
	while (index < i)
	{
		ft_memdel((void**)&tables[index]);
		index++;
	}
	ft_memdel((void**)&tables);
	return (NULL);
}
