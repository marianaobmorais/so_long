/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/19 19:16:16 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// /* typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }	t_data; */

// void	pixel_to_img(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_len + x * (data->bpp/8));
// 	*(unsigned int*)dst = color;
// }

// int	close_win(int keycode, t_game *game)
// {
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_window(game->mlx, game->window);
// 		exit(0);
// 	}
// 	return (0);
// }

// /* int hello(int x, int y, t_game *game)
// {
// 	ft_printf("Hello! Mouse entered window at (%d, %d)\n", x, y);
	
// 	mlx_string_put(game->mlx, game->window, 100, 300, 0x00FFA000, "Hello!");
// 	return (0);
// } */

// int	key_hook(int keycode, t_game *game)
// {
// 	if (keycode == 65364)
// 	{
// 		static int i = 100;
// 		ft_printf("Hello from key_hook!\n");
// 		mlx_string_put(game->mlx, game->window, i, 300, 0x00FFA000, "Hello!");
// 		i += 50;
// 	}
// 	return (0);
// }

// int	mouse_hook(int keycode/* , t_game *game */)
// {
// 	if (keycode)
// 	{
// 		ft_printf("%d\n",keycode);
// 		//mlx_string_put(game->mlx, game->window, 110, 300, 0x00FFA000, "left click!");
// 	}
// 	/* if (keycode == 2)
// 	{
// 		ft_printf("middle click!\n");
// 		//mlx_string_put(game->mlx, game->window, 115, 100, 0x00FFA000, "middle click!");
// 	} */
// 	return(0);
// }
// int	render(t_game *game, t_data *data)
// {
// 	static int	frame = 0;
// 	int color = 0x00FFC000;
// 	int	width = 600;
// 	int	height = 400;
	
// 	mlx_clear_window(game->mlx, game->window);
// 	data->x += (frame * 2) % width;
// 	data->y += (frame *2) % height;
// 	pixel_to_img(data, data->x, data->y, color);
// 	mlx_put_image_to_window(game->mlx, game->window, data->img, 0, 0);
// 	frame++;
// 	return (0);
// }

// int	main(void)
// {
// 	t_game	game;
// 	t_data	data;
	
// 	game.mlx = mlx_init();
// 	game.window = mlx_new_window(game.mlx, 600, 400, "so_long");
// 	data.img = mlx_new_image(game.mlx, 600, 400);
// 	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
// 	data.x = 0;
	
// 	int i = 0;
// 	int	j = 1;
// 	while (i <= 100)
// 	{
// 		pixel_to_img(&data, i, j, 0x00FF0000);
// 		pixel_to_img(&data, j, i, 0x00FFA000);
// 		i++;
// 		j++;
// 	}
// 	mlx_put_image_to_window(game.mlx, game.window, data.img, 0, 0);
// 	//mlx_hook(game.window, 7, 1L<<4, hello, &game);
// 	mlx_key_hook(game.window, key_hook, &game);
// 	mlx_mouse_hook(game.window, mouse_hook, &game);
// 	mlx_hook(game.window, 2, 1L<<0, close_win, &game);
// 	mlx_loop_hook(game.mlx, render, &game);
// 	mlx_loop(game.mlx);

// 	return (0);
// }


void    pixel_to_img(t_data *data, int x, int y, int color)
{
    if (x < 0 || x >= 600 || y < 0 || y >= 400)
        return; // Ensure x and y are within bounds

    char    *dst;

    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

/* int render(t_game *game)
{
    static int frame = 0;
    int color = 0x00FFC000; // Yellow color
    t_data *data = game->data;

    // Clear the image buffer
    ft_memset(data->addr, 0, 600 * 400 * (data->bpp / 8));

    // Update position for the next frame
    data->x = (frame * 2) % 600;
    data->y = (frame * 2) % 400;

    // Draw a simple moving dot
    pixel_to_img(data, data->x, data->y, color);

    // Draw image to window
    mlx_put_image_to_window(game->mlx, game->window, data->img, 0, 0);

    frame++;
    return (0);
}

int main(void)
{
    t_game game;
    t_data data;
    
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, 600, 400, "so_long");
    data.img = mlx_new_image(game.mlx, 600, 400);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    data.x = 0;
    data.y = 0;

    game.data = &data;

    mlx_loop_hook(game.mlx, render, &game);
    mlx_loop(game.mlx);

    return (0);
} */