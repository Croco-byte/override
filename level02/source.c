#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	int	i = 0;
	int	n;		// [rbp-0x114]
	long	l;		// [rbp-0x120]
	char	buff[96];	// [rbp-0x70]		// no terminating \0 ?
	char	buff2[41];	// [rbp-0xa0]
	char	buff3[96];	// [rbp-0x110]
	FILE	*file = 0;	// [rbp-0x8]
	size_t	y = 0;		// [rbp-0xc]

	while (i < 96)
		buff[i++] = '\0';
	i = 0;
	while (i < 40)
		buff[i++] = '\0';
	i = 0;
	while (i < 96)
		buff[i++] = '\0';

	file = fopen("/home/users/level03/.pass", "r");
	if (file == 0)
	{
		fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
		exit(1);
	}

	y = fread(buff2, 1, 41, file);
	buff2[strcspn(buff2, "\n")] = '\0';
	if (y != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
		exit(1);
	}
	fclose(file);

	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(buff, 0x64, stdin);
	buff[strcspn(buff, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(buff3, 0x64, stdin);
	buff3[strcspn(buff3, "\n")] = '\0';

	puts("*****************************************");
	printf("Comparing %s | %s\n", buff2, buff3);
	if (strncmp(buff2, buff3, 41) == 0)
	{
		printf("Greetings, %s!\n", buff);
		system("/bin/sh");
		return (0);
	}
	printf(buff);				// Format string vulnerability
	puts(" does not have access!");
	exit(1);
}

// 
// 
