#include <stdio.h>

char *real_uname = "dat_wil";			// 0x80486a8
char *real_passw = "admin";			// 0x80486b0
char a_user_name[100];				// 0x64 - 100 ; 0x804a040


int	verify_user_name(void)
{
	int	i = 0;
	puts("verifying username....\n");

	while (real_uname[i] == a_user_name[i] &&  i < 7)
		i++;
	if (i == 7)
		return (0);
	return (1);
}

int	verify_user_pass(char *buff)
{
	int	i = 0;

	while (buff[i] == real_passw[i] && i < 5)
		i++;
	if (i == 5)
		return (0);
	return (1);
}


int	main(void)
{
	int	i = 0;
	char	buff[64];			// [esp+0x1c]
	int	n;				// [esp+0x5c]

	while (i < 64)
		buff[i++] = '\0';
	n = 0;
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 0x100, stdin);
	n = verify_user_name();
	if (n != 0)
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	puts("Enter Password: ");
	fgets(buff, 0x64, stdin);
	n = verify_user_pass(buff);
	if (n != 0)
	{
		puts("nope, incorrect password...\n");
		return (1);
	}
	return (0);
}
