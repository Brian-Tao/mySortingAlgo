#include "myHeap.h"
#include <algorithm>
#include "myDisplay.h"
#include <iostream>

int myHeap::top()
{
	return num_of_element > 0 ? heap[0] : -1;
}

void myHeap::insert(int value)
{
	if (num_of_element < size) {
		heap[num_of_element] = value;
		++num_of_element;

		//heapify
		int cur_index = num_of_element - 1;
		int parent_index = cur_index % 2 == 1 ? (cur_index - 1) / 2 : (cur_index - 2) / 2;
		while (cur_index > 0 and heap[cur_index] < heap[parent_index]) {
			swap(&heap[cur_index], &heap[parent_index]);
			cur_index = parent_index;
			parent_index = cur_index % 2 == 1 ? (cur_index - 1) / 2 : (cur_index - 2) / 2;
		}
	}
}

int myHeap::remove()
{
	if (num_of_element == 1) {
		--num_of_element;
		return heap[0];
	}
	else if (num_of_element > 1){
		int return_value = heap[0];
		swap(&heap[0], &heap[num_of_element - 1]);
		--num_of_element;
		
		//heapify
		int cur_index = 0;
		int child;
		if (2 * cur_index + 2 < num_of_element) {
			child = heap[2 * cur_index + 2] > heap[2 * cur_index + 1] ? 2 * cur_index + 1 : 2 * cur_index + 2;
		}
		else if (2 * cur_index + 1 < num_of_element) {
			child = 2 * cur_index + 1;
		}
		else {
			//this->display_heap();
			return return_value;
		}

		while (child < num_of_element and heap[cur_index] > heap[child]) {
			swap(&heap[cur_index], &heap[child]);
			cur_index = child;
			if (2 * cur_index + 2 < num_of_element) {
				child = heap[2 * cur_index + 2] > heap[2 * cur_index + 1] ? 2 * cur_index + 1 : 2 * cur_index + 2;
			}
			else if (2 * cur_index + 1 < num_of_element) {
				child = 2 * cur_index + 1;
			}
			else {
				//this->display_heap();
				return return_value;
			}
		}
		//this->display_heap();
		return return_value;
	}

	return -1;
}

bool myHeap::empty()
{
	if (num_of_element > 0)
		return false;
	else
		return true;
}

void myHeap::display_heap()
{
	display(this->heap);
}
