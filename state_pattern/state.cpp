#include"state.h"

#include<iostream>
using namespace std;

Context::Context() {
  state_ = ConcreteStateA::Instance();
}

Context::~Context() {}

void Context::ChangeState(State* state) {
  state_ = state;
}

void Context::request() {
  state_->Handle(this);
}


State::~State() {}


ConcreteStateA* ConcreteStateA::state_a_ = NULL;

ConcreteStateA::ConcreteStateA() {}

State* ConcreteStateA::Instance() {
  if (state_a_ == NULL) {
    state_a_ = new ConcreteStateA;
  }
  return state_a_;
}

void ConcreteStateA::Handle(Context* context) {
  cout << "doing something in state A...\n"
          "done.change state to B\n";
  context->ChangeState(ConcreteStateB::Instance());
}


ConcreteStateB* ConcreteStateB::state_b_ = NULL;

ConcreteStateB::ConcreteStateB() {}

State* ConcreteStateB::Instance() {
  if (state_b_ == NULL) {
    state_b_ = new ConcreteStateB;
  }
  return state_b_;
}

void ConcreteStateB::Handle(Context* context) {
  cout << "doing something in state B...\n"
          "done.change state to A\n";
  context->ChangeState(ConcreteStateA::Instance());
}

