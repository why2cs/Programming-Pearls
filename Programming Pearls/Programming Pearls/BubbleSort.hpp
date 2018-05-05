/*
1. ð��������Ҫ��������ѭ��
	��㣺������֮���޳��Ѿ������Ԫ�أ���С��ģ��
	�ڲ㣺�����Ƚϡ��������ƶ����������Ҳࡣ

2. ���ļ��ֲ��ԣ������Ż���
	�� ����С��ģ���ж���Ԫ�ؾͽ��ж������ڲ�ѭ����
	�� ���������־λ�����ڲ������������ʱ����־λ�ü١�ѭ���жϱ�־λֱ��Ϊ�������
	�� ��������Ƿ�Ϊ�գ���Ϊ�վͽ����ڲ�ѭ������ǰ�᣺�ڲ�ѭ�����ܼ�С���й�ģ��

3. �ڲ�ļ��ֲ��ԣ������Ż���
	�� ����С��ģ����ζ���β�Ѿ������Ԫ�ؽ�����������
	�� ��¼�����Ѿ������βλ�ã���һ�������ϼ�С��ģ��
	�� ��¼�����Ѿ��������βλ�ã������������ϼ�С��ģ��
*/


template<typename T>
class BubbleSort {
public:
	BubbleSort(T* ptr, int num, int random) {
		switch (random) {
		
		//���ѭ���� �ڲ�ѭ����
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

		//���ѭ���� �ڲ�ѭ����
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

		//���ѭ���� �ڲ�ѭ����
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

		//���ѭ���� �ڲ�ѭ����
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
