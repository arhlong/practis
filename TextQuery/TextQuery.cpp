#include <iostream>
#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

TextQuery::TextQuery(ifstream& inf)
	:file_(new vector<string>)
{
	string szText;
	while(getline(inf,szText))
	{
		file_->push_back(szText);
		LineNo lno = file_->size() - 1;
		istringstream iss(szText);
		string szWord;
		while(iss >> szWord)
		{
			auto& lnos = wordMap_[szWord];
			if(!lnos)
				lnos.reset(new set<LineNo>);
			lnos->insert(lno);
		}
	}
}

TextQuery::~TextQuery()
{
}

QueryResult TextQuery::query(string word)
{
	static shared_ptr<set<LineNo>> nodata(new set<LineNo>);
	auto finded = wordMap_.find(word);
	if(finded == wordMap_.end())
	{
		return QueryResult(word,file_,nodata);
	}
	else
		return QueryResult(word,file_,finded->second);
}

void TextQuery::test()
{
	for(auto& tmp : wordMap_)
	{
		cout << tmp.first;
		for(auto& lno : *tmp.second)
		{
			cout << " ";
			cout << lno;
		}
		cout << endl;
	}
}
