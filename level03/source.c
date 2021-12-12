#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

// Key is 322424827

void	decrypt(unsigned int r)
{
	int	n_2 = 0x757c7d51;		// [ebp-0x1d]
	int	n_3 = 0x67667360;		// [ebp-0x19]
	int	n_4 = 0x7b66737e;		// [ebp-0x15]
	int	n_5 = 0x33617c7d;		// [ebp-0x11]
	// "Q}|u`sfg~sf{}|a3"

	char	c = 0x0;			// [ebp-0xd]
	int	size = 0;			// [ebp-0x24]
	int	n_7 = 0;			// [ebp-0x28]
	char	*correct = "Congratulations!";

	while (*((char *)&n_2 + size) != 0)
		size++;
	while (n_7 < size)
	{
		*((char *)&n_2 + n_7) = r ^ *((char *)&n_2 + n_7);
		n_7++;
	}

	int i = 0;
	while (*((char *)&n_2 + i) == correct[i] && i < 16)
		i++;
	if (i == 16)
	{
		system("/bin/sh");
		return ;
	}
	else
		puts("\nInvalid Password");
	return ;
}

void	test(int n, int hex)
{
	unsigned int r;				// [ebp-0xc]

	r = hex - n;
	if (r < 0x15)
	{
		unsigned int tmp = r*4;
		if (tmp == 0)
			goto RAND;
		if (tmp == 4)
			goto G46;
		if (tmp == 8)
			goto G62;
		if (tmp == 12)
			goto G78;
		if (tmp == 16)
			goto G94;
		if (tmp == 20)
			goto G110;
		if (tmp == 24)
			goto G126;
		if (tmp == 28)
			goto G142;
		if (tmp == 32)
			goto G155;
		if (tmp == 36)
			goto G168;
		if (tmp == 40 || tmp == 44 || tmp == 48 || tmp == 52 || tmp == 56 || tmp == 60)
			goto RAND;
		if (tmp == 64)
			goto G181;
		if (tmp == 68)
			goto G194;
		if (tmp == 72)
			goto G207;
		if (tmp == 76)
			goto G220;
		if (tmp == 80)
			goto G233;
		if (tmp == 84)
			goto G246;
	}
	else
	{
	RAND:
		decrypt(rand());
		return ;
	}

G46:
	decrypt(r);
	return ;
G62:
	decrypt(r);
	return ;
G78:
	decrypt(r);
	return ;
G94:
	decrypt(r);
	return ;
G110:
	decrypt(r);
	return ;
G126:
	decrypt(r);
	return ;
G142:
	decrypt(r);
	return ;
G155:
	decrypt(r);
	return ;
G168:
	decrypt(r);
	return ;
G181:
	decrypt(r);
	return ;
G194:
	decrypt(r);
	return ;
G207:
	decrypt(r);
	return ;
G220:
	decrypt(r);
	return ;
G233:
	decrypt(r);
	return ;
G246:
	decrypt(r);
	return ;

	return ;
}

int	main(void)
{
	int	n;					// [esp+0x1c]

	srand(time(NULL));
	puts("***********************************");
	puts("		level03		**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &n);
	test(n, 0x1337d00d);
	return (0);
}
