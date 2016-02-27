#include "ThreadPool.h"
#include <iostream>
#include <string>

struct Student
{
	std::string name_;
	int         age_;

	Student():age_(0){}
	Student(std::string name,int age):name_(name),age_(age){}
};

int main()
{
	ThreadPool pool(3);
	std::vector<Student> students {{"lucy",18},{"lily",5},{"hanmeimei",8},{"",30},{"lilei",14},{"xiaoming",3},{"xiaohong",12}};
	std::vector<std::future<int>> results;

	for(auto &student : students)
	{
		auto res = pool.enqueue(
				[&student]()->int {
				if(student.name_.empty())
				{
				    std::cout<<"input a empty student name!"<<std::endl;
				    return 1;
				}
				if(student.age_ >= 10)
				{
				    std::cout<<"larger than 10 age,name:"<<student.name_<<std::endl;
				}
				else
				{
				    std::cout<<"smaller than 10 age,name:"<<student.name_<<std::endl;
				}
				return 0;
				});
	}

	for(auto &res : results)
	{
		std::cout<<"result:"<<res.get()<<std::endl;
	}

	return 0;
}
