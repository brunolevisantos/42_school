/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-seic <bde-seic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:44:11 by bde-seic          #+#    #+#             */
/*   Updated: 2022/12/19 14:55:50 by bde-seic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i]) //ver ate quando posso ler
	{
		j = i + 1;
		while (argv[j])
		{
			if (argv[i] == argv[j])
			{
				write(2, "Error\n", 6);
				exit ();
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_minmax(char *argv)
{
	if 
}

int	check_args(char **argv)
{
	int	i;

	i = 1;
	if (check_doubles(argv))
	{
		while (argv[i])
		{
			if (check_minmax(ft_atoi(argv[i])) && check_)
		}	
	}
	return (0);
}
