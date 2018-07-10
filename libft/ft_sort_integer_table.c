/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:27:09 by cpaquet           #+#    #+#             */
/*   Updated: 2017/09/04 16:22:38 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int temp;
	int n;
	int k;

	temp = 0;
	size--;
	k = size;
	while (k > 0)
	{
		n = size;
		while (n > 0)
		{
			if (tab[n] < tab[n - 1])
			{
				temp = tab[n];
				tab[n] = tab[n - 1];
				tab[n - 1] = temp;
			}
			n--;
		}
		k--;
	}
}
