#ifndef _TEXT_QUERY_H
#define _TEXT_QUERY_H

class TextQuery
{
public:
	TextQuery(const char* path,const char* word) = default;
	TextQuery(const TextQuery& other) = delete;
	TextQuery& TextQuery(const TextQuery& other) = delete;
	~TextQuery();

	//query and print
	void query();

private:
	char* path_;
	char* word_;
	std::map<int,std::string> mapLine_;
	int   count_;
};

#endif
