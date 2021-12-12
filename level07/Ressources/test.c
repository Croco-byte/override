#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned int n = 0x0;
	scanf("%u", &n);

	printf("[*] As unsigned :	%u\n", n * 4);
	printf("[*] As signed :		%d\n", n * 4);


	return (0);
}
