#include <iostream>
#include <memory>
#include "sylutils.h"

int main()
{
	{
		std::shared_ptr<syl::string> p1(new syl::string("hello world!"));
		syl::shared_ptr<syl::string> p2(new syl::string("hello arhlog!"));

		std::cout<<p1->c_str()<<std::endl;
		std::cout<<p2->c_str()<<std::endl;

	}

	std::cin.get();
	return 0;
}
