#ifndef _PERSION_H_
#define _PERSION_H_
#include <string>
#include <memory>
#include "PersionImpl.h"

using std::string;
using std::shared_ptr;

//class PersionImpl;

class Persion
{
protected:
	Persion(const string& name,int age) :ptrImpl_(new PersionImpl(name,age)) {};
public:
	virtual ~Persion(){};
	Persion(const Persion& other) :ptrImpl_(other.ptrImpl_) {};
	Persion& operator=(const Persion& other){ptrImpl_ = other.ptrImpl_; return *this;};

public:
	static shared_ptr<Persion> create(const string& name,int age) {return shared_ptr<Persion>(new Persion(name,age));}
	virtual string name() const {return ptrImpl_->name();}
	virtual int age() const {return ptrImpl_->age();}

private:
	shared_ptr<PersionImpl> ptrImpl_;
};
#endif
