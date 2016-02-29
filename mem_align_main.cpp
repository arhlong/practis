#include <iostream>

using namespace std;

//#pragma pack(push)
typedef struct
{
	int a;
	double b;
	float c;
}SA;

typedef union
{
	int a;
	double b;
}UA;

typedef struct
{
	string a;
	int b;
}BA;

class CA
{
private:
	int a;
	double b;
};


double Cacl(const int &a,const int &b)
{
	if(a == -b)
	{
		throw "invalid args!";
	}

	return (a+b)/(a-b);
}


//#pragma pack(pop)

void f2()
{
	cout << "call f2." << std::endl;
}

void f()
{
	cout << "call f." << endl;
	f2();
}

int main(int argc,char **argv)
{
	SA a;
	UA ua;
	CA b;
	BA c;
	string d;
	char *ptr;
	char *ptrb = new char[126];

	f();

	cout << "size SA:" << sizeof(a) << endl;
	cout << "size UA:" << sizeof(ua) << endl;
	cout << "size CA:" << sizeof(b) << endl;
	cout << "size BA:" << sizeof(c) << endl;
	cout << "size string:" << sizeof(d) << endl;

	int ia = 10;
	int ib = -10;

	try
	{
		double ret = Cacl(ia,ib);
		cout << "ret:" << ret <<endl;
	}
	catch(const char *s)
	{
		cout << "exception:" << s << endl;
		return 1;
	}

	return 0;
}
