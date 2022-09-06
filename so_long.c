/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/06 23:07:21 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_start(t_data data)
{
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(EXIT_FAILURE);
	if (sl_errors(data) == TRUE)
		return (exit(EXIT_FAILURE), TRUE);
	if (sl_invalid_chars(data) == TRUE)
		return (exit(EXIT_FAILURE), TRUE);
	sl_count(&data);
	sl_locate(&data);
	data.window = mlx_new_window(data.mlx,
			data.nb_char * 48, data.nb_line * 48, "DIG DUG");
	sl_find_images(&data);
	sl_images(&data);
	mlx_hook(data.window, KeyPress, KeyPressMask, &sl_key, &data);
	mlx_hook(data.window, ClientMessage, 0, &sl_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc != 2)
		return (ft_printf("Error\nYou need a map path in the 1st argument.\n"));
	ft_bzero(&data, sizeof(t_data));
	data.map = sl_getmap(&data, arv[1]);
	if (sl_invalid_extension(arv[1]) == FALSE)
	{
		sl_free_map(&data);
		return (ft_printf("Error\nNot a \".ber\" file.\n"), FALSE);
	}
	sl_start(data);
	return (0);
}
