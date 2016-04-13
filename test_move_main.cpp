#include <iostream>
#include <memory>

using std::unique_ptr;
using std::string;

unique_ptr<string> create_obj()
{
	return unique_ptr<string>(new string("hi girl."));
}

int main()
{
	unique_ptr<string> ret = create_obj();
	std::cout<<*ret<<std::endl;
	return 0;
}
