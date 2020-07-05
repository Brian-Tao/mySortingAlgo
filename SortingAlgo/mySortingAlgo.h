#pragma once
#include <vector>
using namespace std;

class mySortingAlgo
{	
public:
	const vector<int> input_array;
	mySortingAlgo(vector<int>& v) :input_array(v) {};
	~mySortingAlgo() {};

	vector<int> selectionSort();

	vector<int> bubbleSort();
	vector<int> mergeSort();
	vector<int> quickSort();

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

	void mergeSort(vector<int>& v, int left, int right);
	void merge(vector<int>& v, int left, int mid, int right);

	void quickSort(vector<int>& input, int left, int right);
	int partition(vector<int>& input, int left, int right);
};

