#include <iostream>
#include <fstream>
#include <string.h>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(const char* path,const char* word)
	:path_(path),
	word_(word),
	count_(0)
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
		string::size_type pos = 0;
		bool finded = false;
		do
		{
			pos = line.find(word_,pos);
			if(pos != string::npos)
			{
				if(!finded)
				{
					finded = true;
					mapLine_[lineNO] = line;
				}
				++count_;
				pos += strlen(word_);
			}
		}while(pos != string::npos && pos <= line.size());

		++lineNO;
	}

	//print
	cout << "element occurs " << count_ << " times" << endl;
	for(auto& content : mapLine_)
	{
		cout << "(line " << content.first << ") " << content.second << endl;
	}

}
