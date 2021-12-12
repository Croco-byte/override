#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <string.h>
#include <stdint.h>

int	auth(char *buff, unsigned int serial)
{
	size_t		s;				// [ebp-0xc]
	unsigned int	key;				// [ebp-0x10]
	int		n;				// [ebp-0x14]

	buff[strcspn(buff, "\n")] = '\0';
	s = strnlen(buff, 32);

	if (s <= 5)
		return (1);
	if (ptrace(PTRACE_TRACEME) == -1)
	{
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return (1);
	}
	key = ((int)buff[3] ^ 0x1337) + 0x5eeded;
	n = 0;

	while (n < (int)s)
	{
		unsigned int v2, v3, v4;

		if (buff[n] <= 31)
			return (1);
		
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
	if (serial == key)
		return (0);
	return (1);

}

int	main(int argc, char **argv)
{
	char		*av_0;			// [esp+0x1c]
	int		n;			// [esp+0x4c]
	char		buff[32];		// [esp+0x2c]
	unsigned int	serial;			// [esp+0x28]

	av_0 = argv[0];
	n = 0x14;

	puts("***********************************");
	puts("*		level06		*");
	puts("***********************************");

	printf("-> Enter Login: ");
	fgets(buff, 32, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");

	printf("-> Enter Serial: ");
	scanf("%u", &serial);

	if (auth(buff, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
