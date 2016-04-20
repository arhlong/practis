#ifndef _PERSION_IMPL_H_
#define _PERSION_IMPL_H_

#include <string>

using std::string;

class PersionImpl
{
public:
	PersionImpl(const string& name,int age);
	~PersionImpl();
	PersionImpl(const PersionImpl& other);
	PersionImpl& operator=(const PersionImpl& other);

public:
	string name() const;
	int age() const;

private:
	string name_;
	int    age_;
};

#endif
