#include <iostream>
#include <memory>
#include <vector>
#include <string>

using std::unique_ptr;
using std::string;
using std::vector;
using std::move;

unique_ptr<string> create_obj()
{
	return unique_ptr<string>(new string("hi girl."));
}

int main()
{
	unique_ptr<string> ret = create_obj();
	std::cout<<*ret<<std::endl;
	unique_ptr<string> ret2(new string("hi boy."));
	vector<unique_ptr<string>> vs;
	vs.push_back(move(ret));
	vs.push_back(move(ret2));
	std::cout<<"vector size:"<<vs.size()<<std::endl;
	for(auto &v : vs)
	{
		std::cout<<*v<<std::endl;
	}

	return 0;
}
