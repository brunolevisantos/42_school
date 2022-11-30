#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

int	main(void)
{
	int		fd;
	int		i;
	char	buf[BUFFER_SIZE];

	fd = open("file_to_read.txt", O_RDONLY);
	i = read(fd, buf, BUFFER_SIZE);
	buf[i] = '\0';
	printf("%s\n", buf);
}
