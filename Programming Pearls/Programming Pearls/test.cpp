#include "test.h"

int sum(int arg) {
	if (arg > 1)
		return arg + sum(arg - 1);
	else
		return arg;
}