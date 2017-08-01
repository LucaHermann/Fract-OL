/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 17:27:14 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/26 18:27:19 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 400
# define HEIGHT 400
# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L<<6)
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>

typedef struct 		s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			s_l;
	int			en;
	char		*str;
	char		*av;
	int			imax;
	int			imx;
	int			imy;
	int			paramx;
	int			paramy;
	int			stop;
	int			jul;
	int			c;
	long double	tmpixel;
	long double tmp;
	long double	x1;
	long double	y1;
	long double	zoom;
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
}					t_env;

/*
**DRAW
*/

void	mandelbrot_init(t_env *e);
void	mandelbrot_basic(t_env *e);
void	mandelbrot(t_env *e, int x, int y);
void	burn_run(t_env *e, int x, int y);
void	julia_init(t_env *e);
void	julia_basic(t_env *e);
void	julia_run(t_env *e, int x, int y);
void	buddhabrot_init(t_env *e);
void	buddhabrot_basic(t_env *e);
void	buddhabrot(t_env *e, int x, int y);

/*
**EVENT
*/

int		my_mouse(int keycode, int x, int y, t_env *e);
void	zoom(int keycode, int x, int y, t_env *e);
int		my_key(int keyboard, t_env *e);
void	clean_event(int keyboard, t_env *e);
void	clean_next(int keyboard, t_env *e);

/*
**INIT
*/

int		main(int ac, char **av);
void	main_if(t_env *e);
void	color(int i, t_env *e);
int		mouse_move(int x, int y, t_env *e);

#endif