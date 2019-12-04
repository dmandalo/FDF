/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:19:10 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/04 20:55:05 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char *line;
	int	fd;
	int	height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	int	width;
	int fd;
	char *line;
	
	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' '); //split
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line) 
{
	char **nums;
	int	i;
	
	nums = ft_strsplit(line, ' '); //дробим строку split'ом
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]); // записываем переводя это в цифры
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int fd;
	char *line;
	int i;
	
	data->height = get_height(file_name); // получили высоту
	data->width = get_width(file_name); //получили ширину
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->width + 1)); // выделили память под массив строчек
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1)); //выделили память под кажду строчку
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line); // запись
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
