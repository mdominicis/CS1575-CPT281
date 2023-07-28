#ifndef EXCERCISE_H
#define EXCERCISE_H

#include <queue>
/**
 * \brief finds and averages the top 5 scores
 * \param scores a vector of at least size 5
 * \return the average (integer division) of the top 5 scores
 */
unsigned int average_top_five(const std::vector<unsigned int>& scores){
	//create a min heap
	std::priority_queue<unsigned int,std::vector<unsigned int>,std::greater<unsigned int>> qu;
	//keep exactly 5 elements in the heap
	for(unsigned int score:scores){
		if (qu.size() < 5) { qu.push(score); }
		else{
			//compare the current {score} with the top of the heap
			//if {score} is less than the root, since the heap is min heap, then it means that {score} is less than all the 5 scores in the heap
			//so, we can discard {score}
			//if {score} is greater than the root, then we need to remove the root, and add {score}
			if(score>qu.top()){
				qu.pop();
				qu.push(score);
			}
		}
	}
	//now, the heap stores the top 5 scores
	//average the 5 scores in the heap
	unsigned int sum = 0;
	while (!qu.empty()){
		sum += qu.top();
		qu.pop();
	}
	return sum / 5;
}

#endif