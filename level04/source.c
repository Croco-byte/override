#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <signal.h>

int	main(void)
{
	pid_t	pid;		// [esp+0xac]
	int	n;		// [esp+0xa8]
	int	ret;		// [esp+0x1c]
	int	ret2;		// [esp+0xa0]
	int	ret3;		// [esp+0xa4]
	char	buff[128];	// [esp+0x20]

	pid = fork();
	int i = 0;
	while (i < 128)
		buff[i++] = '\0';

	n = 0;
	ret = 0;
	if (pid == 0)					// Executed by child
	{
		prctl(PR_SET_PDEATHSIG, SIGHUP);
		ptrace(PTRACE_TRACEME, 0x0, 0x0, 0x0);
		puts("Give me some shellcode, k");
		gets(buff);
		execve("/bin/sh", 0, 0);
	}
	else						// Executed by parent
	{
		while (n != 0xb)
		{
			wait(&ret);
			ret2 = ret;
			if (WIFEXITED(ret) || WIFSIGNALED(ret))
			{
				puts("child is exiting...");
				return (0);
			}
			printf("executing ptrace\n");
			n = ptrace(PTRACE_PEEKUSER, pid, 0x2c, 0x0);
			n = 0xb;
		}
		puts("no exec() for you");
		kill(pid, 0x9);
	}
	return (0);
}
