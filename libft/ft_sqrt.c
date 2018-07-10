/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:12:30 by cpaquet           #+#    #+#             */
/*   Updated: 2018/03/20 15:01:22 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sqrt(int nb)
{
	int		i;
	int		result;

	i = 1;
	result = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i <= nb)
	{
		i++;
		result = i * i;
		if (result == nb)
			return (i);
	}
	return (0);
}

double		ft_sqrt_heron(int nb, int precision)
{
	double		result;

	result = 0;
	result = (precision + (nb / precision)) / 2;
	return (result);
}
