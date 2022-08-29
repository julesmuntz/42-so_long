/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:54:49 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/29 20:53:14 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_press(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_printf("So long!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	sl_press(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->window);
		ft_printf("So long!\n");
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_w)
		sl_up(data);
	else if (key == XK_a)
		sl_left(data);
	else if (key == XK_s)
		sl_down(data);
	else if (key == XK_d)
		sl_right(data);
	sl_images(data);
	return (0);
}