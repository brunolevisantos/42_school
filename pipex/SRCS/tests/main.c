#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main (int argv, char **argc, char *envp[])
{
	int	i;
	char	*env_var;

	i = 0;
	env_var = envp[i];
	while (access("PATH", F_OK))
	{
		i++;
		env_var = envp[i];
		printf("%s\n", env_var);
	}
	return (0);
}