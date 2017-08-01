/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 21:47:10 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/31 21:47:31 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	clean_next(keyboard, e);
}

void	clean_next(int keyboard, t_env *e)
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