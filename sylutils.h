#ifndef __SYLUTILS__
#define __SYLUTILS__

#include <string.h>

namespace syl
{

class string
{
public:
	string(const char *str = 0)
	{
		if(str)
		{
			data = new char[strlen(str) + 1];
            if(!data) throw;
			strcpy(data,str);
		}
		else
		{
		 	data = new char[1];
            if(!data) throw;
			data[0] = '\0';
		}

		std::cout << "construct a string:" << data << std::endl;
	}

	~string()
	{
		std::cout << "destruct a string:" << data << std::endl;
		delete [] data;
	}

	string(const string &str)
	{
		char *newdata = new char[strlen(str.data) + 1];
		if(newdata)
		{
			delete [] data;
			data = newdata;
			strcpy(data,str.data);
		}
		else
			throw;

		std::cout << "copy a string:" << data << std::endl;
	}

	string& operator=(const string &str)
	{
		if(data == str.data)
		{
			return *this;
		}

		char *newdata = new char[strlen(str.data) + 1];
		if(newdata)
		{
			delete [] data;
			data = newdata;
			strcpy(data,str.data);
			return *this;
		}
		else
			throw;

		std::cout<< "assign a string:" << data << std::endl;
	}

	char* c_str() { return data;}

private:
	char *data;
};

template<typename T>
class shared_ptr
{
public:
	explicit shared_ptr(T *p = 0) { pointer = p; counter = new int(1); }

	~shared_ptr()
	{
		if(counter && --*counter == 0)
		{
			delete pointer;
			delete counter;
		}
	}

	shared_ptr<T>& operator=(const shared_ptr<T>& ptr)
	{
		if(pointer == ptr.pointer)
		{
			return *this;
		}

		++*counter;
		pointer = ptr.pointer;
		return *this;
	}

	T* operator->() {return pointer;}
	T& operator*() {return *pointer;}

private:
	shared_ptr(const shared_ptr<T>& ptr);

private:
	T *pointer;
	int *counter;
};

}

#endif
