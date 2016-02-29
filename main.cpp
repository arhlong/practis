#include <iostream>
#include <string>
#include <memory>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <strings.h>
#include <arpa/inet.h>


class Student
{
private:
	enum {len = 10};
    static const int lenght = 15;
	//const int size = 20;
	char math[lenght];
	//char language[size];
	std::string name;

public:
	static std::string city;
	static void print()
	{
		std::cout<<city<<std::endl;
	}
	void setMath()
	{
		sprintf(math,"90");
		printf("math:%s\n",math);
	}
};

std::string Student::city = "guanzhou";

int main()
{
	std::shared_ptr<std::string> p1(new std::string("hello world!"));
	std::shared_ptr<std::string> p2 = p1;
	std::unique_ptr<std::string> p3(new std::string("hello girl!"));
	std::auto_ptr<std::string> p4(new std::string("hello arhlong!"));

    Student a;
    Student::print();
    a.print();
	Student::city = "beijin";
    std::cout<<a.city<<std::endl;
	a.city = "shanhai";
	std::cout<<a.city<<std::endl;
	a.setMath();

	enum class egg {SMALL,LARGE};
	egg e = egg::SMALL;
	std::cout<<"small:"<<int(e)<<std::endl;
	std::cout<<"small:"<<(int)egg::SMALL<<" large:"<<(int)egg::LARGE<<std::endl;

    std::string s1,s2;
	s1 = "C5F5A5356B7918D8BC00A137F8DD08A3";
	s2 = "C5F5A5356B7918D8BC00A137F8DD08A3";
    std::cout<<"s1<s2:"<<int(s1<s2)<<std::endl;
    std::cout<<"s2<s1:"<<int(s2<s1)<<std::endl;

	int sockfd = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in sin;
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(8888);

	int ret = bind(sockfd,(struct sockaddr*)&sin,sizeof(sin));
	if(ret < 0)
	{
		perror("bind");
		return 1;
	}

	ret = listen(sockfd,5);
	if(ret < 0)
	{
		perror("listen");
		return 1;
	}

    pid_t pid = vfork();
	if(pid < 0 )
	{
		perror("fork");
		return 1;
	}
	else if(pid == 0)
	{
		std::cout<<"in child proccess."<<std::endl;
		int ret = execl("ha","-v");
		if(ret < 0)
		{
			perror("execl");
		    _exit(1);
		}
		_exit(0);
	}
	else
	{
		std::cout<<"in parent proccess."<<std::endl;

		struct sockaddr_in cliaddr;
		int clilen = sizeof(cliaddr);

		ret = accept(sockfd,(struct sockaddr*)&cliaddr,(socklen_t*)&clilen);
	}


    return 0;
}
