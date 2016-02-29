#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int globalValue = 1;
int globaltmp;
int globaltmp2;

int done()
{
	int donetmp;
	printf("donetmp:%d\n",done);
}

int main(int argc, char **argv)
{
	printf("hello world!\n");
	int mainValue = 2;
	int *pInt = malloc(4);
	*pInt = 3;
	int maintmp;
	int maintmp2;
	printf("globaltmp:%d,globaltmp2:%d,maintmp:%d,maintmp2:%d\n",globaltmp,globaltmp2,maintmp,maintmp2);
	done();

	pid_t pid;

	pid = fork();

	if(0 == pid)
	{
		int count1 = 0;
		printf("pid:%d,count1:%d\n",getpid(),count1);
		while(1)
		{
			if(count1 > 1)
				exit(1);
				/*break;*/
			printf("pid:%d,global value:%d,main value:%d,malloc value:%d\n",getpid(),globalValue,mainValue,*pInt);
			printf("pid:%d,global value addr:%p,main value addr:%p,malloc value addr:%p\n",getpid(),&globalValue,&mainValue,pInt);
			globalValue += 5;
			mainValue += 5;
			(*pInt) += 5;
			count1++;
			sleep(3);
		}
	}
	else if(pid > 0)
	{
		int count2 = 0;
		printf("pid:%d,count2:%d\n",getpid(),count2);
		int status;
		wait(&status);
		while(1)
		{
			if(count2 > 1)
				break;
			printf("pid:%d,global value:%d,main value:%d,malloc value:%d\n",getpid(),globalValue,mainValue,*pInt);
			printf("pid:%d,global value addr:%p,main value addr:%p,malloc value addr:%p\n",getpid(),&globalValue,&mainValue,pInt);
			globalValue ++;
			mainValue ++;
			(*pInt) ++;
			count2 ++;
			sleep(3);
		}

	}
	else
	{
		perror("fork");
	}

	printf("after fork,pid:%d\n",getpid());
	return 0;
}
