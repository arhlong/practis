#include <iostream>

class foobar
{
public:
	foobar(){}
	foobar(int a,int b) : a_(a),b_(b)  {}
	~foobar(){}

public:
	void printf() { std::cout<<a_<<" "<<b_<<std::endl;};

private:
	int a_ = 1;
	int b_ = 2;

};

int main()
{
	foobar aux;
	aux.printf();

	const int a = 0;
	static_assert(a,"must be not zero");
	return 0;
}
