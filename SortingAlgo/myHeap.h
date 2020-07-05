#ifndef MY_HEAP
#define MY_HEAP
#include <vector>

using namespace std;
class myHeap
{
	vector<int> heap;
	int size;
	int num_of_element;

public:
	myHeap(int size = 10):size(size) {
		heap = vector<int>(size, 0);
		num_of_element = 0;
	};
	~myHeap() {};

	int top();
	void insert(int value);
	int remove();
	bool empty();
	void display_heap();

private:
	void swap(vector<int>& v, int i, int j) {
		if (i == j)
			return;
		else {
			int temp = v[j];
			v[j] = v[i];
			v[i] = temp;
		}
		return;
	}

	void swap(int* i, int* j) {
		int temp = *i;
		*i = *j;
		*j = temp;
	}
};

#endif