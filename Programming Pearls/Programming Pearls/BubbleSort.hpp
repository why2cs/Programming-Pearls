/*
1. 冒泡排序主要包含两层循环
	外层：减而治之。剔除已经排序的元素，减小规模。
	内层：遍历比较。将最大的移动至序列最右侧。

2. 外层的几种策略，依次优化：
	① 不减小规模，有多少元素就进行多少轮内层循环。
	② 设置有序标志位，当内层产生交换操作时将标志位置假。循环判断标志位直至为真结束。
	③ 检查序列是否为空，不为空就进行内层循环。（前提：内层循环需能减小序列规模）

3. 内层的几种策略，依次优化：
	① 不减小规模，多次对首尾已经排序的元素进行无用排序。
	② 记录序列已经排序的尾位置，从一个方向上减小规模。
	③ 记录序列已经排序的首尾位置，从两个方向上减小规模。
*/


template<typename T>
class BubbleSort {
public:
	BubbleSort(T* ptr, int num, int random) {
		switch (random) {
		
		//外层循环① 内层循环②
		case 1:
		{
			for (int n = 0; n != num; ++n) {
				for (T *movePtr = ptr, *last = ptr + num - 1 - n; movePtr != last; ++movePtr) {
					if (*movePtr > *(movePtr + 1))
						swapValue(*movePtr, *(movePtr + 1));
					++times;
				}
			}
		}
		break;

		//外层循环② 内层循环②
		case 2:
		{
			bool hasSwap = true;
			int hasSorted = 0;
			while (hasSwap) {
				hasSwap = false;
				for (T *movePtr = ptr, *last = ptr + num - 1 - hasSorted; movePtr != last; ++movePtr) {
					if (*movePtr > *(movePtr + 1)) {
						swapValue(*movePtr, *(movePtr + 1));
						hasSwap = true;
					}
					++times;
				}
				++hasSorted;
			}
		}
		break;

		//外层循环③ 内层循环②
		case 3:
		{
			T* last = ptr + num - 1;
			while (ptr < last) {
				T* tempPtr = nullptr;
				for (T *movePtr = ptr; movePtr != last; ++movePtr) {
					if (*movePtr > *(movePtr + 1)) {
						swapValue(*movePtr, *(movePtr + 1));
						tempPtr = movePtr;
					}
					++times;
				}
				last = tempPtr;
			}
		}
		break;

		//外层循环③ 内层循环③
		case 4:
		{
			T* first = ptr;
			T* trailer = ptr + num;
			while (first < trailer) {
				T* tempPtr = nullptr;
				T* tempFirst = first;
				while (++tempFirst != trailer) {
					if (*(tempFirst - 1) > *tempFirst) {
						swapValue(*(tempFirst - 1), *tempFirst);
						tempPtr = tempFirst;
					}
					++times;
				}
				trailer = tempPtr;
				T* tempTrailer = trailer;
				while (--tempTrailer != first) {
					if (*(tempTrailer - 1) > *tempTrailer) {
						swapValue(*(tempTrailer - 1), *tempTrailer);
						tempPtr = tempTrailer;
					}
					++times;
				}
				first = tempPtr;
			}
		}
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
