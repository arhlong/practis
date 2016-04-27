#include <iostream>
#include <thread>
#include <future>

//future,async,promise,packaged_task 的用法
//mutex,condition_variable 的用法

class Bar
{
public:
	void print() { std::cout<<a_<<" "<<b_<<std::endl; }
	void addself() { ++a_; ++b_;}
private:
	int a_ = 1;
	int b_ = 2;
};

void do_stuff()
{
	std::cout<<"do someting..."<<std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int add(int a,int b)
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return a+b;
}

void print_info(std::future<int>& fut)
{
	int x = fut.get();
	std::cout<<"in print_info,get x:"<<x<<std::endl;
}

int main()
{
	std::future<int> fut1 = std::async(add,10,20);
	do_stuff();
	std::cout<<"get fut1 result:"<<fut1.get()<<std::endl;

	std::packaged_task<int(int,int)> task(add);
	std::future<int> fut2 = task.get_future();
	std::thread t1(std::move(task),10,30);
	do_stuff();
	std::cout<<"get fut2 result:"<<fut2.get()<<std::endl;
	t1.join();

	std::promise<int> prom;
	std::future<int> fut3 = prom.get_future();
	std::thread t2(print_info,std::ref(fut3));
	do_stuff();
	prom.set_value(10);
	t2.join();

	return 0;
}
