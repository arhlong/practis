/*
 *
 */
#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

int main(int argc,char** argv)
{
	if(argc < 2)
	{
		cout << "usage:" << argv[0] << " path" << endl;
		return 1;
	}

	ifstream inf(argv[1]);
	TextQuery obj(inf);
	string word;

	do
	{
		cout << "please typed the word or q for quit" << endl;
		if(!(cin >> word) || word == string("q"))
			return 0;
		QueryResult res = obj.query(word);
		res.print(cout);
	}while(1);
	return 0;
}
