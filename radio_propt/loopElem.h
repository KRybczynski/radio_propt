#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include<memory>

struct LoopElem
{
public:
	
	std::shared_ptr<LoopElem> prev, next, nearest_prev, nearest_next;
	std::vector<char> message;
	int n_next, n_prev;
	LoopElem();
	~LoopElem();
	LoopElem(std::string message, std::shared_ptr<LoopElem> prev, std::shared_ptr<LoopElem> next, int max_size);
	friend std::ostream& operator<<(std::ostream& os, const LoopElem& dt);
	
};
