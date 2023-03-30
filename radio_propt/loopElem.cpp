#pragma once
#include<iostream>
#include"loopElem.h"


LoopElem::LoopElem(std::string mes, LoopElem* prev, LoopElem* next) {
  this->mes = mes;
  this->prev = prev;
  this->next = next;
}

LoopElem::LoopElem()
{
  prev = next = nullptr;
}

LoopElem::~LoopElem()
{
}