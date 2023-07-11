#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putnbr(int nbr);
int		ft_putstr(char *str);
void	ft_puthex(int nbr);
int		nbr_size(int nbr);

int	print_args(va_list args, char c)
{
	int	written;

	written = 0;
	if (c == 'd')
	{
		ft_putnbr(va_arg(args, int));
		// written += nbr_size(va_arg(args, int));
	}
	else if (c == 's')
		written += ft_putstr(va_arg(args, char *));
	// else if (c == 'x')
	// {
	// 	ft_puthex(va_arg(args, int));
	// 	// written += 1; // alterar
	// }
	return (written);
}

int ft_printf(const char *str, ... )
{
	int		i;
	int		written;
	va_list	args;

	i = -1;
	written = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] != '%')
			written += write (1, &str[i], 1);
		else
			written += print_args(args, str[++i]);
	}
	va_end(args);
	return (written);
}

int	main(void)
{
	ft_printf("A tua mae e um %s com %d anos\n", "homem", 33);
}