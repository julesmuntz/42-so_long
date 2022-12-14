/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:54:49 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/18 11:33:53 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_count(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	data->e_count = 1;
	data->c_count = 0;
	data->p_count = 0;
	data->c_count_t = 0;
	while (data->map[line] && data->map_copy[line])
	{
		i = 0;
		while (data->map[line][i] && data->map_copy[line][i])
		{
			if (data->map[line][i] == 'C')
				data->c_count++;
			if (data->map_copy[line][i] == 'C')
				data->c_count_t++;
			i++;
		}
		line++;
	}
}

void	sl_score(t_data *data)
{
	char	*nb;

	nb = ft_itoa(data->p_count);
	mlx_string_put(data->mlx, data->window, 8, 20, 0xFFFFFF, "SCORE");
	mlx_string_put(data->mlx, data->window, 8, 38, 0xFFFF00, nb);
	mlx_string_put(data->mlx, data->window, 64, 20, 0xFFFFFF, "HI-SCORE");
	if (data->p_count < 42)
		mlx_string_put(data->mlx, data->window, 64, 38, 0xFFD700, "42");
	else
		mlx_string_put(data->mlx, data->window, 64, 38, 0x00FFFF, nb);
	free(nb);
}

int	sl_quit(t_data *data)
{
	if (data->c_count == 0)
	{
		ft_printf("Finished with %d moves!\n", data->p_count + 1);
		sl_free(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	sl_cross(t_data *data)
{
	ft_printf("So long!\n");
	sl_free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	sl_key(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_printf("So long!\n");
		sl_free(data);
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
	return (0);
}
