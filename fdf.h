/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:06:43 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/03 18:00:32 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct 
{
	int	width;
	int	height;
	int	**z_matrix;
	int zoom;
	int color;
	int shift_x;
	int shift_y;
	double angle;
	void	*mlx_ptr; //знать в какое окно выводить пиксель
	void	*win_ptr;
}			fdf;

void	read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

#endif
