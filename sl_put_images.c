/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:54:40 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/27 19:54:45 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*f(void *mlx, char *file, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, file, width, height));
}

int	ptr_mlx_put_image_to_window(t_data *data, void *ptr, int i, int line)
{
	return (mlx_put_image_to_window(data->mlx,
			data->mlx_win, ptr, (i * 48), (line * 48)));
}

void	sl_find_images(t_data *data)
{
	data->img_0 = f(data->mlx, "./images/void.xpm", &(data->w), &(data->h));
	data->img_1 = f(data->mlx, "./images/wall.xpm", &(data->w), &(data->h));
	data->img_e = f(data->mlx, "./images/exit.xpm", &(data->w), &(data->h));
	data->img_c = f(data->mlx, "./images/coin.xpm", &(data->w), &(data->h));
	data->img_p = f(data->mlx, "./images/r_w1.xpm", &(data->w), &(data->h));
}

void	sl_put_images(t_data *data)
{
	int	line;
	int	i;

	sl_find_images(data);
	line = -1;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == '0')
				ptr_mlx_put_image_to_window(data, data->img_0, i, line);
			if (data->map[line][i] == '1')
				ptr_mlx_put_image_to_window(data, data->img_1, i, line);
			if (data->map[line][i] == 'E')
				ptr_mlx_put_image_to_window(data, data->img_e, i, line);
			if (data->map[line][i] == 'C')
				ptr_mlx_put_image_to_window(data, data->img_c, i, line);
			if (data->map[line][i] == 'P')
				ptr_mlx_put_image_to_window(data, data->img_p, i, line);
		}
	}
}