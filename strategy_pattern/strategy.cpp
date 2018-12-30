#include"strategy.h"

#include<iostream>
using namespace std;

Context::Context() {
  strategy_ = StrategyA::Instance();
}


void Context::SetStrategy(Strategy* strategy) {
  strategy_ = strategy;
}


void Context::Algorithm() {
  strategy_->Algorithm();
}


Strategy::~Strategy() {}


StrategyA* StrategyA::strategy_a_ = NULL;

StrategyA* StrategyA::Instance() {
  if (NULL == strategy_a_) {
    strategy_a_ = new StrategyA;
  }
  return strategy_a_;
}


StrategyA::StrategyA() {}


void StrategyA::Algorithm() {
  cout << "running algorithm of StrategyA...\n";
}


StrategyB* StrategyB::strategy_b_ = NULL;

StrategyB* StrategyB::Instance() {
  if (NULL == strategy_b_) {
    strategy_b_ = new StrategyB;
  }
  return strategy_b_;
}


StrategyB::StrategyB() {}


void StrategyB::Algorithm() {
  cout << "running algorithm of StrategyB...\n";
}
