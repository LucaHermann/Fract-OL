/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 21:48:13 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/31 21:48:17 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac == 2 && (ft_strcmp("julia", av[1]) == 0 ||
	ft_strcmp("mandelbrot", av[1]) == 0 ||
	ft_strcmp("burningship", av[1]) == 0 ||
	ft_strcmp("buddhabrot", av[1]) == 0))
	{
		if (!(e = (t_env *)malloc(sizeof(t_env))))
			return (-1);
		if (!(e->av = (char *)malloc(sizeof(char) * ft_strlen(av[1]) + 1)))
			return (-1);
		ft_strcpy(e->av, av[1]);
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fract'ol");
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->str = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->en));
		e->jul = 0;
		main_if(e);
	}
	else
		ft_putendl_fd("Usage <filename> [mandelbrot/julia/burningship/buddhabrot]", 2);
	return (0);
}

void	main_if(t_env *e)
{
	if (ft_strcmp("mandelbrot", e->av) == 0 ||
	ft_strcmp("burningship", e->av) == 0)
		mandelbrot_init(e);
	else if (ft_strcmp("julia", e->av) == 0)
		julia_init(e);
	else if (ft_strcmp("buddhabrot", e->av) == 0)
		buddhabrot_init(e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move, e);
	mlx_mouse_hook(e->win, my_mouse, e);
	mlx_hook(e->win, 2, 3, my_key, e);
	mlx_loop(e->mlx);
}

void	color(int i, t_env *e)
{
	int r;
	int g;
	int b;

	if (i == e->imax)
		e->c = 0x00000000;
	else
	{
		r = (i * 5) * 2;
		g = (255 - (i * 10)) * 2;
		b = (255 - (i * 2)) * 2;
		e->c = (r << 16) + (g << 8) + b;
	}
}

int		mouse_move(int x, int y, t_env *e)
{
	if ((x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	&& e->jul == 1 && e->stop == 0)
		return (0);
	if (e->jul == 1 && e->stop == 0)
	{
		e->paramx = x;
		e->paramy = y;
		mlx_clear_window(e->mlx, e->win);
		julia_basic(e);
	}
	return (0);
}