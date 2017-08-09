unsigned int	choose_color(int palette, int i, int iter_max, double mult, double zr, double zi, double ci);
unsigned int	choose_color(int palette, int i, int iter_max,
					double mult, double zr, double zi, double ci)
{
	if (palette == 0)
		return (aqua_blue(iter_max, i, mult));
	else if (palette == 1)
		return (smooth_aqua_blue(iter_max, i, mult));
	else if (palette == 2)
		return (blue(i, iter_max, mult));
	else if (palette == 3)
		return (grey(i, iter_max, mult));
	else if (palette == 4)
		return (fire(i, iter_max, mult));
	else if (palette == 5)
		return (shade_of_grey(i, iter_max, mult));
	else if (palette == 6)
		return (smooth_shade_of_grey(i, iter_max, mult));
	else if (palette == 7)
		return (rainbow2(iter_max, i, mult));
	else if (palette == 8)
		return (picots(iter_max, i, zr, mult));
	else if (palette == 9)
		return (vasarely(zi));
	else if (palette == 10)
		return (zebra(i, iter_max, mult));

}

double	ft_abs_double(double nb);
double	ft_abs_double(double nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

__kernel void choose_fractal(__global unsigned int *buffer,
									  int fractale,
									  int width,
									  int height,
									  double zoom,
									  double offx,
									  double offy,
									  int rond,
									  int palette,
									  double x1,
									  double x2,
									  double y1,
									  double y2,
									  double cr,
									  double ci,
									  double zr,
									  double zi,
									  int iter_max, 
									  int mx,
									  int my,
									  int midx,
									  int midy)
{
	unsigned int	pixel;
	int i;
	int x;
	int y;
	double mult;
	double tmp;

	pixel = get_global_id(0);
	y = pixel / width;
	x = pixel % width;
	mult = 0;
	i = 0;
	if (fractale == JULIA)
	{
		zr = (double)(x - midx) / zoom + x1 + offx;
		zi = (double)(y - midy) / zoom + y1 + offy;
	}
	else
	{
		cr = (double)(x - midx) / zoom + x1 + offx;
		ci = (double)(y - midy) / zoom + y1 + offy;
	}
	if (y >= height * 96 / 100)
		buffer[pixel] = 0x000000;
	else if (y >= height * 92 / 100)
		buffer[pixel] = 0xFFFFFF;
	else
	{
		while (mult < rond && i < iter_max)
		{
			if (fractale == DUOBROT)
			{
				tmp = (zr * zr - (zi * zi * 3.0)) * zr + cr;
				zi = ((zr * zr * 3.0) - zi * zi) * zi + ci;
			}
			else if (fractale == TRIOBROT)
			{
				tmp = zr * zr * zr * zr + zi * zi * zi * zi - 6 * zr * zr * zi * zi + cr;
				zi = 4 * zr * zi * (zr * zr - zi * zi) + ci;
			}
			else if (fractale == SHIP)
			{
				tmp = zr * zr - zi * zi + cr;
				zi = 2 * ft_abs_double(zi * zr) + ci;
			}
			else if (fractale == BIRD)
			{
				tmp = (zr * zr - (zi * zi * 3)) * ft_abs_double(zr) + cr;
				zi = ((zr * zr * 3) - zi * zi) * ft_abs_double(zi) + ci;
			}
			else if (fractale == JULIA)
			{
				tmp = zr * zr - zi * zi + cr * width / 2 / mx;
				zi = 2 * zi * zr + ci * height / 2 / my;
			}
			else if (fractale == BUFFALO)
			{
				tmp = ft_abs_double(zr * zr - zi * zi) + cr;
				zi = 2 * ft_abs_double(zr * zi) + ci;
			}
			else if (fractale == MANDELBAR)
			{
				tmp = -(zr * zr - (zi * zi * 3.0)) * zr + cr;
				zi = ((zr * zr * 3.0) - zi * zi) * zi + ci;
			}
			else
			{
				tmp = zr * zr - zi * zi + cr;
				zi = 2 * zi * zr + ci;
			}
			zr = tmp;
			i++;
			mult = zr * zr + zi * zi;
		}
		buffer[pixel] = choose_color(palette, i, iter_max, mult, zr, zi, ci);
	}
}
