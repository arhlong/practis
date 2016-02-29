#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int glob = 1;
char *buf = "write to stdout.\n";

int main(int argc, char ** argv)
{
	int var = 10;
	pid_t pid;

	write(STDOUT_FILENO,buf,strlen(buf));

	printf("befor fork\n");

	pid = fork();
	if(pid < 0)
	{
		perror("fork");
	}
	else if(pid ==0)
	{
		glob ++;
		var ++;
	}
	else
	{
		sleep(3);
	}

	printf("pid:%d,glob:%d,var:%d\n",getpid(),glob,var);

	return 0;
}
