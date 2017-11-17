#include <stdio.h>

int	main(int ac, char **av)
{
	char	test[4];
	int		i;
	int		tmp;

	i = 0;
	while (i < 4)
	{
		test[i] = av[i + 1][0] - '0';
		i++;
	}
	i = 0;
	printf("pos dep %d avec cote de %d\n", (int)(av[5][0] - '0'), (int)(av[6][0]- '0'));
	while (i < 4)
	{
		tmp =  av[5][0] - '0' + (test[i] % 5) + (test[i] / 5) * (av[6][0] - '0') - test[0];
		printf("i%d %d\n", i + 1, tmp);
		i++;
	}
	return(0);	
}
