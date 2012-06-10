#include <iostream>
#include "SingleLinkList.h"

int main()
{
	SingleLinkList<int> mySLL;
	mySLL.Pushfront(1);
	mySLL.Pushfront(2);
	mySLL.Pushfront(3);
	mySLL.Pushback(4);
	mySLL.Pushback(5);
	mySLL.Pushback(6);

	return 0;
}