/*
 *
 */
#include <iostream>
#include "TextQuery.h"

using namespace std;

int main(int argc,char** argv)
{
	if(argc < 3)
	{
		cout << "usage:" << argv[0] << argv[1] << argv[2] << endl;
		return 1;
	}

	TextQuery obj(argv[1],argv[2]);
	obj.query();
	return 0;
}
