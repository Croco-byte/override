#include <stdio.h>

void decrypt(unsigned int r)
{
	char *enc = "Q}|u`sfg~sf{}|a3";
	int	size = 0;
	int	n_7 = 0;
	char result[64];

	while (enc[size])
		size++;
	while (n_7 < size)
	{
		result[n_7] = (char)(r ^ (*(enc + n_7)));
		n_7++;
	}
	result[n_7] = '\0';
	printf("[*] --> %s\n", result);
	return ;

}

int	main(void)
{
	int d00d	= 322424845;
	int guess	= 322424845;
	
	int i = 0;
	while (guess + i < d00d + 0x15)
	{
		unsigned int r = d00d - (guess - i);
		printf("\nTrying with %d (r is %u)\n", guess - i, r);
		decrypt(r);
		i++;
	}
	return (0);
}
