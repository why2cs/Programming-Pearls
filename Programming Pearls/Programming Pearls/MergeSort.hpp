/*
1. �鲢����Ļ���˼����Ƿ��Ρ�

2. �鲢���򣬷���1����
	�� ��Ԫ�ظ�������1�����γ������Ѿ�����������С�
	�� �ж�ǰ������β��ֵ�ͺ�������ͷ��ֵ��С����βС���ף�������
	�� ����һ����ʱ�ռ�������������С�
	�� ������������ͷ����С���Ǹ�Ԫ�ط��������������У�������Ӧ��������
	�� �������������滻ԭ���С�
	�� �ͷ���ʱ�ռ䡣

3. �鲢���򣬷���2���裨�����˶��������ͷŶѿռ䣩
	�� ����һ����ʱ�ռ䣬���ڴ��ǰ������С�
	�� ����������������ռ��ַ������
		�� ��Ԫ�ظ�������1�����γ������Ѿ�����������С�
		�� �ж�ǰ������β��ֵ�ͺ�������ͷ��ֵ��С����βС���ף�������
		�� ��ǰ�����п�������ʱ�ռ��С�
		�� ����ʱ���кͺ�������ͷ����С���Ǹ�Ԫ�ط���ԭ�����У��������Ե�������
	�� �ͷ���ʱ�ռ䡣
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
		//double loopTimes = log(trailer - first) / log(2);	//�������еı�����������Ҫ����ȡ��
		//for (int i = 0; i < ceil(loopTimes); ++i) {			
		//	int leftSize = static_cast<int>(pow(2, i));		//���α��������У����бȽϵ�������еĳ���
		//	auto left = new T[leftSize];

		for (int leftSize = 1; leftSize < trailer - first; leftSize *= 2) {											//�������еı���ѭ��
			auto left = new T[leftSize];

			for (auto subfirst = first, subright = subfirst + leftSize, subtrailer = subfirst + 2 * leftSize;
				subright < trailer;
				subfirst = subtrailer, subright = subfirst + leftSize, subtrailer = subfirst + 2 * leftSize) {		//���α��������У�ѭ���Ƚϲ���
				if (subtrailer > trailer)																			//�����Ҳ����г��Ƚ϶̵����
					subtrailer = trailer;
				for (int i = 0; i < leftSize; ++i) {																//����������е���ʱ�ռ�
					left[i] = subfirst[i];
				}
				for (int f = 0, l = 0, r = 0; l < leftSize || r < subtrailer - subright; ) {						//�Ƚϲ���
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