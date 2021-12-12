#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	size = 0;
	int	n = 0;			// [esp+0x8c]
	char	buff[100];		// [esp+0x28]

	fgets(buff, 100, stdin);

	while (buff[size] != '\0')
		size++;
	
	while (n < size)
	{
		if (buff[n] > 0x40 && buff[n] <= 0x5a)
		{
			buff[n] ^= 0x20;
		}
		n++;
	}
	printf(buff);
	exit(0);
}
