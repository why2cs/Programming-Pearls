template<typename T>
class SelectionSort {
public:
	SelectionSort(T *first, int num) {
		for (int i = 0; i < num - 1; ++i) {		//注意此处不要越界
			int smallestIndex = i;
			for (int j = i + 1; j < num; ++j) {
				if (first[j] < first[smallestIndex])
					smallestIndex = j;
			}
			if (i != smallestIndex)
				swapValue(first[i], first[smallestIndex]);
		}
	}

private:
	void swapValue(T &a, T &b) {
		T temp = a;
		a = b;
		b = temp;
	}
};