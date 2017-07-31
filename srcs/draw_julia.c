/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 21:45:26 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/31 21:45:28 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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