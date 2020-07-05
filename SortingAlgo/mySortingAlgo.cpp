#include "mySortingAlgo.h"
#include <iostream>

vector<int> mySortingAlgo::selectionSort() {
	vector<int> v{ this->input_array };

	if (v.size() <= 1)
		return v;
	int fp = 0;
	int sp = 0;

	for (int fp = 0; fp < v.size(); ++fp) {
		int minIndex = fp;
		for (int sp = fp; sp < v.size(); ++sp) {
			if (v[minIndex] > v[sp])
				minIndex = sp;
		}
		//swap(v, fp, minIndex);
		swap(&v[fp], &v[minIndex]);
	}


	return v;
}

vector<int> mySortingAlgo::bubbleSort()
{
	vector<int>v{ this->input_array };
	if (v.size() <= 1)
		return v;

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size() - i - 1; ++j) {
			if (v[j] > v[j + 1])
				swap(&v[j], &v[j + 1]);
		}
	}
	return v;
}

vector<int> mySortingAlgo::mergeSort()
{
	vector<int>v{ this->input_array };
	if (v.size() <= 1)
		return v;
	mySortingAlgo::mergeSort(v, 0, v.size() - 1);
	return v;
}

vector<int> mySortingAlgo::quickSort()
{
	vector<int>v{ this->input_array };
	if (v.size() <= 1)
		return v;

	quickSort(v, 0, v.size() - 1);
	return v;
}

void mySortingAlgo::mergeSort(vector<int>& v, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		//cout << "merging" << left << " " << mid << " " << mid << endl;
		mySortingAlgo::mergeSort(v, left, mid);
		mySortingAlgo::mergeSort(v, mid + 1, right);
		mySortingAlgo::merge(v, left, mid, right);
	}
	return;
}

void mySortingAlgo::merge(vector<int>& v, int left, int mid, int right)
{
	int fp = left;
	int sp = mid + 1;
	int index = 0;
	vector<int> temp(right - left + 1);

	while (fp <= mid and sp <= right) {
		if (v[fp] >= v[sp]) {
			temp[index] = v[sp];
			++sp;
			++index;
		}
		else {
			temp[index] = v[fp];
			++fp;
			++index;
		}
	}

	if (fp <= mid and sp == right+1) {
		while (fp <= mid) {
			temp[index] = v[fp];
			++fp;
			++index;
		}

		for (int i = left; i <= right; ++i)
			v[i] = temp[i - left];
	}
	else if (fp == mid+1 and sp <= right) {
		for (int i = left; i < sp; ++i) {
			v[i] = temp[i - left];
		}
	}
	else {
		// for debugging
		cout << "WRONGGGGGGGGG!" << endl;
		cout << left << " " << mid << " " << right << endl;
		cout << fp << " " << sp << endl;
	}


}

void mySortingAlgo::quickSort(vector<int>& input, int left, int right)
{
	if (left < right) {
		int pivot = this->partition(input, left, right);
		quickSort(input, left, pivot - 1);
		quickSort(input, pivot + 1, right);
	}
	
}

int mySortingAlgo::partition(vector<int>& input, int left, int right)
{
	int pivot = input[right];
	//index points to the last element that strictly smaller than pivot
	int index = left-1;
	for (int i = left; i < right; ++i) {
		if (input[i] >= pivot)
			continue;
		else {
			++index;
			swap(input, i, index);
		}
	}
	swap(input, index + 1, right);
	return index+1;
}


