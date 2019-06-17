#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_
#include <map>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <memory>

class QueryResult;
class TextQuery
{
public:
	using LineNo = std::vector<std::string>::size_type;
	TextQuery(std::ifstream& inf);
	TextQuery(const TextQuery& other) = delete;
	TextQuery& operator=(const TextQuery& other) = delete;
	~TextQuery();

	void test();
	QueryResult query(std::string word);

private:
	std::shared_ptr<std::vector<std::string>>  file_;
	std::map<std::string,std::shared_ptr<std::set<LineNo>>> wordMap_;
};

#endif
