/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opencl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 15:59:43 by mdubus            #+#    #+#             */
/*   Updated: 2017/08/05 15:59:44 by mdubus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static char	*join_properly(char *s1, int free1, char *s2, int free2)
{
	char	*temp1;
	char	*temp2;
	char	*mew;

	temp1 = s1;
	temp2 = s2;
	mew = ft_strjoin(s1, s2);
	if (free1 == 1)
		free(temp1);
	if (free2 == 1)
		free(temp2);
	return (mew);
}

static char	*read_file_with_gnl(char *file)
{
	t_fgnl	gnl;

	gnl.fd = -1;
	gnl.gnl_ret = -1;
	gnl.line = NULL;
	gnl.mew = NULL;
	gnl.temp = NULL;
	if ((gnl.fd = open(file, O_RDONLY)) < 0)
		ft_print_error_exit(&perror, "Error ");
	while ((gnl.gnl_ret = get_next_line(gnl.fd, &gnl.line)) != 0)
	{
		gnl.line = join_properly("\n", 0, gnl.line, 1);
		if (gnl.mew != NULL)
			gnl.mew = join_properly(gnl.mew, 1, gnl.line, 1);
		else
			gnl.mew = gnl.line;
	}
	close(gnl.fd);
	return (gnl.mew);
}

static void	get_src_opencl(t_p *p)
{
	char	*temp;

	temp = NULL;
	p->fbegin = ft_strdup("#define GPU\n #define UI unsigned int\n");
	p->fcolor = read_file_with_gnl("includes/color.h");
	p->fpalette3 = read_file_with_gnl("srcs/palette3.c");
	p->fpalette1 = read_file_with_gnl("srcs/palette1.c");
	p->fpalette2 = read_file_with_gnl("srcs/palette2.c");
	p->fkernel = read_file_with_gnl("srcs/speed.cl");
	temp = join_properly(p->fbegin, 1, p->fcolor, 1);
	temp = join_properly(temp, 1, p->fpalette3, 1);
	temp = join_properly(temp, 1, p->fpalette1, 1);
	temp = join_properly(temp, 1, p->fpalette2, 1);
	temp = join_properly(temp, 1, p->fkernel, 1);
	p->opencl = temp;
}

static void	init_opencl_part_2(t_p *p, int *err)
{
	unsigned int	nb_pixels;

	nb_pixels = WIDTH_W * HEIGHT_W * 3;
	*err = clBuildProgram(p->program, 0, NULL, NULL, NULL, NULL);
	if (*err != CL_SUCCESS)
		ft_print_error_exit(&ft_putendl, "Error with clBuildProgram");
	p->kernel = clCreateKernel(p->program, "choose_fractal", err);
	if (!p->kernel || *err != CL_SUCCESS)
		ft_print_error_exit(&ft_putendl, "Error with clCreateKernel");
	if (!(p->buffer = clCreateBuffer(p->context, CL_MEM_WRITE_ONLY,
					sizeof(UI) * nb_pixels, NULL, NULL)))
		ft_print_error_exit(&ft_putendl, "Error with clCreateBuffer");
	if ((*err = clGetKernelWorkGroupInfo(p->kernel, p->device_id,
					CL_KERNEL_WORK_GROUP_SIZE, sizeof(p->local), &p->local,
					NULL)) != CL_SUCCESS)
		ft_print_error_exit(&ft_putendl,
				"Error with clGetKernelWorkGroupsInfo");
}

void		init_opencl(t_p *p)
{
	int				err;

	get_src_opencl(p);
	err = -1;
	if ((err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, 1,
					&p->device_id, NULL)) != CL_SUCCESS)
		ft_print_error_exit(&ft_putendl, "Error with clGetDeviceIDs");
	if (!(p->context = clCreateContext(0, 1, &p->device_id, NULL, NULL, &err)))
		ft_print_error_exit(&ft_putendl, "Error with clCreateContext");
	if (!(p->commands = clCreateCommandQueue(p->context,
					p->device_id, 0, &err)))
		ft_print_error_exit(&ft_putendl, "Error with clCreateCommandQueue");
	if (!(p->program = clCreateProgramWithSource(p->context, 1,
					(const char**)&p->opencl, NULL, &err)))
		ft_print_error_exit(&ft_putendl,
				"Error with clCreateProgramWithSource");
	init_opencl_part_2(p, &err);
}
