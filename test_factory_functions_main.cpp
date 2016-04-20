#include <iostream>
#include "Persion.h"

int main()
{
	shared_ptr<Persion> ptrPersion = Persion::create("xiao fang",18);
    std::cout<<ptrPersion->name()<<ptrPersion->age()<<std::endl;
	return 0;
}
