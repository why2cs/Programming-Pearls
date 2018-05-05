#include <iostream>
#include "MergeSort.hpp"
#include "BubbleSort.hpp"
int main()
{
	//test Data
	constexpr int num = 15;
	int a[num] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	int result[num] = { 2,3,4,5,15,19,26,27,36,38,44,46,47,48,50};
	int times = 0;


	//MergeSort<int> foo(a,num);
	BubbleSort<int> foo(a, num,4);
	times = foo.times;


	//test Output
	bool equal = true;
	for (int i = 0; i != num; ++i) {
		std::cout << a[i] << " ";
		if (a[i] != result[i])
			equal = false;
	}
	std::cout << std::endl << std::boolalpha << equal << std::endl;
	std::cout << times << std::endl;
	return 0;
}