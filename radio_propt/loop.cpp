#include"loop.h"


Loop::Loop()
{
	first = last = nullptr;
}

Loop::~Loop()
{
	first->prev = nullptr;
	last->next = nullptr;
	for (auto a = first->next; a != nullptr; a = a->next) {
		a->prev->next = nullptr;
		a->prev = nullptr;
	}
}

void Loop::add(std::string mes, int max_size) {
	if (first == nullptr) {
		first = make_shared<LoopElem>(mes, nullptr, nullptr, max_size);
		last = first;
		first->prev = first;
		first->next = first;
		return;
	}
	last->next = make_shared<LoopElem>(mes, last, first, max_size);
	last = last->next;
	first->prev = last;
}

void Loop::display()
{
	std::cout << *first << std::endl;
	for (auto i = first->next; i != first; i = i->next) {
		std::cout << *i<<std::endl;
	}
}

void Loop::test()
{
	auto temp = first;
	for (int i = 0; i < 9; i++) {
		std::cout << i << ". " << *temp << std::endl;
		temp = temp->next;
	}
}


void Loop::cipher(int corruption_factor) {
	if (first == nullptr)
		return;
	scanForNearest();
	auto a = first;
	do {
		if (a->message.empty()) {
			if (a->n_next < a->n_prev) {
				corrupt_message(a, a->nearest_next, a->nearest_prev, corruption_factor);
			}
			else {
				corrupt_message(a, a->nearest_prev, a->nearest_next, corruption_factor);
			}
		}

		a = a->next;
	} while (a != first);
}


void Loop::getNearest(std::shared_ptr<LoopElem>& element) {
	int n_next = 1, n_prev = 1;
	auto near_next = element->next;
	for (; near_next != element; near_next = near_next->next) {
		if (!near_next->message.empty())
			break;
		n_next++;
	}

	auto near_prev = element->prev;
	for (; near_prev != element; near_prev = near_prev->prev) {
		if (!near_prev->message.empty())
			break;
		n_prev++;
	}
	element->nearest_next = near_next;
	element->nearest_prev = near_prev;
	element->n_next = n_next;
	element->n_prev = n_prev;
}

void Loop::addMessages(std::vector<std::string> message)
{
	auto longest = std::max_element(message.begin(), message.end(),
		[](const auto& a, const auto& b) {
			return a.size() < b.size();
		});
	
	//std::cout << "bruh " << (*longest).size() << std::endl;
	for (auto a : message) {
		add(a, (*longest).size());
	}
}

void Loop::scanForNearest() {
	if (first == nullptr)
		return;
	auto a = first;
	do {
		if (a->message.empty())
			getNearest(a);
		a = a->next;
	} while (a != first);
}

void Loop::corrupt_message(std::shared_ptr<LoopElem>& element, const std::shared_ptr<LoopElem>& closer, const std::shared_ptr<LoopElem>& furhter, int corruption_factor)
{
	std::cout << element->message.size() << " " << furhter->message.size() << std::endl;
	std::copy_if(furhter->message.begin(), furhter->message.end(), std::back_inserter(element->message), [](char x) {return x != ' ' && x != '\a'; });
	for (auto& a : element->message) {
		if (a == '\n')
			break;
		if (a == ' ')
			continue;
		a += rand() % (corruption_factor * 2);
	}
	int shift = 3 + rand() % corruption_factor;
	std::copy_if(closer->message.begin(), closer->message.end(), element->message.begin() + shift, [](char x) {return x != ' ' && x != '\a'; });
	for (auto i = 0; i < closer->message.size(); i += 1 + rand() % corruption_factor) {
		int curr = i + shift;
		if (element->message[curr] == '\0')
			break;
		if (element->message[curr] == ' ')
			continue;
		element->message[curr] += rand() % corruption_factor;
	}
	
}
