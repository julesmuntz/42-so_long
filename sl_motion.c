/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_motion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:39:44 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/01 15:14:23 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_up(t_data *data)
{
	if (data->map[data->p_line - 1][data->p_char] != '1')
	{
		if (data->map[data->p_line - 1][data->p_char] == 'E'
				&& data->c_count == 0)
		{
			data->p_line--;
			sl_quit(data);
		}
		if (data->map[data->p_line - 1][data->p_char] != 'E')
		{
			if (data->map[data->p_line - 1][data->p_char] == 'C')
				data->c_count--;
			data->p_line--;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line + 1][data->p_char] = '0';
			data->p_count++;
			if (data->p_count == 1)
				ft_printf("You did %d move.\n", data->p_count);
			else
				ft_printf("You did %d moves.\n", data->p_count);
		}
	}
}

void	sl_left(t_data *data)
{
	if (data->map[data->p_line][data->p_char - 1] != '1')
	{
		if (data->map[data->p_line][data->p_char - 1] == 'E'
				&& data->c_count == 0)
		{
			data->p_char--;
			sl_quit(data);
		}
		if (data->map[data->p_line][data->p_char - 1] != 'E')
		{
			if (data->map[data->p_line][data->p_char - 1] == 'C')
				data->c_count--;
			data->p_char--;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line][data->p_char + 1] = '0';
			data->p_count++;
			if (data->p_count == 1)
				ft_printf("You did %d move.\n", data->p_count);
			else
				ft_printf("You did %d moves.\n", data->p_count);
		}
	}
}

void	sl_down(t_data *data)
{
	if (data->map[data->p_line + 1][data->p_char] != '1')
	{
		if (data->map[data->p_line + 1][data->p_char] == 'E'
				&& data->c_count == 0)
		{
			data->p_line++;
			sl_quit(data);
		}
		if (data->map[data->p_line + 1][data->p_char] != 'E')
		{
			if (data->map[data->p_line + 1][data->p_char] == 'C')
				data->c_count--;
			data->p_line++;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line - 1][data->p_char] = '0';
			data->p_count++;
			if (data->p_count == 1)
				ft_printf("You did %d move.\n", data->p_count);
			else
				ft_printf("You did %d moves.\n", data->p_count);
		}
	}
}

void	sl_right(t_data *data)
{
	if (data->map[data->p_line][data->p_char + 1] != '1')
	{
		if (data->map[data->p_line][data->p_char + 1] == 'E'
				&& data->c_count == 0)
		{
			data->p_char++;
			sl_quit(data);
		}
		if (data->map[data->p_line][data->p_char + 1] != 'E')
		{
			if (data->map[data->p_line][data->p_char + 1] == 'C')
				data->c_count--;
			data->p_char++;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line][data->p_char - 1] = '0';
			data->p_count++;
			if (data->p_count == 1)
				ft_printf("You did %d move.\n", data->p_count);
			else
				ft_printf("You did %d moves.\n", data->p_count);
		}
	}
}
