#include <stdio.h>
#include <string.h>
#include <stdint.h>

void	keygen(char *buff)
{
	size_t		s;
	unsigned int	key;
	int		n;

	s = strnlen(buff, 32);
	if (s <= 5)
		return ;

	key = ((int)buff[3] ^ 0x1337) + 0x5eeded;
	n = 0;

	while (n < (int)s)
	{
		unsigned int v2, v3, v4;

		if (buff[n] <= 31)
			return ;
		
		v2 = buff[n];
		v2 ^= key;
		v3 = (uint64_t)v2*0x88233b2b >> 32;
		v4 = v2 - v3;
		v4 = v4 >> 1;
		v4 += v3;
		v4 = v4 >> 10;
		v4 *= 0x539;
		v4 = v2 - v4;

		key += v4;


		//		key = key + ((int)buff[n] ^ key) % 0x539;
		n++;
	}
	printf("[+] %u\n", key);
}


int	main(int argc, char **argv)
{
	keygen(argv[1]);
	return (0);
}
