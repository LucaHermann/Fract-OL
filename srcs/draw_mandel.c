/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 21:43:01 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/31 21:43:03 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
				burn_run(e, x, y);
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

void	burn_run(t_env *e, int x, int y)
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