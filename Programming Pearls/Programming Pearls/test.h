#ifndef test_h__
#define test_h__

#include <iostream>
class Test {
public:
	Test(int arg, int *sum) {
		if (arg > 1) {
			Test(arg - 1, sum);
			*sum = *sum + arg;
		} else
			*sum = 1;

		std::cout << *sum << " ";
	}
};

extern int sum(int);
#endif // test_h__