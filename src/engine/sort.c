/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:02:38 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/20 17:46:14 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	swap(t_inter *a, t_inter *b)
{
	t_inter	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(t_intrs *array, int low, int high)
{
	float	pivot;
	int		i;
	int		j;

	pivot = array->i[high].t;
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (array->i[j].t <= pivot)
		{
			i++;
			swap(&array->i[i], &array->i[j]);
		}
		j++;
	}
	swap(&array->i[i + 1], &array->i[high]);
	return (i + 1);
}

/**
 * @brief Quicksort implementation for intersection array
 *
 * @param array the inters array to be sorted
 * @param low usually is 0 (recurstion uses it deferently)
 * @param high the number of elements usually size - 1
 */
void	quicksort(t_intrs *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}
