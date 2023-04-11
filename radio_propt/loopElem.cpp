#include"loopElem.h"



LoopElem::LoopElem(std::string message, std::shared_ptr<LoopElem> prev, std::shared_ptr<LoopElem> next, int max_size) {
	//this->mes = mes;
	message.reserve(max_size);
	if(!message.empty())
		std::copy(message.begin(), message.end(), std::back_inserter(this->message));
	this->prev = prev;
	this->next = next;
}

LoopElem::LoopElem() {
}

LoopElem::~LoopElem()
{
	//std::cout << "loopElem_done" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const LoopElem& dt)
{
	for (auto a : dt.message) {
		os << a;
	}
	return os;
}
