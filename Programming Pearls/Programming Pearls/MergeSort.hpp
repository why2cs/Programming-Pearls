template<typename T>
class MergeSort {
public:
	MergeSort(T *ptr, int num, int random,T *abc) {
		switch (random)
		{
		case 1:
		{//
			if (num > 1) {
				auto result = new T[num];

				MergeSort(ptr, num / 2, random,abc);
				MergeSort(ptr + num / 2, num - num / 2, random,abc);
				int resultIndex = 0;
				T *ptrL = ptr, *ptrR = ptr + num / 2;
				for (; (ptrL != ptr + num / 2) && (ptrR != ptr + num); ++resultIndex) {
					if (*ptrL > *ptrR)
						*(result + resultIndex) = *(ptrR++);
					else
						*(result + resultIndex) = *(ptrL++);
				}
				while ((ptrL == ptr + num / 2) && (ptrR != ptr + num))
					*(result + resultIndex++) = *(ptrR++);
				while ((ptrR == ptr + num) && (ptrL != ptr + num / 2))
					*(result + resultIndex++) = *(ptrL++);

				for (int i = 0; i != num; ++i) {
					*(ptr + i) = *(result + i);
				}

				for (int i = 0; i != 15; ++i) {
					std::cout << *(abc + i) << " ";
				}
				std::cout << std::endl;

				delete[] result;
			} else {
				for (int i = 0; i != 15; ++i) {
					std::cout << *(abc + i) << " ";
				}
				std::cout << std::endl;
				return;
			}
		}
		break;
		default:
			break;
		}
	}

	mutable int times = 0;

private:
	void swapValue(T &a, T &b) {
		T temp = a;
		a = b;
		b = temp;
	}
};