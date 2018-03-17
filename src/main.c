#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (0);
	info  = (t_info *)ft_memalloc(sizeof(t_info));
	info->plot = load_file(argv[1]); 
}
