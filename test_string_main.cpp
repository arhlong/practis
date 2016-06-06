#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

struct Test
{
std::string name;
std::string b;
int         count = 0;
Test(std::string str,int val):name(str),count(val){};
};

int main()
{
	{
		Test tmp("defualt",0);
		std::cout<<"string defualt size:"<<tmp.b.size()<<",capacity:"<<tmp.b.capacity()<<std::endl;
		std::string a;
		std::cout<<"string defualt size:"<<a.size()<<",capacity:"<<a.capacity()<<std::endl;
		std::cout<<"string defualt sizeof:"<<sizeof(a)<<std::endl;

		std::vector<Test> vc;
		vc.push_back(Test{"test1",1});
		vc.push_back(Test{"test2",1});
		//vc[0].b = "123499";
		//vc[0].b = "12399999999999999999999999999999999999999999999999999999999999999999999999999999999999";
		//vc[0].b = "12@@@@@@@@@@@@@@@@@@@@@@@@399999999999999999999999999999999999999999999999999999999999999999999999999999999999";

		while(1)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::vector<std::thread> tids;

			for(auto &v : vc)
			{
				tids.push_back(std::thread([&v]{v.b += "2222222222";}));
			}

			for(auto &t : tids)
			{
				t.join();
			}

			for(auto v: vc)
			{
				std::cout<<"b:"<<v.b<<std::endl;
			}
		}

		//for(int i = 0; i < 100; i ++)
		//{
			//std::string tmp("11111111111111144444");
			//vc[0].b += tmp;
			//vc[1].b += tmp;
		//}

		//for(auto v : vc)
		//{
			//std::cout<<"b:"<<v.b<<std::endl;
		//}
	}

	return 0;
}
