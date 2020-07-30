int main()
{
	t_data *data = NULL;
	data = ft_init("map2.cub");
	ft_printf("%s\n%s\n%s\n%s\n", data->texture[0], data->texture[1], data->texture[2], data->texture[3]);
	ft_printf("%s\n", data->sprite);
	ft_printf("c : %d\nf : %d\n", data->ceil, data->floor);
	ft_printf("x : %d	y : %d\n", data->res->x, data->res->y);
	int i = 0;
	while (data->map[i][0])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	return (0);
}
