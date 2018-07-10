/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:30:20 by cpaquet           #+#    #+#             */
/*   Updated: 2018/02/27 09:59:23 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int value, int power)
{
	int		result;

	result = 0;
	if (value > 46340)
		return (-1);
	if (power == 0)
		return (1);
	result = value * ft_power(value, power - 1);
	return (result);
}
