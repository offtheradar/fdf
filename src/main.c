#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (0);
	info = init_info();
	create_vertices(info->plot, argv[1]);
/*	draw_wf(info);*/
	return (0);
}
