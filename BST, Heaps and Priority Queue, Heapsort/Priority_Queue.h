#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <exception>
#include <algorithm>
template<class T>
class Priority_Queue
{
public:
	//constructors
	Priority_Queue();

	//member functions
	size_t size() const;
	bool empty() const;
	const T& top() const;
	void push(const T&);
	void pop();
private:
	//data field
	std::vector<T> vec;
};

template <class T>
void Priority_Queue<T>::pop(){
	if (empty()) { throw std::exception("Attempt to access item in empty priority queue."); }
	vec.front() = vec.back();
	vec.pop_back();
	size_t p = 0, left = 2 * p + 1, right = 2 * p + 2, m = p;
	while(true){
		if (left<size() && vec.at(left)>vec.at(m)) { m = left; }
		if (right<size() && vec.at(right)>vec.at(m)) { m = right; }
		if (m == p) { break; }
		std::swap(vec.at(m), vec.at(p));
		p = m;
		left = 2 * p + 1;
		right = 2 * p + 2;
	}
}


template <class T>
void Priority_Queue<T>::push(const T& item){
	vec.push_back(item);
	int c = vec.size() - 1, p = floor((c - 1) / 2);
	while(c>=0&&vec.at(c)>vec.at(p)){
		std::swap(vec.at(c), vec.at(p));
		c = p;
		p = floor((c - 1) / 2);
	}
}


template <class T>
const T& Priority_Queue<T>::top() const{
	if (empty()) { throw std::exception("Attempt to access item in empty priority queue."); }
	return vec.at(0);
}


template <class T>
bool Priority_Queue<T>::empty() const { return vec.empty(); }


template <class T>
size_t Priority_Queue<T>::size() const { return vec.size(); }


template <class T>
Priority_Queue<T>::Priority_Queue(){  }


#endif