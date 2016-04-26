#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
	std::ofstream fout("test.txt");
	fout<<"hello world!"<<std::endl;
	std::cout<<"hi"<<std::flush;
	std::cout<<"hello"<<std::endl;
	std::cout<<"ni hao.";
	std::string a;
	std::cin>>a;
	std::cout<<a<<std::endl;
	std::cout<<"生活不止眼前的苟且\n";
	std::cout<<"还有诗和远方的田野."<<std::endl;
	double b = 1234.56789f;
	std::cout.precision(2);
	std::cout<<b<<std::endl;

	std::ostringstream ostr;
	double d = 10.23f;
	ostr<<"double value:"<<d;
    std::string tmpstr = ostr.str();
	std::cout<<"ostr to str:"<<tmpstr<<std::endl;

	std::istringstream istr(tmpstr);
	char tmpchar;
	while(istr>>tmpchar)
	{
		std::cout<<"tmpchar:"<<tmpchar<<std::endl;
	}

	return 0;
}
