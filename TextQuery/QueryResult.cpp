#include "QueryResult.h"

#if 0
std::ostream& print(std::ostream& os)
{
	os << word_ << " occurs " << lnos_->size() << " times" << std::endl;
	for(auto no : *lnos_)
	{
		os << "(line " << (no + 1) << ") " << file_->at(no) << std::endl;
	}

	return os;
}
#endif

std::ostream& print(std::ostream& os,const QueryResult& res)
{
	os << res.word_ << " occurs " << res.lnos_->size() << " times" << std::endl;
	for(auto no : *res.lnos_)
	{
		os << "(line " << (no + 1) << ") " << res.file_->at(no) << std::endl;
	}

	return os;
}
