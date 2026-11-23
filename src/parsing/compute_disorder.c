/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   compute_disorder.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: paziehen <paziehen@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 20:04:31 by paziehen         #+#    #+#              */
/*   Updated: 2026/11/23 17:19:38 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function for calculating disorder metric:
 * Return is in unisgned int and will be unformated.
 * Return unformated:	XXX for a disorder value	< 10%
 *			XXXX for a disorder value	> 10%
 *			0 for no disorder at all and array size < 2
 * To match the output asked by the subject, we will need to put a '.' between
 * the second and third to last digit and a '%' at the end. If there is less
 * than 3 digits we need to add a leading 0.
 */
unsigned int	compute_disorder(int *arr, size_t size)
{
	unsigned long	mistakes;
	unsigned long	total_pairs;
	size_t			i;
	size_t			j;

	if (size < 2)
		return (0);
	total_pairs = 0;
	mistakes = 0;
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j <= size - 1)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
		}
	}
	return ((unsigned int)((mistakes * 10000) / total_pairs));
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	int	arr[] = {4, 3, 2, 1};
//
// 	printf("%lu\n", compute_disorder(arr, 4));
// }
