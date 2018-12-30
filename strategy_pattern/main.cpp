#include"strategy.h"

#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
  Context context;
  context.SetStrategy(StrategyA::Instance());
  context.Algorithm();
  context.SetStrategy(StrategyB::Instance());
  context.Algorithm();
  return 0;
}
