#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/*
 * mv level08 binary
 * mkdir level08
 * setfacl -m u:level09:rwx level08/
 * ln -s /home/users/level09/.pass lnk
 * ./binary ../level08/lnk
 *
 *
 * argv[1]	--> ../level08/lnk
 * log		--> ./backups/.log
 * file		--> ../level08/lnk
 * fd		--> ./backups/../level08/lnk
*/



void	log_wrapper(FILE *file, char *msg, char *path)	// [rbp-0x118] - [rbp-0x120] - [rbp-0x128]
{
	char	buff[254];				// [rbp-0x110]
	int	len = 0;
	int	rmd = 0;

	strcpy(buff, msg);
	while (buff[len])
		len++;
	rmd = 254 - len;

	snprintf(buff+len, rmd, path);			// Format string vulnerability
	buff[strcspn(buff, "\n")] = '\0';
	fprintf(file, "LOG: %s\n", buff);
	return ;
}


int	main(int argc, char **argv)		// [rbp-0x94] - [rbp-0xa0]
{
	FILE	*file;				// [rbp-0x80]
	FILE	*log;				// [rbp-0x88]
	char	buff[100];			// [rbp-0x70]
	char	c = 0;				// [rbp-0x71]
	int	fd;				// [rbp-0x78]

	if (argc != 2)
		printf("Usage: %s filename\n", argv[0]);

	log = fopen("./backups/.log", "w");
	if (log == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}

	log_wrapper(log, "Starting back up: ", argv[1]);
	file = fopen(argv[1], "r");
	if (file == 0)
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}

	char	*pre = "./backups/";
	int i = 0;
	while (pre[i])
		buff[i] = pre[i];
	buff[i] = '\0';

	i--;
	int rmd = 100 - i;	
	strncat(buff, argv[i], rmd);

	fd = open(buff, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	if (fd < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}

	while (c != EOF)
	{
		c = fgetc(file);
		if (c != 0xff)
			write(fd, &c, 1);
	}

	log_wrapper(log, "Finished back up ", argv[1]);
	fclose(file);
	close(fd);
	return (0);
}
