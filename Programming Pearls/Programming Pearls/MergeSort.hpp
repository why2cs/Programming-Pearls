template<typename T>
class MergeSort {
public:
	MergeSort(T *ptr, int num, int random) {
		sa = ptr;
		switch (random)
		{
		case 1:
		{//(ptrL != ptr + num / 2) && (ptrR != ptr + num)
			if (num > 1) {
				auto result = new T[num];

				MergeSort(ptr, num / 2, random);
				MergeSort(ptr + num / 2, num - num / 2, random);
				int resultIndex = 0;
				for (T *ptrL = ptr, *ptrR = ptr + num / 2; resultIndex != num; ++resultIndex) {
					if (*ptrL > *ptrR)
						*(result + resultIndex) = *(ptrR++);
					else
						*(result + resultIndex) = *(ptrL++);
				}

				for (int i = 0; i != num; ++i) {
					*(ptr + i) = *(result + i);
				}

				for (int i = 0; i != 15; ++i) {
					std::cout << *(sa + i) << " ";
				}
				std::cout << std::endl;

				delete[] result;
			} else
				return;
		}
		break;
		default:
			break;
		}
	}

	mutable int times = 0;
	T *sa;

private:
	void swapValue(T &a, T &b) {
		T temp = a;
		a = b;
		b = temp;
	}
};