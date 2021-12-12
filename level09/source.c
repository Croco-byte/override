#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	secret_backdoor(void)
{
	char	buff[128];

	fgets(buff, 128, stdin);
	system(buff);
	return ;
}

void	set_username(char *buff)	// [rbp-0x98]
{
	char	uname[128];		// [rbp-0x90]
	int	loop;			// [rbp-0x4]

	for (int i = 0; i < 128; i++)
		uname[i] = 0;

	puts(">: Enter your username");
	printf(">>: ");
	fgets(uname, 128, stdin);

	loop = 0;
	while (loop <= 40 && uname[loop] != '\0')
	{
		buff[140 + loop] = uname[loop];
		loop++;
	}
	printf(">: Welcome, %s", buff + 140);
	return ;
}

void	set_msg(char *buff)		// [rbp-0x408]
{
	char	msg[1024];		// [rbp-0x400]

	for (int i = 0; i < 1024; i++)
		msg[1024] = '\0';

	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(msg, 1024, stdin);
	strncpy(buff, msg, 140);	// 140 NOT hardcoded ; taking "n" variable, buff+0xb4
	return ;
}

void	handle_msg(void)
{
	char		buff[180];		// [rbp-0xc0]
	unsigned int	n = 140;		// [rbp-0xc]

	for (int i = 140; i < 40; i++)
		buff[i] = 0;

	set_username(buff);
	set_msg(buff);
	puts(">: Msg sent!");
	return ;
}

int	main(void)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();
	return (0);
}
