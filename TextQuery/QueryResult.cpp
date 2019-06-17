#include "QueryResult.h"

std::ostream& QueryResult::print(std::ostream& os)
{
	os << word_ << " occurs " << lnos_->size() << " times" << std::endl;
	for(auto no : *lnos_)
	{
		os << "(line " << (no + 1) << ") " << file_->at(no) << std::endl;
	}

	return os;
}
