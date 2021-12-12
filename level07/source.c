#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// index 114 overwrites return address
// Need n * 4 to be 456
// -2147483534 fills the bill

void		clear_stdin(void)
{
	int	tmp;

	tmp = getchar();
	while ((char)tmp != -1)
	{
		if ((char)tmp == '\n')
			return ;
	}
	return ;
}

unsigned int	get_unum(void)
{
	unsigned int result = 0;

	fflush(stdout);
	scanf("%u", &result);
	clear_stdin();
	return (result);
}


int	store_number(char *buff)
{
	unsigned int	n	= 0x0;				// [ebp-0x10]
	unsigned int	n2	= 0x0;				// [ebp-0xc]

	printf(" Number: ");
	n = get_unum();
	printf(" Index: ");
	n2 = get_unum();

	unsigned int tmp_1 = ((uint64_t)n2 * 0xaaaaaaab) >> 32;
	tmp_1 = tmp_1 >> 1;
	unsigned int tmp_2 = tmp_1 + tmp_1;
	tmp_2 += tmp_1;
	unsigned int tmp_3 = n2 - tmp_2;
	// Equivalent to : tmp_3 = n2 % 3
	if (tmp_3 == 0 || (n >> 24) == 183)
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}

	buff[n2 * 4] = n;
	return (0);
}

int	read_number(char *buff)
{
	unsigned int	index = 0x0;				// [ebp-0xc]
	printf(" Index: ");
	index = get_unum();
	printf(" Number at data[%u] is %u\n", index, buff[index * 4]);
	return (0);
}

int	main(int argc, char **argv)
{
	char		**av		= argv;			// [esp+0x1c]
	char		**av_4		= argv + 0x4;		// [esp+0x18]
	unsigned int	n		= 0x14;			// [esp+0x1cc]
	unsigned int	v1		= 0x0;			// [esp+0x1b4]
	char		cmd[20];				// [esp+0x1b8]
	char		buff[100];				// [esp+0x24]

	for (int i = 0; i < 100; i++)
		buff[i] = 0;
	for (int i = 0; i < 20; i++)
		cmd[i] = 0;
	
	while (*av != 0)
	{
		int len = 0;
		while (av[0][len] != 0)
			len++;
		memset(av[0], 0, len);
		av++;
	}

	while (*av_4 != 0)
	{
		int len = 0;
		while (av_4[0][len] != 0)
			len++;
		memset(av_4[0], 0, len);
		av_4++;
	}

	puts("----------------------------------------------------\n Welcome to wil's crappy number storage service! \n----------------------------------------------------\n Commands:                                          \n store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n wil has reserved some storage :>                 \n----------------------------------------------------\n");
	
	while (1)
	{
		printf("Input command: ");
		v1 = 0x1;
		fgets(cmd, 20, stdin);
	
		int size = 0;
		while (cmd[size+1])
			size++;
		cmd[size] = '\0';
	
		int i = 0;
		char *store = "store";
		while (i < 5 && cmd[i] == store[i])
			i++;
		if (i == 5)
			v1 = store_number(buff);

		i = 0;
		char *read = "read";
		while (i < 4 && cmd[i] == read[i])
			i++;
		if (i == 4)
			v1 = read_number(buff);

		i = 0;
		char *quit = "quit";
		while (i < 4 && cmd[i] == quit[i])
			i++;
		if (i == 4)
			return (0);
	
		if (v1 != 0)
			printf(" Failed to do %s command\n", cmd);
		else
			printf(" Completed %s command successfully\n", cmd);
	
		for (int i = 0; i < 20; i++)
			cmd[i] = 0;
	}

	return (0);
}
