#pragma once
#include<iostream>
#include<memory>
#include"loopElem.h"


class Loop
{
private:
  std::shared_ptr<LoopElem> first, last;
public:
  Loop();
  ~Loop();
  void add(std::string mes, int max_size);
  void display();
  void test();
  void cipher(int corruption_factor);
  void corrupt_message(std::shared_ptr<LoopElem>& element, const std::shared_ptr<LoopElem>& closer, const std::shared_ptr<LoopElem>& furhter, int corruption_factor);
  void scanForNearest();
  void getNearest(std::shared_ptr<LoopElem> &element);
  void addMessages(std::vector<std::string> message);
};

