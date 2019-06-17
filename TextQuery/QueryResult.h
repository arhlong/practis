#ifndef _QUERY_RESULT_H_
#define _QUERY_RESULT_H_
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <iostream>

class QueryResult
{
friend std::ostream& print(std::ostream& os,const QueryResult& res);
public:
	using LineNo = std::vector<std::string>::size_type;
	QueryResult(std::string word,
			    std::shared_ptr<std::vector<std::string>> file,
				std::shared_ptr<std::set<LineNo>> lnos)
		:word_(word),
		file_(file),
		lnos_(lnos)
	{
	}

    //std::ostream& print(std::ostream& os);

private:
	std::string word_;
	std::shared_ptr<std::vector<std::string>> file_;
	std::shared_ptr<std::set<LineNo>> lnos_;
};

std::ostream& print(std::ostream& os,const QueryResult& res);

#endif
