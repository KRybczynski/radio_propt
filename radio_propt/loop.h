#pragma once
#include<iostream>
#include"loopElem.h"

class Loop
{
private:
  LoopElem* first, * last;
public:
  Loop();
  ~Loop();
  void add(std::string mes);
  void display();
  void cipher(int corruption_factor);
  void corrupt_message(LoopElem* mes, int corruption_factor);
};

