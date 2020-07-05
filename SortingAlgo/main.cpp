#include "mySortingAlgo.h"
#include "myDisplay.h"
#include "myHeap.h"
#include <vector>
#include <random>

#define input_size 1000

using namespace std;
vector<int> input_generator(int, int);
vector<int> test_heap(vector<int>&, myHeap&);


int main() {
	vector<int> input = input_generator(input_size, 10);
	mySortingAlgo v = mySortingAlgo(input);
	myHeap h = myHeap(input_size);
	/*
	auto sorted5 = test_heap(input, h);
	display(sorted5);
	
	auto sorted = v.selectionSort();
	display(sorted);

	auto sorted2 = v.bubbleSort();
	display(sorted2);
	
	auto sorted3 = v.mergeSort();
	display(sorted3);
	
	auto sorted4 = v.quickSort();
	display(sorted4);
	*/

	return 0;
}

vector<int> input_generator(int length, int range) {
	random_device dev;
	mt19937 engine(dev());
	uniform_int_distribution<int> distribution(0, range);
	vector<int> returner;
	for (int i = 0; i < length; ++i) {
		returner.push_back(distribution(engine));
	}
	return returner;
}

vector<int> test_heap(vector<int>& input, myHeap& heap) {
	vector<int> returner;
	for (int val : input) {
		heap.insert(val);
	}
	
	while (!heap.empty())
		returner.push_back(heap.remove());

	return returner;
}