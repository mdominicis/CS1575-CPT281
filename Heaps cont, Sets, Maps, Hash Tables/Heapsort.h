#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <algorithm>

class Heapsort
{
public:
	//wrapper function
	static void sort(std::vector<int>&vec){
		sort(vec, vec.size());
	}
private:
	//the sort algorithm
	static void sort(std::vector<int>& vec, size_t length){
		build_max_heap(vec,length, 0);
		for(size_t i=length-1;i>0;i--){
			std::swap(vec.at(0), vec.at(i));
			max_heapify(vec, --length, 0);
		}
	}

	//the build max heap alg
	static void build_max_heap(std::vector<int>& vec,size_t length, size_t root) {
		size_t left = 2 * root + 1, right = 2 * root + 2;
		if (left < length) { build_max_heap(vec, length, left); }
		if (right < length) { build_max_heap(vec, length, right); }
		max_heapify(vec, vec.size(), root);
	}

	//the max heapify alg
	static void max_heapify(std::vector<int>& vec, size_t length, size_t root){
		size_t left = 2 * root + 1, right = 2 * root + 2, max = root;
		if (left<length && vec.at(left)>vec.at(max)) { max = left; }
		if (right<length && vec.at(right)>vec.at(max)) { max = right; }
		if(max!=root){
			std::swap(vec.at(root), vec.at(max));
			max_heapify(vec, length, max);
		}
	}
	
};
#endif