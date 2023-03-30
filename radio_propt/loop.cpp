#include"loop.h"


Loop::Loop()
{
  first = last = nullptr;
}

Loop::~Loop()
{
}

void Loop::add(std::string mes) {
  if (first == nullptr) {
    first = new LoopElem(mes, nullptr, nullptr);
    last = first;
    first->prev = first;
    first->next = first;
    return;
  }
  last->next = new LoopElem(mes, last, first);
  last = last->next;
  first->prev = last;
}

void Loop::display()
{
  std::cout << first->mes << std::endl;
  for (LoopElem* i = first->next; i != first; i = i->next) {
    std::cout << i->mes << std::endl;
  }
}

void Loop::cipher(int corruption_factor){
  if (first->mes == "")
    corrupt_message(first, corruption_factor);
  for (LoopElem* i = first->next; i != first; i = i->next)
    if (i->mes == "")
      corrupt_message(i, corruption_factor);
  
}

void Loop::corrupt_message(LoopElem* element, int corruption_factor)
{
  //find nearest message next
  int n_next = 1, n_prev = 1;
  std::string next_mes = "", prev_mes = "";
  for (LoopElem* i = element->next; i != element; i = i->next) {
    n_next++;
    if (i->mes == "")
      continue;
    else {
      next_mes = i->mes;
      break;
    }
  }
  for (LoopElem* i = element->prev; i != element; i = i->prev) {
    n_prev++;
    if (i->mes == "")
      continue;
    else {
      prev_mes = i->mes;
      break;
    }
  }

  if (n_next > n_prev)
    element->mes = next_mes;
  else
    element->mes = prev_mes;


  for (int i = 0; i < element->mes.length(); i++)
    element->mes[i] = "a";//next_mes[i];// +rand() % n_next;

  for (int i = 0; i < element->mes.length(); i++)
    element->mes[i] = prev_mes[i];// +rand() % n_prev;
}



