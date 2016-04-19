#include <atomic>
#include <iostream>
#include <thread>

using std::atomic;

atomic<int> a {0};
//int a {0};

int thread_local errcode {0};
thread_local int errcode2 {0};

void add(int count)
{
	for(int i = 0; i < count; i ++)
	{
		a += i;
		errcode += i;
		std::cout<<"add a:"<<a<<"code:"<<errcode<<std::endl;
	}
}

void sub(int count)
{
	for(int i = 0; i < count; i ++)
	{
		a += i;
		errcode += i;
		std::cout<<"sub a:"<<a<<"code:"<<errcode<<std::endl;
	}
}

int main()
{
	std::thread t1(add,10);
	std::thread t2(sub,5);

	t1.join();
	t2.join();

	return 0;
}
