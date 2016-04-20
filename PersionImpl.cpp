#include "PersionImpl.h"

PersionImpl::PersionImpl(const string& name,int age)
	:name_(name),age_(age)
{
}

PersionImpl::~PersionImpl()
{
}

PersionImpl::PersionImpl(const PersionImpl& other)
	:name_(other.name_),age_(other.age_)
{
}

PersionImpl& PersionImpl::operator=(const PersionImpl& other)
{
	name_ = other.name_;
	age_ = other.age_;

	return *this;
}

string PersionImpl::name() const
{
	return name_;
}

int PersionImpl::age() const
{
	return age_;
}

