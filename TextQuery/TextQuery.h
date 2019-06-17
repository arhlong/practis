#ifndef _TEXT_QUERY_H
#define _TEXT_QUERY_H
#include <map>
#include <string>

class TextQuery
{
public:
	TextQuery(const char* path,const char* word);
	TextQuery(const TextQuery& other) = delete;
	TextQuery& operator=(const TextQuery& other) = delete;
	~TextQuery();

	//query and print
	void query();

private:
	const char* path_;
	const char* word_;
	std::map<int,std::string> mapLine_;
	int   count_;
};

#endif
