#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n;

	puts("***********************************");
	puts("*	-Level00-		*");
	puts("***********************************");
	printf("Password:");

	scanf("%d", &n);
	if (n == 0x149c)				// 5276
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
		return (0);
	}
	puts("\nInvalid Password!");
	return (1);
}
