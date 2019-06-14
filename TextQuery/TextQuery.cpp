#include <iostream>
#include <fstream>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(const char* path,const char* word)
	:path_(path),
	word_(word),
	count_(0);
{
}

TextQuery::~TextQuery()
{
}

void TextQuery::query()
{
	if(path_ == nullptr || word_ == nullptr)
		cout << "please input the path and word!" << endl;

	ifstream inf(path_);
	if(!inf)
	{
		cout << "open fail:" + string(path_) << endl;
		return ;
	}

	//query
	string line;
	int lineNO = 1;
	while(getline(inf,line))
	{
		auto pos = line.find(word_);
		if(pos != string::npos)
		{
			mapLine_[lineNO] = line;
			++count_;
		}

		++lineNO;
	}

	//print
	cout << "element occurs " << count_ << " times" << endl;
	for(auto& content : mapLine_)
	{
		cout << "(line " << content.first << ") " << content.second << endl;
	}

}
