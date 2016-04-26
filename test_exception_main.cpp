#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

int my_div(int a,int b)
{
	if(0 == b) throw std::runtime_error("b == 0");
	return a/b;
}

int main()
{
	int a = 2,b = 0;
	std::vector<int> vec;
	try
	{
		a = my_div(a,b);
	}
	catch(std::runtime_error& e)
	{
		std::cout<<"11111 catch throw:"<<std::endl;
		std::cout<<e.what()<<std::endl;
		return 1;
	}
	catch(std::exception& e)
	{
		std::cout<<"22222 catch throw:"<<std::endl;
		std::cout<<e.what()<<std::endl;
		return 2;
	}
	//catch(const char* e)
	//{
		//std::cout<<"33333 catch throw:"<<std::endl;
		//std::cout<<e<<std::endl;
		//return 3;
	//}
	//catch(...)
	//{
		//std::cout<<"44444 catch throw:"<<std::endl;
		////std::cout<<e<<std::endl;
		//return 4;
	//}

	std::cout<<"res:"<<a<<std::endl;
	//assert(a);
	return 0;
}
