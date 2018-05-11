/*
1. 归并排序的基础思想就是分治。

2. 归并排序，方法1步骤
	① 若元素个数大于1，分治成两个已经排序的子序列。
	② 判断前子序列尾部值和后子序列头部值大小。若尾小于首，结束。
	③ 申请一段临时空间用作已排序队列。
	④ 将两个子序列头部较小的那个元素放入已排序序列中，递增相应迭代器。
	⑤ 用已排序序列替换原序列。
	⑥ 释放临时空间。

3. 归并排序，方法2步骤（避免了多次请求和释放堆空间）
	① 申请一段临时空间，用于存放前半段序列。
	② 调用排序函数，传入空间地址参数。
		① 若元素个数大于1，分治成两个已经排序的子序列。
		② 判断前子序列尾部值和后子序列头部值大小。若尾小于首，结束。
		③ 将前子序列拷贝到临时空间中。
		④ 将临时序列和后子序列头部较小的那个元素放入原序列中，递增各自迭代器。
	③ 释放临时空间。
*/

template<typename T>
class MergeSort {
public:
	MergeSort(T *ptr, int num) {
		if (num > 1) {
			MergeSort(ptr, num / 2);
			MergeSort(ptr + num / 2, num - num / 2);

			int resultIndex = 0;
			T *ptrL = ptr, *ptrR = ptr + num / 2;
			auto result = new T[num];
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

			for (int i = 0; i != num; ++i)
				*(ptr + i) = *(result + i);

			delete[] result;
		}
	}

	MergeSort(T *left, T *trailer) {
		if (left < trailer - 1) {
			T *mid = left + (trailer - left) / 2;
			const T *begin = left;
			MergeSort(left, mid);
			MergeSort(mid, trailer);

			//combine the list
			if (*(mid - 1) > *mid) {
				T *inOrder = new T[trailer - left];
				auto left2 = mid;
				while (left != mid && left2 != trailer)
					*(inOrder++) = (*left > *left2) ? *(left2++) : *(left++);
				while (left == mid&&left2 != trailer)
					*(inOrder++) = *(left2++);
				while (left != mid&&left2 == trailer)
					*(inOrder++) = *(left++);

				while (trailer != begin)
					*(--trailer) = *(--inOrder);
				delete[]inOrder;
			}
		}
	}

	MergeSort(T* first, T *trailer, int) {
		T* buffer = new T[(trailer - first + 1) / 2];
		MergeSortSub(first, trailer, buffer);
		delete[] buffer;
	}
	void MergeSortSub(T *first, T *trailer, T *  const leftHalfBuffer) {
		if (trailer - first > 1) {
			T *mid = first + (trailer - first) / 2;
			MergeSortSub(first, mid, leftHalfBuffer);
			MergeSortSub(mid, trailer, leftHalfBuffer);

			if (*(mid - 1) > *mid) {
				int leftSize = mid - first;
				int rightSize = trailer - mid;
				for (int i = 0; mid != first + i; leftHalfBuffer[i] = first[i], ++i);
				for (int originIndex = 0, leftIndex = 0, rightIndex = 0; leftIndex < leftSize || rightIndex < rightSize;) {
					if (leftIndex < leftSize && (rightIndex == rightSize || leftHalfBuffer[leftIndex] <= mid[rightIndex]))
						first[originIndex++] = leftHalfBuffer[leftIndex++];
					if (rightIndex < rightSize && (leftIndex == leftSize || leftHalfBuffer[leftIndex] > mid[rightIndex]))
						first[originIndex++] = mid[rightIndex++];
				}
			}
		}
	}

	MergeSort(T *first, T *trailer, int, int) {
		//double loopTimes = log(trailer - first) / log(2);	//整个序列的遍历次数，需要向上取整
		//for (int i = 0; i < ceil(loopTimes); ++i) {			
		//	int leftSize = static_cast<int>(pow(2, i));		//单次遍历过程中，进行比较的左侧序列的长度
		//	auto left = new T[leftSize];

		for (int leftSize = 1; leftSize < trailer - first; leftSize *= 2) {											//整个序列的遍历循环
			auto left = new T[leftSize];

			for (auto subfirst = first, subright = subfirst + leftSize, subtrailer = subfirst + 2 * leftSize;
				subright < trailer;
				subfirst = subtrailer, subright = subfirst + leftSize, subtrailer = subfirst + 2 * leftSize) {		//单次遍历过程中，循坏比较操作
				if (subtrailer > trailer)																			//处理右侧序列长度较短的情况
					subtrailer = trailer;
				for (int i = 0; i < leftSize; ++i) {																//拷贝左侧序列到临时空间
					left[i] = subfirst[i];
				}
				for (int f = 0, l = 0, r = 0; l < leftSize || r < subtrailer - subright; ) {						//比较操作
					if ((l < subright - subfirst) && ((r == subtrailer - subright) || left[l] <= subright[r]))
						subfirst[f++] = left[l++];
					if ((r < subtrailer - subright) && ((l == subright - subfirst) || left[l] > subright[r]))
						subfirst[f++] = subright[r++];
				}
			}

			delete[]left;
		}
	}

};