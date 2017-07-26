/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 17:26:40 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/15 21:24:55 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**DRAW
*/

void	mandelbrot_init(t_env *e)
{
	e->x1 = -2.1;
	e->y1 = -1.2;
	e->zoom = 100;
	e->imax = 100;
	e->imx = -(WIDTH / 2) + (WIDTH / 6);
	e->imy = -(HEIGHT / 2) + (HEIGHT / 6);
	mandelbrot_basic(e);
}

void	mandelbrot_basic(t_env *e)
{
	int x;
	int y;

	x = e->imx - 1;
	while (++x < WIDTH + e->imx)
	{
		y = e->imy - 1;
		while (++y < HEIGHT + e->imy)
		{
			e->cr = x / e->zoom + e->x1;
			e->ci = y / e->zoom + e->y1;
			e->zr = 0;
			e->zi = 0;
			if (ft_strcmp("mandelbrot", e->av) == 0)
				mandelbrot(e, x, y);
			else
				brot_run(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	mandelbrot(t_env *e, int x, int y)
{
	int i;

	i = -1;
	while (++i< e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * e->zi * e->tmp + e->ci;
	}
	color(i, e);
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c >> 8;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c >> 16;
}

void	brot_run(t_env *e, int x, int y)
{
	int			i;

	i = -1;
	while (++i < e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * fabsl(e->zi * e->tmp) + e->ci;
	}
	color(i, e);
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c >> 8;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c >> 16;
}

void	julia_init(t_env *e)
{
	e->x1 = -1;
	e->y1 = -1.2;
	e->zoom = 100;
	e->imax = 100;
	e->imx = -(WIDTH / 2) + (WIDTH / 6);
	e->imy = -(HEIGHT / 2) + (HEIGHT / 6);
	e->paramx = WIDTH / 2;
	e->paramy = HEIGHT / 2;
	e->jul = 1;
	e->stop = 0;
	julia_basic(e);
}

void	julia_basic(t_env *e)
{
	int x;
	int	y;

	x = e->imx - 1;
	while (++x < WIDTH + e->imx)
	{
		y = e->imy - 1;
		while (++y < HEIGHT + e->imy)
		{
			e->cr = 0.285;
			e->ci = 0.01;
			e->zr = x / e->zoom + e->x1;
			e->zi = y / e->zoom + e->y1;
			julia_run(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	julia_run(t_env *e, int x, int y)
{
	int			i;

	i = -1;
	while (++i < e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi - 0.8 +
			(0.6 / ((double)e->paramx / (double)WIDTH));
		e->zi = 2 * e->zi * e->tmp + 0.27015 /
			((double)e->paramy / (double)WIDTH);
	}
	color(i, e);
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c >> 8;
	e->str[((x - e->imx) + ((y - e->imy) * WIDTH)) * 4] = e->c >> 16;
}

/*
**EVENT
*/

int		my_mouse(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 || keycode == 1 || keycode == 4 || keycode == 2)
	{
		zoom(keycode, x, y, e);
		return (0);
	}
	return (0);
}

void	zoom(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 || keycode == 1)
	{
		e->imx += x / 5;
		e->imy += y / 5;
		e->zoom *= 1.2;
		e->imx *= 1.2;
		e->imy *= 1.2;
	}
	else if (keycode == 4 || keycode == 2)
	{
		e->imx -= x / 5;
		e->imy -= y / 5;
		e->zoom /= 1.2;
		e->imx /= 1.2;
		e->imy /= 1.2;
	}
	mlx_clear_window(e->mlx, e->win);
	if (ft_strcmp("mandelbrot", e->av) == 0 ||
	ft_strcmp("burningship", e->av) == 0)
		mandelbrot_basic(e);
	else if (ft_strcmp("julia", e->av) == 0)
		julia_basic(e);
}

int		my_key(int keyboard, t_env *e)
{
	if (keyboard == 35)
	{
		if (e->stop == 1)
			e->stop = 0;
		else if (e->stop == 0)
			e->stop = 1;
	}
	else if (keyboard == 53)
	{
		free(e->av);
		free(e);
		exit(EXIT_SUCCESS);
	}
	else if (keyboard == 69 || keyboard == 78 || keyboard == 124
	|| keyboard == 123 || keyboard == 125 || keyboard == 126 || keyboard == 15)
		clean_event(keyboard, e);
	return (0);
}

void	clean_event(int keyboard, t_env *e)
{
	if (keyboard == 69 || keyboard == 78)
	{
		if (keyboard == 69)
			e->imax += 50;
		else if (keyboard == 78)
			e->imax -= 50;
		ft_putstr("Iteration max = ");
		ft_putnbr(e->imax);
		ft_putchar('\n');
	}
	else if (keyboard == 124)
		e->imx -= 20;
	else if (keyboard == 123)
		e->imx += 20;
	else if (keyboard == 125)
		e->imy -= 20;
	else if (keyboard == 126)
		e->imy += 20;
	mlx_clear_window(e->mlx, e->win);
	clen_next(keyboard, e);
}

void	clen_next(int keyboard, t_env *e)
{
	if (keyboard == 15)
	{
		if (ft_strcmp("mandelbrot", e->av) == 0 ||
		ft_strcmp("burningship", e->av) == 0)
			mandelbrot_init(e);
		else if (ft_strcmp("julia", e->av) == 0)
			julia_init(e);
	}
	else
	{
		if (ft_strcmp("mandelbrot", e->av) == 0 ||
		ft_strcmp("burningship", e->av) == 0)
			mandelbrot_basic(e);
		else if (ft_strcmp("julia", e->av) == 0)
			julia_basic(e);
	}
}

/*
**INIT
*/

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac == 2 && (ft_strcmp("julia", av[1]) == 0 ||
	ft_strcmp("mandelbrot", av[1]) == 0 ||
	ft_strcmp("burningship", av[1]) == 0))
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
		ft_putendl_fd("Usage <filename> [mandelbrot/julia/burningship]", 2);
	return (0);
}

void	main_if(t_env *e)
{
	if (ft_strcmp("mandelbrot", e->av) == 0 ||
	ft_strcmp("burningship", e->av) == 0)
		mandelbrot_init(e);
	else if (ft_strcmp("julia", e->av) == 0)
		julia_init(e);
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