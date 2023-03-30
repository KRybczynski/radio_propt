#pragma once
struct LoopElem
{
public:
  LoopElem* prev, * next;
  std::string mes;
  LoopElem();
  ~LoopElem();
  LoopElem(std::string mes, LoopElem* prev, LoopElem* next);
};
